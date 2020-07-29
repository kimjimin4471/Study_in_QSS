using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    private Transform transform;
    private Rigidbody2D rigidbody2D;
    private bool canjump = false;

    public static bool isSurvive = true;
    // Start is called before the first frame update
    void Start()
    {
        transform = GetComponent<Transform>();
        rigidbody2D = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.A))
        {
            rigidbody2D.AddForce(new Vector2(-5,0));
        }   
        if (Input.GetKey(KeyCode.D))
        {
            rigidbody2D.AddForce(new Vector2(5,0));
        }
        if (Input.GetKeyDown(KeyCode.W) && canjump)
        {
            rigidbody2D.AddForce(new Vector2(0, 300));
            canjump = false;
        }   
    }

    void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.CompareTag("Ground"))
        {
            canjump = true;
        }
    }
   
}
