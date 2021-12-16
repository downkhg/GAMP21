using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public CameraTracker mainCameraTracker;
    public Responner responnerPlayer;

    void CameraTrackingTargetPlayerProcess()
    {
        if(mainCameraTracker.objTarget == null)
        {
            if(responnerPlayer.objPlayer != null)
                mainCameraTracker.objTarget = responnerPlayer.objPlayer;
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        CameraTrackingTargetPlayerProcess();
    }
}
