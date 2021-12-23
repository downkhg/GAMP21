using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    Vector3 vStart;
    // Start is called before the first frame update
    void Start()
    {
        //Destroy(gameObject, 1);
        vStart = this.transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 vPos = this.transform.position;
        //벡터의 차를 이용하여 거리를 구하는 방법
        //Vector3 vDist = vStart - vPos;
        //float fDist = vDist.magnitude;
        float fDist = Vector3.Distance(vStart, vPos);

        if(fDist >= 1)
        {
            Destroy(gameObject);
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Monster")
        {
            Player target = collision.gameObject.GetComponent<Player>();
            Player attaker = 
                GameManager.GetInstacne().responnerPlayer.objPlayer.GetComponent<Player>();

            attaker.Attack(target);
            //Destroy(collision.gameObject);
        }
    }
}
