using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Timmer : MonoBehaviour
{
    int CurTime = 0;
    bool isUse = false;

    float fCurTime;

    IEnumerator ProcessCountTime()
    {
        Debug.Log("ProcessCountTime Start");
        CurTime = 0;
        isUse = true;
        while(isUse)
        {
            Debug.Log("ProcessCountTime WaitForSeconds Start");
            yield return new WaitForSeconds(1);
            CurTime++;
            Debug.Log("ProcessCountTime WaitForSeconds End");
        }
        isUse = false;
        Debug.Log("ProcessCountTime End");
    }

    void TimmerUpdate()
    {
        if (isUse)
        {
            if (fCurTime >= 1)
            {
                fCurTime -= 1;
                CurTime++;
            }
            else
                fCurTime += Time.deltaTime;
        }
    }

    public void Update()
    {
        //TimmerUpdate();
    }

    public void Play()
    {
        StartCoroutine(ProcessCountTime());
        //isUse = true;
    }

    public void Stop()
    {
        isUse = false;
    }

    public void Reset()
    {
        fCurTime = 0;
        StopCoroutine(ProcessCountTime());
       // StopAllCoroutines();
    }

    private void OnGUI()
    {
        if (GUI.Button(new Rect(Screen.width / 2 - 50, Screen.height / 2 - 50, 100, 100), "Time:" + CurTime + "/" + fCurTime))
        {
            if (isUse)
                Stop();
            else
                Play();
        }
        if (GUI.Button(new Rect(Screen.width / 2 - 100, Screen.height / 2 - 10, 100, 100), "Reset"))
        {
            if (isUse)
            {
                Reset();
            }
        }
    }
}
