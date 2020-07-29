using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Stopwatch : MonoBehaviour
{
    private Text view;
    private double timer;
    private double stopwatch;
    
    public const int watingtime = 20;
    public GameObject obj;
    
    // Start is called before the first frame update
    void Start()
    {
        timer = 0.0;
        stopwatch = 0.0;
        view = GetComponent<Text>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Player.isSurvive)
        {
            stopwatch += Time.deltaTime;
            timer += Time.deltaTime;
            String timeText = String.Format("{0:0.00}", stopwatch);
            view.text = timeText;
            if (timer > watingtime)
            {
                timer = 0;
                Instantiate(obj);
            }
        }
    }
}
