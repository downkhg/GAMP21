﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float JumpPower= 10;
    public bool isJump = false;
    public int Score = 0;

    public Gun gun;
    public Vector3 dir = Vector3.right;

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.position += Vector3.right * Time.deltaTime;
            dir = Vector3.right;
        }

        if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.position += Vector3.left * Time.deltaTime;
            dir = Vector3.left;
        }

        if (Input.GetKey(KeyCode.DownArrow))
        {
            //transform.position += Vector3.down * Time.deltaTime;
        }

        if (Input.GetKeyDown(KeyCode.Space))
        {
            if (isJump == false)
            {
                Rigidbody2D rigidbody2D = this.gameObject.GetComponent<Rigidbody2D>();
                rigidbody2D.AddForce(Vector3.up * JumpPower);
                //transform.position += Vector3.up * Time.deltaTime;
                isJump = true;
            }
        }

        if (Input.GetKeyDown(KeyCode.X))
        {
            gun.Shot(dir);
        }

        if (transform.position.y < -4)
        {
            Destroy(this.gameObject);
        }
    }

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 100, 20), "Score:" + Score);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isJump = false;
        
        Debug.Log("OnCollisionEnter2D:" + collision.gameObject.name);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        //if (collision.gameObject.name == "cherry")
        //{
        //    Score += 10;
        //    Destroy(collision.gameObject);
        //}
        if (collision.gameObject.tag == "Object")
        {
            Destroy(collision.gameObject);
        }
    }
}
