using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class Furet : MonoBehaviour//, IPointerClickHandler
{
    public furet identite;
    [SerializeField] TMP_Text nom;
    [SerializeField] TMP_Text sexe;
    [SerializeField] TMP_Text couleur;
    [SerializeField] TMP_Text dateNaissance;
    [SerializeField] TMP_Text pere;
    [SerializeField] TMP_Text mere;
    [SerializeField] TMP_Text provenance;
    [SerializeField] TMP_Text numPuce;
    [SerializeField] Image fondSexeFuret;
    MenuManager manager;

    void Awake()
    {
        manager = MenuManager.manager;
    }

    void Start()
    {
        if(identite != null)
        {
            applyIdentity();
        }
    }

    public void applyIdentity()
    {
        if(identite.mort)
            fondSexeFuret.color = MenuManager.deadColor;
        else if (identite.sexe == 0)
            fondSexeFuret.color = Color.white;
        else if (identite.sexe == 1)
            fondSexeFuret.color = MenuManager.maleColor;
        else if (identite.sexe == 2)
            fondSexeFuret.color = MenuManager.femaleColor;
        if (identite.nom == "")
            nom.text = "<color=#880000>Nom ?</color>";
        else
        nom.text = identite.nom;
        couleur.text = identite.couleur;
        if (identite.dateNaissance == "")
            dateNaissance.text = "<color=#aa0000>Date inconnue</color>";
        else
        dateNaissance.text = identite.dateNaissance;
        if (identite.pere == "")
            pere.text = "<color=#aa0000>?</color>";
        else
        pere.text = identite.pere;

        if (identite.mere == "")
            mere.text = "<color=#aa0000>?</color>";
        else
            mere.text = identite.mere;
        if (identite.enfants == null)
        identite.enfants = new List<string>();
        if (identite.provenance == "")
            provenance.text = "";
        else
            provenance.text = identite.provenance;
        if (identite.numPuce == "")
            numPuce.text = "";
        else
            numPuce.text = identite.numPuce;
    }

    public void clicked()
    {
        if (transform.parent.parent.parent.parent.name == "ListeFurets")
            manager.enableEditFuret(identite, transform.GetSiblingIndex());
        else if (transform.parent.parent.parent.parent.name == "Liste")
            manager.addParent(identite);
        else if (transform.parent.parent.parent.parent.name == "ListeChilds")
        {
            manager.disableEnfantsList();
            manager.enableEditFuret(identite, transform.GetSiblingIndex());
        }
        else
            Debug.Log(transform.parent.parent.parent.parent.name);
    }

    /*public void OnPointerClick(PointerEventData eventData)
    {
        clicked();
    }*/
}
