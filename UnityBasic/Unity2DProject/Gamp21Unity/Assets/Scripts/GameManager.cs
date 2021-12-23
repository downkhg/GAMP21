using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public CameraTracker mainCameraTracker;
    public Responner responnerPlayer;
    public Responner responnerEagle;
    public Responner responnerOpossum;

    static GameManager instance;
    
    public static GameManager GetInstacne()
    {
        return instance;
    }

    private void Awake()
    {
        instance = this;
    }

    void CameraTrackingTargetPlayerProcess()
    {
        if(mainCameraTracker.objTarget == null)
        {
            if(responnerPlayer.objPlayer != null)
                mainCameraTracker.objTarget = responnerPlayer.objPlayer;
        }
    }

    void EaglePointSetting()
    {
        if(responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();

            if (eagle.objPatrolPoint == null && eagle.objResponPoint == null)
            {
                eagle.objPatrolPoint = responnerOpossum.gameObject;
                eagle.objResponPoint = responnerEagle.gameObject;
                eagle.SetAIState(Eagle.E_AI_STATE.RETRUN);
            }
        }
    }

    // Update is called once per frame
    void Update()
    {
        CameraTrackingTargetPlayerProcess();
        EaglePointSetting();
    }
}
