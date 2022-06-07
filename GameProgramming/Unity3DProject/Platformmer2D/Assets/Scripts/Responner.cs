﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Responner : MonoBehaviour
{
    public GameObject objPlayer;
    public bool isRespon = false;
    public string strPrefabName;
    public float Time = 1;
    // Start is called before the first frame update
    void Start()
    {
        strPrefabName = objPlayer.name;
    }

    // Update is called once per frame
    void Update()
    {
        if (objPlayer.activeSelf == false)// && isRespon == false)
        {
            if (isRespon == false)
                StartCoroutine(ProcessTimmer());
        }
    }

    IEnumerator ProcessTimmer()
    {
        //Debug.Log("ProcessTimmer 1");
        isRespon = true;
        yield return new WaitForSeconds(Time);
        objPlayer.GetComponent<Player>().Recovery();
        objPlayer.SetActive(true);
        objPlayer.transform.position = this.transform.position;
        isRespon = false;
        //Debug.Log("ProcessTimmer 2");
    }
}
