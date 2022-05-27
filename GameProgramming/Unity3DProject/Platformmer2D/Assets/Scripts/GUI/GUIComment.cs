using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GUIComment : MonoBehaviour
{
    [SerializeField]
    RectTransform rectTransform;
    [SerializeField]
    Text textCommnet;
    // Start is called before the first frame update
    void Start()
    {
        rectTransform = GetComponent<RectTransform>();
    }

    // Update is called once per frame
    void Update()
    {
        rectTransform.position = Input.mousePosition;
    }

    public void OpenComment(ItemData itemData)
    {
        textCommnet.text = itemData.comment;
        //구조체인 벡터의 멤버는 참조해서 변경할수없다.
        //rectTransform.sizeDelta.x = 12 * textCommnet.text.Length;
        Vector2 vSize = rectTransform.sizeDelta;
        vSize.x = 12 * textCommnet.text.Length;
        rectTransform.sizeDelta = vSize;
        gameObject.SetActive(true);
    }
    public void CloseComment()
    {
        gameObject.SetActive(false);
    }
}
