using System;
using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class FurGenealogie : MonoBehaviour
{
    //public int ordre; // si ordre = 0, c'est le furet de base. Si ordre = 2, c'est un parent. Si ordre = 3, c'est un grand-parent.
    public furet identite;
    [SerializeField] TMP_Text nom;
    [SerializeField] TMP_Text couleur;
    [SerializeField] Image image;
    [SerializeField] GameObject flecheParents;
    public Vector2 posPere = new Vector2(350, 60);
    public Vector2 posMere = new Vector2(350, -60);
    [SerializeField] GameObject pereGO;
    [SerializeField] GameObject mereGO;
    [SerializeField] LineRenderer lineRendPere;
    [SerializeField] LineRenderer lineRendMere;
    Vector2 posLinePeres = new Vector2(80, 25);
    Vector2 posLineMeres = new Vector2(80, -25);
    public int gen;

    public void clicked()
    {

        furet fur = MenuManager.manager.furets.Find(x => x.nom == nom.text);
        if (fur != null)
            MenuManager.manager.clickFuretGen(nom.text);
            else
            MenuManager.manager.nouvelleFicheAvecNom(nom.text);
        // on affiche la fiche d'identité du furet
    }
    
    public void applyFalseIdentite(int gender, int generation, string nomFuret) // un furet qui n'existe pas ou qui n'a pas de nom dans la base de données mais qu'on va afficher quand-même s'il existe des infos dessus
    {
        // print("Fausse identité : " + nomFuret);
        if (gen <= 5)
        {
            gen = generation + 1;
            MenuManager.manager.applyGen(gen);
            switch (gender)
            {
                case 0:
                    image.color = Color.white;
                    break;
                case 1:
                    image.color = MenuManager.maleColor;
                    break;
                case 2:
                    image.color = MenuManager.femaleColor;
                    break;
            }
            nom.text = nomFuret;
            couleur.text = "";
            searchPere();
            searchMere();
        }
    }

    public void applyIdentite(int generation)
    {
        // print("Identité : " + identite.nom);
        if(gen<=5)
        {
            gen = generation + 1;
            MenuManager.manager.applyGen(gen);
            switch (identite.sexe)
            {
                case 0:
                    image.color = Color.white;
                    break;
                case 1:
                    image.color = MenuManager.maleColor;
                    break;
                case 2:
                    image.color = MenuManager.femaleColor;
                    break;
            }
            if (identite.couleur != "" && identite.couleur != "Aucune" && identite.couleur != null)
                couleur.text = identite.couleur;
            else
                couleur.text = "";
            if (identite.nom != "" && identite.nom != null)
                nom.text = identite.nom;
            else
                nom.text = "Nom inconnu";
            searchPere();
            searchMere();
        }
    }
    
    void searchPere()
    {
        // on recherche le père par son nom dans la base de données
        // s'il y a un père, on active l'objet et on fait setLinePere(), puis on lui fait applyIdentite()
        string pere = identite.pere;
        if(pere != null && pere != "")
        {
            // faire en sorte que si le père n'est pas dans la base de données, entrer seulement le nom du furet et faire la line renderer, mais ne pas continuer la recherche de parents.
            furet pereFuret = MenuManager.manager.furets.Find(x => x.nom == pere);
            FurGenealogie pereGen = pereGO.GetComponent<FurGenealogie>();
            if (pereFuret != null)
            {
                pereGen.identite = pereFuret;
                pereGen.applyIdentite(gen);
            }
            else
            {
                pereGen.applyFalseIdentite(1, gen, pere);
            }
            setLinePere();
            pereGO.SetActive(true);
        }
        else
        {
            lineRendPere.gameObject.SetActive(false);
            pereGO.SetActive(false);
        }
    }

    void searchMere()
    {
        // on recherche le père par son nom dans la base de données
        // s'il y a un père, on active l'objet et on fait setLinePere(), puis on lui fait applyIdentite()
        string mere = identite.mere;
        if (mere != null && mere != "")
        {
            // faire en sorte que si le père n'est pas dans la base de données, entrer seulement le nom du furet et faire la line renderer, mais ne pas continuer la recherche de parents.
            furet mereFuret = MenuManager.manager.furets.Find(x => x.nom == mere);
            FurGenealogie mereGen = mereGO.GetComponent<FurGenealogie>();
            if (mereFuret != null)
            {
                mereGen.identite = mereFuret;
                mereGen.applyIdentite(gen);
            }
            else
            {
                mereGen.applyFalseIdentite(2, gen, mere);
            }
            setLineMere();
            mereGO.SetActive(true);
        }
        else
        {
            lineRendMere.gameObject.SetActive(false);
            mereGO.SetActive(false);
        }
    }
    
    void setLinePere()
    {
        // print("setting line for " + identite.nom);
        // lineRendPere.positionCount = 2;
        Vector2 perePos = pereGO.transform.localPosition;
        perePos.x -= 80;
        if(perePos.x<posLinePeres.x)
        {
            perePos.x = posLinePeres.x;
            posLinePeres.x = 0;
        }
        lineRendPere.SetPosition(0, posLinePeres);
        perePos.y -= 25;
        lineRendPere.SetPosition(1, perePos);
        lineRendPere.gameObject.SetActive(true);
    }
    void setLineMere()
    {
        // lineRendMere.positionCount = 2;
        Vector2 merePos = mereGO.transform.localPosition;
        merePos.x -= 80;
        if (merePos.x < posLineMeres.x)
        {
            merePos.x = posLineMeres.x;
            posLineMeres.x = 0;
        }
        lineRendMere.SetPosition(0, posLineMeres);
        merePos.y += 25;
        lineRendMere.SetPosition(1, merePos);
        lineRendMere.gameObject.SetActive(true);
    }
}
