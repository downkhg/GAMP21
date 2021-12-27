using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Opossum : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position += Vector3.left * Time.deltaTime;
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            Player target = collision.gameObject.GetComponent<Player>();
            Player attaker = this.gameObject.GetComponent<Player>();
            SuperMode superMode = target.GetComponent<SuperMode>();

            if (superMode.isUse == false)
            {
                attaker.Attack(target);
                superMode.OnMode();
            }
        }
    }
}
