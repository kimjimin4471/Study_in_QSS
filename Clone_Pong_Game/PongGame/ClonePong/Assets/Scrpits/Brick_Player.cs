using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class Brick_Player : MonoBehaviour
{
    public Vector3 direction = new Vector3(0, 3f, 0);
    
    void Update()
    {
        if (Input.GetKey(KeyCode.W))
        {
            transform.Translate(direction*Time.deltaTime);
        }
        if (Input.GetKey(KeyCode.S))
        {
            transform.Translate(-direction*Time.deltaTime);
        }
    }
}
