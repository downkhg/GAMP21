using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float JumpPower= 10;
    public bool isJump = false;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
            transform.position += Vector3.right * Time.deltaTime;

        if (Input.GetKey(KeyCode.LeftArrow))
            transform.position += Vector3.left * Time.deltaTime;

        if (Input.GetKey(KeyCode.DownArrow))
        {
            //transform.position += Vector3.down * Time.deltaTime;
            
        }

        if (Input.GetKeyDown(KeyCode.UpArrow))
        {
            if (isJump == false)
            {
                Rigidbody2D rigidbody2D = this.gameObject.GetComponent<Rigidbody2D>();
                rigidbody2D.AddForce(Vector3.up * JumpPower);
                //transform.position += Vector3.up * Time.deltaTime;
                isJump = true;
            }
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isJump = false;
        Debug.Log("OnCollisionEnter2D:" + collision.gameObject.name);
    }
}
