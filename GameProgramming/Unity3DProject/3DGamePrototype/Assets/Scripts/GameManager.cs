using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    [SerializeField]
    List<ItemObject> m_listItemObject;
    [SerializeField]
    ItemManager m_cItemManager;
    [SerializeField]
    List<PlayerController> m_listPlayerControllers;
    [SerializeField]
    int m_nPlayerIdx = 0;
    [SerializeField]
    Camera m_cMainCamera;

    public int PlayerIdx { get { return m_nPlayerIdx; } set { m_nPlayerIdx = value; } }
        
    public List<ItemObject> ItemObjects
    {
        get { return m_listItemObject; }
    }
    public ItemManager ItemManager
    {
        get { return m_cItemManager; }
    }
    public List<PlayerController> PlayerControllList
    {
        get { return m_listPlayerControllers; }
    }
    public PlayerController GetPlayeControllers(int idx)
    {
        return m_listPlayerControllers[idx];
    }
    //싱글톤기법: 객체는 원래 1개만 생성되로록 규칙이 정해져있어야하지만,
    //인스펙터사용등 편리함을 이유로 유니티에서 느슨한 규칙을 적용한것임.
    static GameManager m_cInstance;

    static public GameManager GetInstance()
    {
        return m_cInstance;
    }

    private void Awake()
    {
        m_cInstance = this;
    }

    [SerializeField]
    Camera m_cCarmera;

    void UpdateInputProcess()
    {

        Ray ray = m_cCarmera.ScreenPointToRay(Input.mousePosition);
        RaycastHit raycastHit = new RaycastHit();
        float fRayDist = 100;
        int nLayer = 1 << LayerMask.NameToLayer("Object");

        if (Input.GetMouseButtonDown(0))
        {
            if (Physics.Raycast(ray.origin, ray.direction, out raycastHit, fRayDist, nLayer, QueryTriggerInteraction.Collide))
            {
                Collider collider = raycastHit.collider;
                //Debug.DrawRay(ray.origin, ray.direction, Color.green);
                Debug.DrawLine(ray.origin, ray.origin + ray.direction * fRayDist, Color.green);
                Debug.Log("Ray Ficking:" + collider.gameObject.name);
                PlayerController playerController = GetPlayeControllers(PlayerIdx);

                Transform transPickup = collider.transform;

                if(playerController.GrabPoint)
                {
                    transPickup.SetParent(playerController.GrabPoint);
                    transPickup.localPosition = Vector3.zero;
                }
            }
            else
                Debug.DrawLine(ray.origin, ray.origin + ray.direction * fRayDist, Color.red);
        }
    }

    [SerializeField]
    bool m_bPopup;
    [SerializeField]
    GameObject m_objPopupLayer;
    [SerializeField]
    GUIItemInventory m_guiItemInventory;
 
    public void ShowPopupIventory()
    {
        Time.timeScale = 0;
        m_objPopupLayer.SetActive(true);
        m_guiItemInventory.gameObject.SetActive(true);
        m_bPopup = true;
    }

    public void ClosePopupIventory()
    {
        Time.timeScale = 1;
        m_objPopupLayer.SetActive(false);
        m_guiItemInventory.gameObject.SetActive(false);
        m_bPopup = false;
    }


    public enum E_GUI_STATE { NONE = -1, TITLE, GAMEOVER, THEEND, PLAY }

    [SerializeField]
    List<GameObject> m_listGUIScenes;
    [SerializeField]
    E_GUI_STATE m_eGurGUIState;

    [SerializeField]
    GUIPlayerInfo m_guiPlayerInfo;

    void ShowGUIScenes(int idx)
    {
        for(int i = 0;  i < m_listGUIScenes.Count; i++)
        {
            if(i == idx)
                m_listGUIScenes[i].SetActive(true);
            else
                m_listGUIScenes[i].SetActive(false);
        }
    }

    void SetGUIState(E_GUI_STATE state)
    {
        switch(state)
        {
            case E_GUI_STATE.TITLE:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.GAMEOVER:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.THEEND:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.PLAY:
                Time.timeScale = 1;
                break;
        }
        ShowGUIScenes((int)state);
        m_eGurGUIState = state;
    }

    void UpdateGUIState()
    {
        switch (m_eGurGUIState)
        {
            case E_GUI_STATE.TITLE:
                
                break;
            case E_GUI_STATE.GAMEOVER:

                break;
            case E_GUI_STATE.THEEND:

                break;
            case E_GUI_STATE.PLAY:
                {
                    if (Input.GetKeyDown(KeyCode.I))
                    {
                        if (m_bPopup)
                            ClosePopupIventory();
                        else
                            ShowPopupIventory();
                    }

                    PlayerController playerController = GetPlayeControllers(m_nPlayerIdx);

                    Vector3 v2DPos = m_cMainCamera.WorldToScreenPoint(playerController.transform.position);
                    m_guiPlayerInfo.transform.position = v2DPos;

                    m_guiPlayerInfo.UpdataPlayerStatus(playerController);
                }
                break;
        }
    }

    public void EventGUIState(int idx)
    {
        SetGUIState((E_GUI_STATE)idx);
    }

    public ItemIventory EventShowMeTheItems()
    {
        Controller controller = GetPlayeControllers(m_nPlayerIdx);
        Player player = controller.GetPlayer();
        ItemIventory itemIventory = player.GetComponent<ItemIventory>();
        itemIventory.TestIventory(10);
        return itemIventory;
    }

  
    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("GameManager::Start() 1");
        m_cItemManager.InitItems();
        for (int i = 0; i < m_listItemObject.Count; i++)
        {
            m_listItemObject[i].SetItem(m_cItemManager.GetItem(0));
        }
        SetGUIState(m_eGurGUIState);
        ItemIventory itemIventory = EventShowMeTheItems();
        m_guiItemInventory.SetIventory(itemIventory);
        Debug.Log("GameManager::Start() 1");
    }

    private void Update()
    {
        UpdateGUIState();
    }

    private void FixedUpdate()
    {
        UpdateInputProcess();
    }
}
