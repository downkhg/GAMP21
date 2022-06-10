using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public static class StaticFunction
{
    public static void Attack(GameObject objAttacker, Collider2D colTarget)
    {
        Debug.Log(objAttacker.name + "Attack" + colTarget.gameObject.name);
        Player attacker = objAttacker.GetComponent<Player>();
        Player target = colTarget.gameObject.GetComponent<Player>();
        SuperMode superMode = target.GetComponent<SuperMode>();

        if (target.Death() == false)
        {
            if (superMode && superMode.isUes == false)
            {
                attacker.Attack(target);
                if (target.Death())
                    attacker.StillExp(target);
                else
                    superMode.OnMode();
            }
        }
    }

    public static void ResponPlayer(GameObject objPlayer, GameObject objResponner)
    {
        objPlayer.GetComponent<Player>().Recovery();
        objPlayer.SetActive(true);
        objPlayer.transform.position = objPlayer.transform.position = objResponner.transform.position;
    }

    public static GameObject InitStaticObject(string path, Vector3 pos)
    {
        GameObject objPrefab = Resources.Load(path) as GameObject;
        GameObject objInstance = Object.Instantiate(objPrefab, pos, Quaternion.identity);
        Object.DontDestroyOnLoad(objInstance);
        return objInstance;
    }
}
    
public class GameManager : MonoBehaviour
{
    public string strVer = "Ver.0.00.00";
    public Text textVer;

    public CameraTracker cameraTracker;

    public Responner responnerPlayer;
    public Responner responnerOpossum;
    public Responner responnerEagle;

    public Dictionary<string, Responner> dicResponners = new Dictionary<string, Responner>();

    public float DeathZoneY = -1;

    public ItemIventory itemIventory;

    public MobileController mobileController;

    public GUIManager guiManager;
    public ItemDataManager itemDataManager;
    public EffectDataManager effectDataManager;
    public EffectDelegateManager effectDelegateManager;

    public string Id;

    public void EventEatItem(ItemData itemData)
    {
        itemIventory.SetIventory(itemData);
    }

    public void EventItemUse(ItemData itemData, GameObject obj)
    {
        itemData.item_effect(obj);
        itemIventory.RemoveIventory(itemData);
    }

    public void EventSceneChange(int idx)
    {
        guiManager.SetGUIScene((GUIManager.E_GUI_STATE)idx);
    }

    public void EventItemUsePlayer(ItemData itemData)
    {
        if (responnerPlayer.objPlayer)
        {
            itemData.item_effect(responnerPlayer.objPlayer);
            itemIventory.RemoveIventory(itemData);
        }
    }

    public void EventSceneResetStart(int idx)
    {
        EventSceneChange("Game", (GUIManager.E_GUI_STATE)idx);
    }

    public void EventSceneChange(string name, GUIManager.E_GUI_STATE guiState)
    {
        SceneManager.LoadScene(name);
        guiManager.SetGUIScene(guiState);
        guiManager.SetGUIScene(GUIManager.curGUIState);
    }

    public void DeathZoneGizmo()
    {
        Vector3 vStartPos = new Vector3(-9999999999, DeathZoneY, 0);
        Vector3 vEndPos = new Vector3(9999999999, DeathZoneY, 0);
        Gizmos.color = Color.red;
        Gizmos.DrawLine(vStartPos, vEndPos);
    }

    //싱글톤: 게임관리자를 어떤객체든 쉽게 접근하게 만들수있다.
    static GameManager instance;
    public static GameManager GetInstance()
    {
        return instance;
    }

    public void Initialize()
    {
        //StaticFunction.InitStaticObject("")
        instance = this;
        textVer.text = string.Format("Ver.{0}", Application.version);
        //itemDataManager.InitItemData(effectDataManager);
        effectDataManager.InitEffectData();
        effectDelegateManager.InitEffectFunction();
        itemDataManager.InitItemDataAsset(effectDelegateManager);

        dicResponners = new Dictionary<string, Responner>();
        dicResponners.Add(responnerPlayer.strPrefabName, responnerPlayer);
        dicResponners.Add(responnerOpossum.strPrefabName, responnerOpossum);
        dicResponners.Add(responnerEagle.strPrefabName, responnerEagle);

        foreach(var reponner in dicResponners)
        {
            reponner.Value.Initialize();
        }

        SetEagleRetrunPointCheck();

        Responner responnerID = dicResponners[Id];
    }

    // Start is called before the first frame update
    void Start()
    {
        ////게임관리자객체만 유지하면 나머지 참조객체들이 사라지므로 의미가 없음.
        //if (instance == null)
        //{
        //    DontDestroyOnLoad(this.gameObject);
        //    instance = this;
        //}
        //else
        //{
        //    Destroy(this.gameObject);
        //}
        Initialize();
    }

    // Update is called once per frame
    void Update()
    {
        if(cameraTracker.objTarget == null)
            cameraTracker.objTarget = responnerPlayer.objPlayer;

        if (mobileController.dynamic == null && responnerPlayer.objPlayer)
            mobileController.dynamic = responnerPlayer.objPlayer.GetComponent<Dynamic>();

        //UpdateEagleRetrunPointCheck();  

        if(responnerPlayer.objPlayer.activeSelf == false)
        {
            guiManager.SetGUIScene(GUIManager.E_GUI_STATE.GAMEOVER);
        }
    }

    private void SetEagleRetrunPointCheck()
    {
        if(responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();
            if (eagle.objResponPoint == null)
            {
                eagle.objResponPoint = responnerEagle.gameObject;
            }

            if (eagle.objPatrolPoint == null)
            {
                eagle.objPatrolPoint = responnerOpossum.gameObject;
            }
        }
    }

    private void OnDrawGizmos()
    {
        DeathZoneGizmo();
    }  
}