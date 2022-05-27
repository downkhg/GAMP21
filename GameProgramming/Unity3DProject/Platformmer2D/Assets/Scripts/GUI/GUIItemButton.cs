using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class GUIItemButton : MonoBehaviour , IPointerDownHandler, IPointerUpHandler
{
    public Text textItemName;
    public Image imgItemSprite;
    ItemData cItemData;

    public bool Set(ItemData itemData)
    {
        Debug.Log("GUIItemButton.Set:" + itemData);
        cItemData = itemData;
        if (itemData != null)
        {
            textItemName.text = itemData.name;
            Sprite sprite = Resources.Load<Sprite>("Image/" + itemData.icon);
            if (sprite) imgItemSprite.sprite = sprite;
            Button button = this.GetComponent<Button>();
            button.onClick.AddListener(() => OnClickEvent(itemData));
            return true;
        }
        return false;
    }

    public void OnClickEvent(ItemData itemData)
    {
        Debug.Log("GUIItemButton.OnClickEvent:" + itemData);
        GameManager.GetInstance().EventItemUsePlayer(itemData);
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //Set(GameManager.GetInstance().itemDataManager.GetItemData(ItemDataManager.E_ITEMDATA.BULLET));
    }

    public void OnPointerDown(PointerEventData eventData)
    {
        GUIManager.GetInstance().guiItemIventory.guiComment.OpenComment(cItemData);
        Debug.Log("OnPointerDown");
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        GUIManager.GetInstance().guiItemIventory.guiComment.CloseComment();
        Debug.Log("OnPointerUp");
    }
}
