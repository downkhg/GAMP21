using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed;
    public float Site = 0.5f;
    public GameObject objResponPoint;
    public GameObject objPatrolPoint;
    public bool isMove = false;

    void PatolProcess()
    {
        if (objTarget)
        {
            if (isMove == false)
            {
                if (objTarget.name == objResponPoint.name)
                {
                    objTarget = objPatrolPoint;
                    Debug.LogError(objPatrolPoint.name);
                }
                else if (objTarget.name == objPatrolPoint.name)
                {
                    objTarget = objResponPoint;
                    Debug.LogError(objResponPoint.name);
                }
            }
        }
    }

    void TargetTrackingProcess()
    {
        if (objTarget != null)
        {
            Vector3 vTargetPos = objTarget.transform.position;
            Vector3 vPos = this.transform.position;
            Vector3 vDist = vTargetPos - vPos;
            Vector3 vDir = vDist.normalized;
            float fDist = vDist.magnitude;

            float fMove = Speed * Time.deltaTime;

            if (fDist > fMove)
            {
                transform.position += vDir * fMove;
                isMove = true;
            }
            else
            {
                isMove = false;
            }
        }
        else
        {
            objTarget = objResponPoint;
        }
    }

    void Update()
    {
        TargetTrackingProcess();
        PatolProcess();
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, Site);
    }

    private void FixedUpdate()
    {
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider2D collider =
            //Physics2D.OverlapCircle(this.transform.position, Site);
            Physics2D.OverlapCircle(this.transform.position, Site, nLayer);
        if(collider)
        {
            objTarget = collider.gameObject;
        }
    }

    // Update is called once per frame
   
    private void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log("OnTriggerEnter2D:"+collision.gameObject.name);
        if(collision.gameObject.tag == "Player")
            objTarget = collision.gameObject;
    }
}
