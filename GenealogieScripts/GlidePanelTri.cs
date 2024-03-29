using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GlidePanelTri : MonoBehaviour
{
    public Sprite[] state;
    public float posYMin;
    RectTransform rect;
    GameObject rechercheGO;

    private void Start()
    {
        rect = GetComponent<RectTransform>();
        posYMin = 0-rect.rect.height;
        rechercheGO = transform.Find("Recherche").gameObject;
        //rechercheGO.SetActive(false);
    }

    public void glide()
    {
        if (rect.anchoredPosition.y == posYMin)
        {
            StartCoroutine(gliding(false));
        }
        else if (rect.anchoredPosition.y == 0)
        {
            StartCoroutine(gliding(true));
        }
    }

    IEnumerator gliding(bool on)
    {
        if (on)
        {
            while (rect.anchoredPosition.y > posYMin) // on descend
            {
                // MenuManager.manager.resetTri();
                rect.anchoredPosition = new Vector2(rect.anchoredPosition.x, rect.anchoredPosition.y-50);
                yield return new WaitForSeconds(0.001f);
            }
            transform.Find("ButtonGlide").GetComponent<Image>().sprite = state[1];
        }
        else
        {
            while (rect.anchoredPosition.y < 0) // on remonte
            {
                rect.anchoredPosition = new Vector2(rect.anchoredPosition.x, rect.anchoredPosition.y+50);
                yield return new WaitForSeconds(0.001f);
            }
            transform.Find("ButtonGlide").GetComponent<Image>().sprite = state[0];
        }
    }
}
