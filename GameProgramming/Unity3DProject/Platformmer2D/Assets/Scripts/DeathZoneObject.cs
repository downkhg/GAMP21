using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeathZoneObject : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        GameManager gameManager = GameManager.GetInstance();

        if (gameManager != null && gameManager.DeathZoneY > this.transform.position.y)
           gameObject.SetActive(false);
    }
}
