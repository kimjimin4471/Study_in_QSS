using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class Poop : MonoBehaviour
{
    private Transform transform;
    private Rigidbody2D _rigidbody2D;
    private bool isTouch;
    void Start()
    {
        transform = GetComponent<Transform>();
        _rigidbody2D = GetComponent<Rigidbody2D>();
    }
    private void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.CompareTag("Player"))
        {
             col.gameObject.SetActive(false);    //똥이 플레이어한테 닿으면 플레이어가 사라진다.
             Player.isSurvive = false;
        }
        if (col.gameObject.CompareTag("Ground"))
        {
            if (isTouch == false)
            {
                _rigidbody2D.velocity = new Vector2(Random.Range(-3f, 3f), _rigidbody2D.velocity.y);
                
                isTouch = true;
                return;
            }
            transform.position = new Vector3(Random.Range(-15f, 15f),10, 0);
            _rigidbody2D.velocity = new Vector2(0, 0);
            _rigidbody2D.mass += 5;
            isTouch = false;
        }

        if (col.gameObject.CompareTag("Coin"))
            transform.position = new Vector3(Random.Range(-15f, 15f), 10, 0);
    }
}
