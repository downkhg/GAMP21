using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Eagle : MonoBehaviour
{
    public GameObject objTarget;
    public float Speed;
    public float Site = 0.5f;

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(this.transform.position, Site);
    }

    private void FixedUpdate()
    {
        int nLayer = 1 << LayerMask.NameToLayer("Player");
        Collider2D collider = 
            Physics2D.OverlapCircle(this.transform.position, Site, nLayer);

        if(collider)
        {
            objTarget = collider.gameObject;
        }
    }

    // Update is called once per frame
    void Update()
    {
        if (objTarget != null)
        {
            Vector3 vTargetPos = objTarget.transform.position;
            Vector3 vPos = this.transform.position;
            Vector3 vDist = vTargetPos - vPos;
            Vector3 vDir = vDist.normalized;
            float fDist = vDist.magnitude;

            if(fDist > Time.deltaTime)
                transform.position += vDir * Speed * Time.deltaTime;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log("OnTriggerEnter2D:"+collision.gameObject.name);
        if(collision.gameObject.tag == "Player")
            objTarget = collision.gameObject;
    }
}
