using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public bool isRespon = false;
    public string strPrefabName;
    public float fTime = 1;

    public float fCurTime;

    public void Initialize()
    {
        objPlayer = GameObject.Find(strPrefabName);
        //strPrefabName = objPlayer.name;
        if (objPlayer == null)
        {
            objPlayer = StaticFunction.InitStaticObject("Prefabs/" + strPrefabName, this.transform.position);
            objPlayer.name = strPrefabName;
        }
    }

    // Start is called before the first frame update
    //void Start()
    //{
    //    objPlayer = GameObject.Find(strPrefabName);
    //    //strPrefabName = objPlayer.name;
    //    if (objPlayer == null)
    //    {
    //        objPlayer = StaticFunction.InitStaticObject("Prefabs/" + strPrefabName, this.transform.position);
    //        objPlayer.name = strPrefabName;
    //    }
    //}

    // Update is called once per frame
    void Update()
    {
        if (objPlayer.gameObject && objPlayer.activeSelf == false)// && isRespon == false)
        {
            if (isRespon == false)
                StartCoroutine(ProcessTimmer());
        }
    }

    public void ResetPlayer()
    {
        fCurTime = 0;
        StaticFunction.ResponPlayer(objPlayer, gameObject);
        isRespon = false;
    }

    IEnumerator ProcessTimmer()
    {
        //Debug.Log("ProcessTimmer 1");
        isRespon = true;
        while (fCurTime <= fTime)
        {
            fCurTime += Time.deltaTime;
            yield return null;
        }
        fCurTime = 0;
        //objPlayer.GetComponent<Player>().Recovery();
        //objPlayer.SetActive(true);
        //objPlayer.transform.position = this.transform.position;
        StaticFunction.ResponPlayer(objPlayer, gameObject);
        isRespon = false;
        //Debug.Log("ProcessTimmer 2");
    }
}
