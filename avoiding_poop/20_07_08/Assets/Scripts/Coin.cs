using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;
using UnityEngine.UI;
public class Coin : MonoBehaviour
{
    public Text view;
    public int total;
    private Transform transform;
    // Start is called before the first frame update
    void Start()
    {
        total = 0;
        transform = GetComponent<Transform>();
    }

    // Update is called once per frame
    private void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.CompareTag("Player"))
        {
            transform.position = new Vector3(Random.Range(-15f, 15f), -2.358f, 0);
            total += 1;
        }
    }

    void Update()
    {
        view.text = total.ToString();
    }
}
