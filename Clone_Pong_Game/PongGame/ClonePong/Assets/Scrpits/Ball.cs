using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    public float speed;

    private Vector2 direction = new Vector2(1, 1);
    
    void Awake()
    {
        
    }

    // Update is called once per frame
    private void FixedUpdate()
    {
        transform.Translate(direction * (speed * Time.deltaTime));
    }

    private void OnTriggerEnter2D(Collider2D col)
    {
        if (col.CompareTag("Brick"))
        {
            direction.x *= -1;
        }

        if (col.CompareTag("Wall"))
        {
            direction.y *= -1;
        }
    }
}
