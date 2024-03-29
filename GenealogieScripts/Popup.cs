using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class Popup : MonoBehaviour
{
    CanvasGroup canvas;
    TMP_Text texte;
    float alpha;
    void Awake()
    {
        canvas = GetComponent<CanvasGroup>();
        texte = transform.GetChild(0).GetComponent<TMP_Text>();
    }

    public void fading(string textToShow)
    {
        texte.text = textToShow;
        StopAllCoroutines();
        StartCoroutine(fadeInOut());
    }
    
    IEnumerator fadeInOut()
    {
        alpha = 0;
        while (alpha < 1)
        {
            alpha += 0.05f;
            canvas.alpha = alpha;
            yield return new WaitForSeconds(0.01f);
        }
        yield return new WaitForSeconds(1);
        while (alpha > 0)
        {
            alpha -= 0.05f;
            canvas.alpha = alpha;
            yield return new WaitForSeconds(0.01f);
        }
        texte.text = string.Empty;
    }
}
