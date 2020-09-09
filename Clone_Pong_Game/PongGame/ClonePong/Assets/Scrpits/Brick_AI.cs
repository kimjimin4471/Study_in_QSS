using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Brick_AI : MonoBehaviour
{
    public GameObject gameobject;
    public float speed;
    public Ball ball;

    private Vector3 dirvec;
    private void FixedUpdate()
    {
        dirvec = new Vector3(0, ball.transform.position.y * 0.1f, 0);
    }

    private void Update()
    {
        transform.Translate(dirvec * (speed * Time.deltaTime));

    }
}
