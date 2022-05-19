using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TransfromViewer : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnGUI()
    {
        string strMsg = transform.localToWorldMatrix.ToString();

        GUI.Box(new Rect(0,0,100,100), strMsg);
    }
}
