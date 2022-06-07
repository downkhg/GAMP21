using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SuperMode : MonoBehaviour
{
    public bool isUes;
    public float Time;

    IEnumerator ProcessTimmer()
    {
        Debug.Log("SuperMode::ProcessTimmer Start");
        isUes = true;
        yield return new WaitForSeconds(Time);
        //종료시 투명하지않게 만듦.
        GetComponent<SpriteRenderer>().color = Color.white;
        isUes = false;
        Debug.Log("SuperMode::ProcessTimmer End");
    }

    public void OnMode()
    {
        if(!isUes )
            StartCoroutine(ProcessTimmer());
    }

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log("SuperMode::Start");
        if (isUes == true) StartCoroutine(ProcessTimmer());
    }

    // Update is called once per frame
    void Update()
    {
        if(isUes)
        {
            SpriteRenderer spriteRenderer = GetComponent<SpriteRenderer>();
            Color color = spriteRenderer.color;
            if (color.a == 0) color.a = 1;
            else color.a = 0;
            spriteRenderer.color = color;
        }
    }
}
