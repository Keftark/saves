using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

public class MenuManager : MonoBehaviour
{
    public bool localSave;
    public static MenuManager manager;
    public static Color deadColor = new Color(0.7f, 0.7f, 0.7f, 1);
    public static Color maleColor = new Color(0.85f, 0.85f, 1, 1);
    public static Color femaleColor = new Color(1, 0.85f, 0.85f, 1);

    [SerializeField] GameObject furetPrefab;
    [SerializeField] Button buttonStats;

    [SerializeField] Sprite maleSprite;
    [SerializeField] Sprite femelleSprite;
    [SerializeField] Sprite inconnuSprite;

    public List<furet> furets;
    List<furet> queueFichesFurets;

    [SerializeField] GameObject buttonDelete;
    [SerializeField] Transform listeFuretsTransform;
    [SerializeField] Transform editFuretUI;
    [SerializeField] Transform scrollView;
    [SerializeField] Scrollbar listeScrollBar;
    float scrollBarValue;
    float listTransformY;
    [SerializeField] Transform listeFuretsAttach;
    [SerializeField] Transform listeNomsAttach;
    [SerializeField] Transform listeEnfantsAttach;

    public Popup popup;
    [SerializeField] GameObject editCanvas;
    [SerializeField] GameObject listeNomsCanvas;
    [SerializeField] GameObject listeEnfantsCanvas;
    [SerializeField] GameObject inputsGO;
    [SerializeField] GameObject textesGO;
    [SerializeField] Image sexeImage;

    [SerializeField] GameObject notesCanvas;
    [SerializeField] TMP_InputField inputNoteFuret;
    [SerializeField] TMP_InputField inputNomFuret;
    [SerializeField] TMP_Dropdown inputCouleurFuret;
    [SerializeField] TMP_InputField inputDateFuret;
    [SerializeField] TMP_InputField inputDateDayFuret;
    [SerializeField] TMP_InputField inputDateMonthFuret;
    [SerializeField] TMP_InputField inputDateYearFuret;
    [SerializeField] TMP_InputField inputPereFuret;
    [SerializeField] TMP_InputField inputMereFuret;
    [SerializeField] TMP_InputField inputProvenanceFuret;
    [SerializeField] TMP_InputField inputNumPuce;
    [SerializeField] Toggle toggleMort;
    [SerializeField] TMP_Text texteNoteFuret;
    [SerializeField] TMP_Text texteNomFuret;
    [SerializeField] TMP_Text texteCouleurFuret;
    [SerializeField] TMP_Text texteDateFuret;
    [SerializeField] TMP_Text textePereFuret;
    [SerializeField] TMP_Text texteMereFuret;
    [SerializeField] TMP_Text headerEdit;
    [SerializeField] TMP_Text texteTotal;
    [SerializeField] TMP_Text texteEnfants;
    [SerializeField] TMP_Text texteMort;
    [SerializeField] TMP_Text texteProvenanceFuret;
    [SerializeField] TMP_Text texteAutreElevage;
    [SerializeField] Toggle toggleAutreElevage;
    [SerializeField] TMP_Text texteNumPuce;
    [SerializeField] Button male;
    [SerializeField] Button femelle;
    [SerializeField] GameObject maleChild;
    [SerializeField] GameObject femelleChild;
    [SerializeField] Image maleImg;
    [SerializeField] Image femelleImg;
    int sexe;
    List<string> couleurs;

    bool nouveauFuret;


    furet curEditFuret;
    int indexCurEditFuret = -1;

    // notes
    public RectTransform rectFond;
    public RectTransform rectNotes;
    public RectTransform rectNotesParent;
    public Vector2 vectorFond;
    public Vector2 vectorNotesParent;


    // tri
    [SerializeField] GlidePanelTri panelTri;
    [SerializeField] TMP_InputField inputRecherche;
    [SerializeField] TMP_InputField inputAnneeRecherche;
    [SerializeField] TMP_InputField inputNumPuceRecherche;
    [SerializeField] List<GameObject> curTri;
    [SerializeField] TMP_Dropdown triCouleur;
    [SerializeField] Toggle triMort;
    [SerializeField] Toggle triAutreElevage;
    [SerializeField] Transform triMale;
    [SerializeField] Transform triFemelle;
    [SerializeField] Transform triTous;

    // généalogie
    [SerializeField] GameObject genealogyCanvas;
    [SerializeField] GameObject baseFuret;
    [SerializeField] GameObject boutonGenealogy;
    public GameObject interfaceScreenshot;

    // stats
    [SerializeField] GameObject statsCanvas;
    [SerializeField] TMP_Dropdown triStats;
    [SerializeField] GameObject[] statsGo;
    
    [SerializeField] TMP_Text toutTotal;
    [SerializeField] TMP_Text toutSexe;
    [SerializeField] TMP_Text toutAnnee;
    [SerializeField] TMP_Text toutCouleur;

    [SerializeField] TMP_Text maleTotal;
    [SerializeField] TMP_Text femelleTotal;
    [SerializeField] TMP_Text inconnuTotal;

    [SerializeField] TMP_Text totalCouleur;

    [SerializeField] TMP_Text totalAnnee;
    [SerializeField] GameObject buttonOpenFolder;
    [SerializeField] GameObject buttonOpenPhotoFuret;
    string fullPath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "PhotosFurets");


    void Awake()
    {
        manager = this;
        vectorFond = rectFond.sizeDelta;
        vectorNotesParent = rectNotesParent.sizeDelta;
    }
    private void Start()
    {
        queueFichesFurets = new List<furet>();
        curTri = new List<GameObject>();
        Application.targetFrameRate = 60;
        notesCanvas.SetActive(false);
        statsCanvas.SetActive(false);
        genealogyCanvas.SetActive(false);
        listeEnfantsCanvas.SetActive(false);
        listeNomsCanvas.SetActive(false);
        editCanvas.SetActive(false);
        showStatsPanel(4); // cache tous les panels de stats
        initDropDownCouleurs();
        initDropdownTri();
        initDropdownStatsTri();
        if (Application.platform == RuntimePlatform.Android)
        {
            buttonOpenFolder.SetActive(false);
            buttonOpenPhotoFuret.SetActive(false);
        }
    }

    void initDropDownCouleurs()
    {
        couleurs = new List<string>();
        couleurs.Add("Aucune");
        couleurs.Add("Albinos");
        couleurs.Add("Angora");
        couleurs.Add("Black");
        couleurs.Add("Cannelle");
        couleurs.Add("Champagne");
        couleurs.Add("Chocolat");
        couleurs.Add("Zibeline");
        couleurs.Add("Zibeline black");
        inputCouleurFuret.ClearOptions();
        inputCouleurFuret.AddOptions(couleurs);
    }
    
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            if(statsCanvas.activeSelf)
            {
                buttonRetourStats();
            }
            else if (notesCanvas.activeSelf)
            {
                cancelEditNotes();
            }
            else if (listeNomsCanvas.activeSelf)
            {
                disableSecondList();
            }
            else if (editCanvas.activeSelf)
            {
                if(inputsGO.activeSelf)
                    cancelEditFuret();
                    else
                    exitEditFuret();
            }
            else if (genealogyCanvas.activeSelf)
            {
                endGenealogy();
            }
            else
            {
                quitApp();
            }
        }
    }

    public void quitApp()
    {
        Application.Quit();
    }

    void initDropdownStatsTri()
    {
        List<string> stats = new List<string>();
        stats.Add("Tout");
        stats.Add("Sexe");
        stats.Add("Couleur");
        stats.Add("Année");
        triStats.ClearOptions();
        triStats.AddOptions(stats);
    }

    public void initListeFurets()
    {
        int nbre = 0;
        for (int i = 0; i < furets.Count; i++)
        {
            GameObject nouveau = Instantiate(furetPrefab, listeFuretsTransform, false) as GameObject;
            nouveau.GetComponent<Furet>().identite = furets[i];
            if(furets[i].mort || furets[i].autreElevage) 
                nouveau.SetActive(false);
            else
                nbre += 1;
        }
        texteTotal.text = "Total : " + nbre;
        bool interact = listeFuretsTransform.childCount == 0 ? false : true;
        buttonStats.interactable = interact;
    }

    void initDropdownTri()
    {
        List<string> couleurTri = new List<string>(couleurs);
        couleurTri[0] = "Toutes";
        triCouleur.ClearOptions();
        triCouleur.AddOptions(couleurTri);
    }

    string UppercaseFirst(string s)
    {
        if (string.IsNullOrEmpty(s))
            return string.Empty;
        return char.ToUpper(s[0]) + s.Substring(1);
    }

    public void openEditNotes() 
    {
        inputNoteFuret.text = curEditFuret.note;
        notesCanvas.SetActive(true);
    }
    public void cancelEditNotes()
    {
        notesCanvas.SetActive(false);
    }

    public void applyEditNotes() // curEditFuret
    {
        texteNoteFuret.text = curEditFuret.note = inputNoteFuret.text;
        verifSizeNote();
        notesCanvas.SetActive(false);
    }

    void verifSizeNote()
    {
        LayoutRebuilder.ForceRebuildLayoutImmediate(rectNotes);
        Canvas.ForceUpdateCanvases();
        float difference = rectNotes.sizeDelta.y - vectorNotesParent.y;
        if (difference <= 0)
        {
            rectNotesParent.sizeDelta = vectorNotesParent;
            rectFond.sizeDelta = vectorFond;
        }
        else if (difference > 0 && difference < 500)
        {
            texteNoteFuret.text = texteNoteFuret.text;
            rectNotesParent.sizeDelta = new Vector2(vectorNotesParent.x, vectorNotesParent.y + difference);
            rectFond.sizeDelta = new Vector2(vectorFond.x, vectorFond.y + difference);
        }
        else if (difference >= 500)
        {
            rectNotesParent.sizeDelta = new Vector2(vectorNotesParent.x, vectorNotesParent.y + 500);
            rectFond.sizeDelta = new Vector2(vectorFond.x, vectorFond.y + 500);
        }
        LayoutRebuilder.ForceRebuildLayoutImmediate(rectNotesParent);
        LayoutRebuilder.ForceRebuildLayoutImmediate(rectFond);
    }

    public void glidePanelTri()
    {
        panelTri.glide();
    }

    public void changeValueStats()
    {
        switch (triStats.value)
        {
            case 0:
                triStatsTout();
                break;
            case 1:
                triStatsSexe();
                break;
            case 2:
                triStatsCouleur();
                break;
            case 3:
                triStatsAnnee();
                break;
        }
    }

    public void openStatsUI()
    {
        try
        {
            changeValueStats();
        }
        catch (Exception ex)
        {
            GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = ex.Message;
        }
        statsCanvas.SetActive(true);
    }

    void triStatsTout()
    {
        int totalFurets = 0;
        List<furet> newList = new List<furet>();
        for (int i = 0; i < furets.Count;i++)
        {
            if(!furets[i].autreElevage)
                newList.Add(furets[i]);
        }
        Dictionary<string, int> annees = new Dictionary<string, int>();
        annees.Add("Inconnue", 0);
        List<int> sexes = new List<int>();
        sexes.Add(new int());
        sexes.Add(new int());
        sexes.Add(new int());
        Dictionary<string, int> couleursDict = new Dictionary<string, int>();
        for (int ii = 0; ii < couleurs.Count; ii++)
        {
            if (!couleursDict.ContainsKey(couleurs[ii]) && couleurs[ii] != "Aucune")
                couleursDict.Add(couleurs[ii], 0);
        }
        couleursDict.Add("Aucune", 0);

        for (int i = 0; i < newList.Count; i++)
        {
            totalFurets++;

            if (newList[i].dateNaissance != null && newList[i].dateNaissance.Length > 0)
            {
                string annee = newList[i].dateNaissance.Substring(newList[i].dateNaissance.Length - 2);
                if (annees.ContainsKey("20" + annee))
                    annees["20" + annee] += 1;
                else
                    annees.Add("20" + annee, 1);
            }
            else
            {
                if (annees.ContainsKey("Inconnue"))
                    annees["Inconnue"] += 1;
                else
                    annees.Add("Inconnue", 1);
            }
            // sexes
            switch (newList[i].sexe)
            {
                case 0:
                    sexes[0] += 1;
                    break;
                case 1:
                    sexes[1] += 1;
                    break;
                case 2:
                    sexes[2] += 1;
                    break;
            }
            // couleurs
            for (int ii = 0; ii < couleurs.Count; ii++)
            {
                if (!couleursDict.ContainsKey(couleurs[ii]))
                    couleursDict.Add(couleurs[ii], 0);
            }
            couleursDict[newList[i].couleur] += 1;
        }

        // total
        toutTotal.text = "Nombre total de furets : " + totalFurets;

        // dates
        StringBuilder anneesText = new StringBuilder();
        // string anneesText = "";
        if (annees["Inconnue"] == 0)
            annees.Remove("Inconnue");
        if (annees.Count > 0)
        {
            foreach (KeyValuePair<string, int> an in annees.OrderByDescending(pair => pair.Key))
            {
                if(an.Key != "Inconnue")
                {
                    float percentage = an.Value * 100 / totalFurets;
                    percentage = Mathf.Round(percentage * 100f) / 100f;
                    if (anneesText.ToString() != "")
                        anneesText.Append("\n" + an.Key + " : " + an.Value + " (" + percentage + "%)");
                    else
                        anneesText.Append(an.Key + " : " + an.Value + " (" + percentage + "%)");
                }
            }
            float percentage2 = annees["Inconnue"] * 100 / totalFurets;
            percentage2 = Mathf.Round(percentage2 * 100f) / 100f;
            anneesText.Append("\nInconnue : " + annees["Inconnue"] + " (" + percentage2 + "%)");
            toutAnnee.text = "<mark=#BABABA50><align=center><size=48><color=#0033FF>Années de naissance : </color></size><align=left></mark>\n\n" + anneesText;
        }
        else
            toutAnnee.text = "<mark=#BABABA50><align=center><size=48><color=#0033FF>Années de naissance inconnues </color></size><align=left></mark>\n\n";
        // sexes
        string sexesText = "";
        float percentageInconnu = sexes[0] * 100 / totalFurets;
        percentageInconnu = Mathf.Round(percentageInconnu * 100f) / 100f;
        float percentageMales = sexes[1] * 100 / totalFurets;
        percentageMales = Mathf.Round(percentageMales * 100f) / 100f;
        float percentageFemelles = sexes[2] * 100 / totalFurets;
        percentageFemelles = Mathf.Round(percentageFemelles * 100f) / 100f;
        sexesText = "<mark=#BABABA50><align=center><size=48><color=#0033FF>Sexes : </color></size><align=left></mark>\n\nMâles : " + sexes[1] + " (" + percentageMales + "%)\nFemelles : " + sexes[2] + " (" + percentageFemelles + "%)\nInconnu : " + sexes[0] + " (" + percentageInconnu + "%)";
        toutSexe.text = sexesText;

        // couleurs
        StringBuilder couleursText = new StringBuilder();
        // string couleursText = "";

        if (couleursDict.ContainsKey("Aucune"))
        {
            int integ = couleursDict["Aucune"];
            couleursDict.Remove("Aucune");
            couleursDict.Add("Inconnue", integ);
        }
        foreach (KeyValuePair<string, int> an in couleursDict)
        {
            // string trueValue = an.Key;
            float percentage = an.Value * 100 / totalFurets;
            percentage = Mathf.Round(percentage * 100f) / 100f;
            if (an.Value > 0) // on n'affiche pas la couleur s'il n'y a aucun représentant
                if (couleursText.ToString() != "")
                    couleursText.Append("\n" + an.Value + " : " + an.Value + " (" + percentage + "%)");
                else
                    couleursText.Append(an.Value + " : " + an.Value + " (" + percentage + "%)");
        }
        toutCouleur.text = "<mark=#BABABA50><align=center><size=48><color=#0033FF>Couleurs : </color></size><align=left></mark>\n\n" + couleursText;
        showStatsPanel(0);
    }
    void triStatsSexe()
    {
        int totalFurets = 0;
        int totalMales = 0;
        int totalFemelles = 0;
        int totalInconnus = 0;
        Dictionary<string, int> anneesMales = new Dictionary<string, int>();
        anneesMales.Add("Inconnue", 0);
        Dictionary<string, int> anneesFemelles = new Dictionary<string, int>();
        anneesFemelles.Add("Inconnue", 0);
        Dictionary<string, int> anneesInconnu = new Dictionary<string, int>();
        anneesInconnu.Add("Inconnue", 0);
        Dictionary<string, int> couleursDictMale = new Dictionary<string, int>();
        Dictionary<string, int> couleursDictFemelle = new Dictionary<string, int>();
        Dictionary<string, int> couleursDictInconnu = new Dictionary<string, int>();

        for (int ii = 0; ii < couleurs.Count; ii++)
        {
            string couleur = couleurs[ii];
            if (!couleursDictMale.ContainsKey(couleur) && couleur != "Aucune")
                couleursDictMale.Add(couleur, 0);
            if (!couleursDictFemelle.ContainsKey(couleur) && couleur != "Aucune")
                couleursDictFemelle.Add(couleur, 0);
            if (!couleursDictInconnu.ContainsKey(couleur) && couleur != "Aucune")
                couleursDictInconnu.Add(couleur, 0);
        }
        couleursDictMale.Add("Aucune", 0);
        couleursDictFemelle.Add("Aucune", 0);
        couleursDictInconnu.Add("Aucune", 0);

        List<furet> newList = new List<furet>();
        for (int i = 0; i < furets.Count; i++)
        {
            if (!furets[i].autreElevage)
                newList.Add(furets[i]);
        }
        
        for (int i = 0; i < newList.Count; i++)
        {
            totalFurets++;

            switch (newList[i].sexe)
            {
                case 0:
                    totalInconnus++;

                    if (!string.IsNullOrEmpty(newList[i].dateNaissance))
                        if (newList[i].dateNaissance.Length > 0)
                    {
                        string annee = newList[i].dateNaissance.Substring(newList[i].dateNaissance.Length - 2);
                        if (anneesInconnu.ContainsKey("20" + annee))
                            anneesInconnu["20" + annee] += 1;
                        else
                            anneesInconnu.Add("20" + annee, 1);
                    }
                    else
                    {
                        if (anneesInconnu.ContainsKey("Inconnue"))
                            anneesInconnu["Inconnue"] += 1;
                        else
                            anneesInconnu.Add("Inconnue", 1);
                    }
                    couleursDictInconnu[newList[i].couleur] += 1;
                    break;
                case 1:
                    totalMales++;
                    if (!string.IsNullOrEmpty(newList[i].dateNaissance))
                        if (newList[i].dateNaissance.Length > 0)
                    {
                        string annee = newList[i].dateNaissance.Substring(newList[i].dateNaissance.Length - 2);
                        if (anneesMales.ContainsKey("20" + annee))
                            anneesMales["20" + annee] += 1;
                        else
                            anneesMales.Add("20" + annee, 1);
                    }
                    else
                    {
                        if (anneesMales.ContainsKey("Inconnue"))
                            anneesMales["Inconnue"] += 1;
                        else
                            anneesMales.Add("Inconnue", 1);
                    }
                    couleursDictMale[newList[i].couleur] += 1;
                    break;
                case 2:
                    totalFemelles++;
                    if (!string.IsNullOrEmpty(newList[i].dateNaissance))
                        if (newList[i].dateNaissance.Length > 0)
                    {
                        string annee = newList[i].dateNaissance.Substring(newList[i].dateNaissance.Length - 2);
                        if (anneesFemelles.ContainsKey("20" + annee))
                            anneesFemelles["20" + annee] += 1;
                        else
                            anneesFemelles.Add("20" + annee, 1);
                    }
                    else
                    {
                        if (anneesFemelles.ContainsKey("Inconnue"))
                            anneesFemelles["Inconnue"] += 1;
                        else
                            anneesFemelles.Add("Inconnue", 1);
                    }
                    couleursDictFemelle[newList[i].couleur] += 1;
                    break;
            }
        }
        // MÂLES
        // total
        if (totalMales > 0)
        {
            StringBuilder totalMalesText = new StringBuilder();
            // string totalMalesText = "";
            totalMalesText.Append("<mark=#BABABA50><align=center><size=48><color=#0033FF>Mâles : " + totalMales + " (" + (Mathf.Round(totalMales * 100 / totalFurets * 100f) / 100f) + "%)</color></size><align=left></mark>\n\n<b>Années : </b>");
            // dates
            if (anneesMales["Inconnue"] == 0)
                anneesMales.Remove("Inconnue");
            foreach (KeyValuePair<string, int> an in anneesMales.OrderByDescending(pair => pair.Key))
            {
                float percentage = an.Value * 100 / totalMales;
                percentage = Mathf.Round(percentage * 100f) / 100f;
                totalMalesText.Append("\n" + an.Key + " : " + an.Value + " (" + percentage + "%)");
            }
            totalMalesText.Append("\n<b>Couleurs : </b>");
            // couleurs
            foreach (KeyValuePair<string, int> an in couleursDictMale)
            {
                float percentage = an.Value * 100 / totalMales;
                percentage = Mathf.Round(percentage * 100f) / 100f;
                string value = an.Key;
                if (an.Key == "Aucune")
                    value = "Inconnue";
                if (an.Value > 0) // on n'affiche pas la couleur s'il n'y a aucun représentant
                    totalMalesText.Append("\n" + value + " : " + an.Value + " (" + percentage + "%)");
            }
            maleTotal.text = totalMalesText.ToString();
        }
        else
        {
            maleTotal.text = "<size=48><color=#0033FF>Pas de mâle</color></size>";
        }

        // FEMELES
        // total
        if (totalFemelles > 0)
        {
            StringBuilder totalFemellesText = new StringBuilder();
            // string totalFemellesText = "";
            totalFemellesText.Append("<mark=#BABABA50><align=center><size=48><color=#CD05BB>Femelles : " + totalFemelles + " (" + (Mathf.Round(totalFemelles * 100 / totalFurets * 100f) / 100f) + "%)</color></size><align=left></mark>\n\n<b>Années : </b>");
            // dates
            if (anneesFemelles["Inconnue"] == 0)
                anneesFemelles.Remove("Inconnue");
            foreach (KeyValuePair<string, int> an in anneesFemelles.OrderByDescending(pair => pair.Key))
            {
                float percentage = an.Value * 100 / totalFemelles;
                percentage = Mathf.Round(percentage * 100f) / 100f;
                totalFemellesText.Append("\n" + an.Key + " : " + an.Value + " (" + percentage + "%)");
            }
            totalFemellesText.Append("\n<b>Couleurs : </b>");
            // couleurs
            foreach (KeyValuePair<string, int> an in couleursDictFemelle)
            {
                float percentage = an.Value * 100 / totalFemelles;
                percentage = Mathf.Round(percentage * 100f) / 100f;
                string value = an.Key;
                if (an.Key == "Aucune")
                    value = "Inconnue";
                if (an.Value > 0) // on n'affiche pas la couleur s'il n'y a aucun représentant
                    totalFemellesText.Append("\n" + value + " : " + an.Value + " (" + percentage + "%)");
            }
            femelleTotal.text = totalFemellesText.ToString();
        }
        else
        {
            femelleTotal.text = "<size=48><color=#CD05BB>Pas de femelle</color></size>";
        }

        // INCONNUS
        // total
        if (totalInconnus > 0)
        {
            StringBuilder totalInconnuText = new StringBuilder();
            // string totalInconnuText = "";
            totalInconnuText.Append("<mark=#BABABA50><align=center><size=48><color=#ffffaa>Sexe inconnu : " + totalInconnus + " (" + (Mathf.Round(totalInconnus * 100 / totalFurets * 100f) / 100f) + "%)</color></size><align=left></mark>\n\n<b>Années : </b>");
            // dates
            if (anneesInconnu["Inconnue"] == 0)
                anneesInconnu.Remove("Inconnue");
            foreach (KeyValuePair<string, int> an in anneesInconnu.OrderByDescending(pair => pair.Key))
            {
                float percentage = an.Value * 100 / totalInconnus;
                percentage = Mathf.Round(percentage * 100f) / 100f;
                totalInconnuText.Append("\n" + an.Key + " : " + an.Value + " (" + percentage + "%)");
            }
            totalInconnuText.Append("\n<b>Couleurs : </b>");
            // couleurs
            foreach (KeyValuePair<string, int> an in couleursDictInconnu)
            {
                float percentage = an.Value * 100 / totalInconnus;
                percentage = Mathf.Round(percentage * 100f) / 100f;
                string value = an.Key;
                if (an.Key == "Aucune")
                    value = "Inconnue";
                if (an.Value > 0) // on n'affiche pas la couleur s'il n'y a aucun représentant
                    totalInconnuText.Append("\n" + value + " : " + an.Value + " (" + percentage + "%)");
            }
            inconnuTotal.text = totalInconnuText.ToString();
        }
        else
            inconnuTotal.text = "";

        showStatsPanel(1);
    }

    class ParCouleur
    {
        public string couleur;
        public int total;
        public int inconnus;
        public int males;
        public int femelles;
        public Dictionary<string,int> annees;
    }
    void triStatsCouleur()
    {
        List<ParCouleur> parCouleur = new List<ParCouleur>();
        int totalFurets = 0;
        for (int ii = 0; ii < couleurs.Count; ii++)
        {
            parCouleur.Add(new ParCouleur());
            parCouleur[ii].couleur = couleurs[ii];
            parCouleur[ii].annees = new Dictionary<string, int>();
            parCouleur[ii].annees.Add("Inconnue", 0);
        }

        List<furet> newList = new List<furet>();
        for (int i = 0; i < furets.Count; i++)
        {
            if (!furets[i].autreElevage)
                newList.Add(furets[i]);
        }

        for (int i = 0; i < newList.Count; i++)
        {
            totalFurets++;
            int index = couleurs.FindIndex(d => d == newList[i].couleur);
            // total
            ParCouleur couleur = parCouleur[index];
            couleur.total++;
            // sexe
            switch (newList[i].sexe)
            {
                case 0:
                    couleur.inconnus++;
                    break;
                case 1:
                    couleur.males++;
                    break;
                case 2:
                    couleur.femelles++;
                    break;
            }
            // année
            string annee = "Inconnue";
            if (newList[i].dateNaissance != null && newList[i].dateNaissance != "")
            if (newList[i].dateNaissance.Length>=2)
            annee = newList[i].dateNaissance.Substring(newList[i].dateNaissance.Length - 2);
            if (couleur.annees.ContainsKey(annee))
                couleur.annees[annee]++;
            else
                couleur.annees.Add(annee, 1);
            
        }

        parCouleur.Sort((p1, p2) => p1.couleur.CompareTo(p2.couleur));
        for (int i = 0;i< parCouleur.Count;i++)
        if (parCouleur[i].couleur == "Aucune") // on met Inconnue à la fin si ça existe
        {
            ParCouleur item = parCouleur[i];
            parCouleur.RemoveAt(i);
            parCouleur.Insert(parCouleur.Count, item);
                break;
        }
        StringBuilder totalCouleurText = new StringBuilder();
        // string totalCouleurText = "";
        for (int i = 0; i < parCouleur.Count; i++)
        {
            ParCouleur couleur = parCouleur[i];
            int total = couleur.total;
            if (total > 0)
            {
                float percentage = total * 100 / totalFurets;
                percentage = Mathf.Round(percentage * 100f) / 100f;
                float percentageM = couleur.males * 100 / total;
                percentageM = Mathf.Round(percentageM * 100f) / 100f;
                float percentageF = couleur.femelles * 100 / total;
                percentageF = Mathf.Round(percentageF * 100f) / 100f;
                float percentageI = couleur.inconnus * 100 / total;
                percentageI = Mathf.Round(percentageI * 100f) / 100f;
                int nbreAnnees = couleur.annees.Count;
                if (couleur.couleur == "Aucune")
                    couleur.couleur = "Couleur inconnue";

                totalCouleurText.Append("<mark=#BABABA50><align=center><size=48><color=#0033FF>" + couleur.couleur + " : " +
                    // sexes
                    total + " (" + percentage + "%)</color></size><align=left></mark>\n\n<b>Total : </b>\nMâles : " + couleur.males + " (" + percentageM + "%)\nFemelles : " + couleur.femelles + " (" + percentageF + "%)\nInconnu : " + couleur.inconnus + " (" + percentageI + "%)\n");

                // années
                var mySortedList = couleur.annees.OrderBy(d => d.Key).ToList();
                if (mySortedList[0].Key == "Inconnue")
                {
                    KeyValuePair< string,int> keyValuePair = new KeyValuePair<string, int>(mySortedList[0].Key, mySortedList[0].Value);
                    mySortedList.RemoveAt(0);
                    mySortedList.Add(keyValuePair);
                }
                couleur.annees = new Dictionary<string, int>( mySortedList.ToDictionary(x => x.Key, x => x.Value));
                StringBuilder parAnnee = new StringBuilder();
                parAnnee.Append("<b>Années : </b>");
                foreach (KeyValuePair<string, int> an in couleur.annees.OrderByDescending(pair => pair.Key))
                {
                    float percentageA = an.Value * 100 / total;
                    percentageA = Mathf.Round(percentageA * 100f) / 100f;
                    if (an.Key == "Inconnue")
                    {
                        if (an.Value>0)
                        parAnnee.Append("\n" + an.Key + " : " + an.Value + " (" + percentageA + "%)");
                    }
                    else
                        parAnnee.Append("\n20" + an.Key + " : " + an.Value + " (" + percentageA + "%)");
                }
                totalCouleurText.Append(parAnnee + "\n\n");
            }
        }

        totalCouleur.text = totalCouleurText.ToString();
        showStatsPanel(2);
    }

    class ParAnnee
    {
        public string annee;
        public int total;
        public int males;
        public int femelles;
        public int inconnus;
        public List<AnneeCouleur> couleur;
    }
    class AnneeCouleur
    {
        public string couleur;
        public int total;
        public int males;
        public int femelles;
        public int inconnus;
    }
    void triStatsAnnee()
    {
        int totalFurets = 0;
        List<ParAnnee> parAnnee = new List<ParAnnee>();
        parAnnee.Add(new ParAnnee());
        parAnnee[0].annee = "Année inconnue";
        parAnnee[0].couleur = new List<AnneeCouleur>();
        for (int ii = 0; ii < couleurs.Count; ii++)
        {
            parAnnee[0].couleur.Add(new AnneeCouleur());
            parAnnee[0].couleur[ii].couleur = couleurs[ii];
        }

        List<furet> newList = new List<furet>();
        for (int i = 0; i < furets.Count; i++)
        {
            if (!furets[i].autreElevage)
                newList.Add(furets[i]);
        }

        for (int i = 0; i < newList.Count; i++)
        {
            totalFurets++;
            string annee = "";
            furet fur = newList[i];
            if (fur.dateNaissance != null && fur.dateNaissance != "")
                if (fur.dateNaissance.Length >= 2)
                    annee = fur.dateNaissance.Substring(fur.dateNaissance.Length - 2);
                else
                    annee = "Année inconnue";
            else
                annee = "Année inconnue";
            bool isTrue = false;
            for (int o = 0; o < parAnnee.Count; o++) // pour chaque année
            {
                if (parAnnee[o].annee == annee) // si le furet est d'une année existante
                {
                    isTrue = true;
                    parAnnee[o].total++;
                    switch (fur.sexe)
                    {
                        case 0:
                            parAnnee[o].inconnus++;
                            break;
                        case 1:
                            parAnnee[o].males++;
                            break;
                        case 2:
                            parAnnee[o].femelles++;
                            break;
                    }
                    for (int p = 0;p< parAnnee[o].couleur.Count; p++)
                    {
                        AnneeCouleur catCouleur = parAnnee[o].couleur[p];
                        if (fur.couleur == catCouleur.couleur)
                        {
                            if (catCouleur.couleur == "Aucune")
                                catCouleur.couleur = "Couleur inconnue";
                            catCouleur.total++;
                            switch (fur.sexe)
                            {
                                case 0:
                                    catCouleur.inconnus++;
                                    break;
                                case 1:
                                    catCouleur.males++;
                                    break;
                                case 2:
                                    catCouleur.femelles++;
                                    break;
                            }
                        }
                    }
                    break; // si on trouve l'année, pas besoin de continuer le loop
                }
            }
            if (!isTrue) // si le furet n'a pas d'année enregistrée
            {
                parAnnee.Add(new ParAnnee());
                int maxAnnee = parAnnee.Count - 1;
                ParAnnee catAnnee = parAnnee[maxAnnee];
                catAnnee.annee = annee;
                catAnnee.couleur = new List<AnneeCouleur>();
                for (int ii = 0; ii < couleurs.Count; ii++)
                {
                    catAnnee.couleur.Add(new AnneeCouleur());
                    catAnnee.couleur[ii].couleur = couleurs[ii];
                }
                catAnnee.total++;
                switch (newList[i].sexe)
                {
                    case 0:
                        catAnnee.inconnus++;
                        break;
                    case 1:
                        catAnnee.males++;
                        break;
                    case 2:
                        catAnnee.femelles++;
                        break;
                }
                for (int p = 0; p < catAnnee.couleur.Count; p++)
                {
                    AnneeCouleur catCouleur = catAnnee.couleur[p];
                    if (newList[i].couleur == catCouleur.couleur)
                    {
                        if (catCouleur.couleur == "Aucune")
                            catCouleur.couleur = "Couleur inconnue";
                        catCouleur.total++;
                        switch (newList[i].sexe)
                        {
                            case 0:
                                catCouleur.inconnus++;
                                break;
                            case 1:
                                catCouleur.males++;
                                break;
                            case 2:
                                catCouleur.femelles++;
                                break;
                        }
                    }
                }
            }
        }

        parAnnee.Sort((p2, p1) => p1.annee.CompareTo(p2.annee)); // on trie la liste, de façon à avoir les plus récentes années en premier
        if (parAnnee[0].annee == "Année inconnue") // on met Inconnue à la fin si ça existe
        {
            ParAnnee item = parAnnee[0];
            parAnnee.RemoveAt(0);
            parAnnee.Insert(parAnnee.Count, item);
        }

        // string totalAnneeText = "";
        StringBuilder texte = new StringBuilder();
        for (int i = 0; i < parAnnee.Count; i++) // pour chaque année
        {
            if (parAnnee[i].total > 0)
            {
                ParAnnee catAnnee = parAnnee[i];
                //Debug.Log("année : " + parAnnee[i].annee + " / total : " + parAnnee[i].total);
                // string texte;
                float percentage = catAnnee.total * 100 / totalFurets;
                percentage = Mathf.Round(percentage * 100f) / 100f;
                float percentageM = catAnnee.males * 100 / catAnnee.total;
                percentageM = Mathf.Round(percentageM * 100f) / 100f;
                float percentageF = catAnnee.femelles * 100 / catAnnee.total;
                percentageF = Mathf.Round(percentageF * 100f) / 100f;
                float percentageI = catAnnee.inconnus * 100 / catAnnee.total;
                percentageI = Mathf.Round(percentageI * 100f) / 100f;

                // sexes
                if (catAnnee.annee != "Année inconnue")
                texte.Append("<mark=#BABABA50><align=center><size=48><color=#0033FF>20" + catAnnee.annee + " : " + catAnnee.total + " (" + percentage + "%)</color></size><align=left></mark>\n\n<b>Total : </b>\nMâles : " + catAnnee.males + " (" + percentageM + "%)\nFemelles : " + catAnnee.femelles + " (" + percentageF + "%)\nInconnu : " + catAnnee.inconnus + " (" + percentageI + "%)\n");
                else
                    texte.Append("<mark=#BABABA50><align=center><size=48><color=#0033FF>" + catAnnee.annee + " : " + catAnnee.total + " (" + percentage + "%)</color></size><align=left></mark>\n\n<b>Total : </b>\nMâles : " + catAnnee.males + " (" + percentageM + "%)\nFemelles : " + catAnnee.femelles + " (" + percentageF + "%)\nInconnu : " + catAnnee.inconnus + " (" + percentageI + "%)\n");

                // couleurs
                catAnnee.couleur.Sort((p2, p1) => p1.couleur.CompareTo(p2.couleur)); // on trie la liste, de façon à avoir les plus récentes années en premier

                for (int p = 0;p< catAnnee.couleur.Count; p++)
                {
                    AnneeCouleur item = catAnnee.couleur[p];
                    //Debug.Log("couleur : " + parAnnee[i].couleur[p].couleur);
                    if (item.couleur == "Aucune" || item.couleur =="Couleur inconnue") // on met Inconnue à la fin si ça existe
                    {
                        catAnnee.couleur.RemoveAt(p);
                        catAnnee.couleur.Insert(catAnnee.couleur.Count, item);
                        break;
                    }
                }
                for (int o = 0; o < catAnnee.couleur.Count; o++) // pour chaque couleur
                {
                    AnneeCouleur catCouleur = catAnnee.couleur[o];
                    if (catCouleur.total > 0)
                    {
                        float percentageCM = catCouleur.males * 100 / catCouleur.total;
                        percentageCM = Mathf.Round(percentageCM * 100f) / 100f;
                        float percentageCF = catCouleur.femelles * 100 / catCouleur.total;
                        percentageCF = Mathf.Round(percentageCF * 100f) / 100f;
                        float percentageCI = catCouleur.inconnus * 100 / catCouleur.total;
                        percentageCI = Mathf.Round(percentageCI * 100f) / 100f;
                        if (catCouleur.total > 0) // total, mâles, femelles, inconnus pour chaque couleur (avec pourcentages)
                        {
                            string trueColor = catCouleur.couleur;
                            if (trueColor == "Aucune")
                                trueColor = "Couleur inconnue";
                            texte.Append("<b><color=#ffffaa>" + trueColor + " : </color></b>" + catCouleur.total + "\nMâles : " + catCouleur.males + " (" + percentageCM + "%)\nFemelles : " + catCouleur.femelles + " (" + percentageCF + "%)\nInconnu : " + catCouleur.inconnus + " (" + percentageCI + "%)\n");
                        }
                    }
                }
                // texte.Insert(0, totalAnneeText);
                texte.Append("\n");
                // totalAnneeText = totalAnneeText + texte + "\n";
            }

        }

        totalAnnee.text = texte.ToString();
        showStatsPanel(3);
    }

    void showStatsPanel(int index)
    {
        for (int i = 0; i < statsGo.Length;i++)
        {
            bool isTrue = i == index ? true : false;
            statsGo[i].SetActive(isTrue);
        }
    }


    public void buttonRetourStats()
    {
        statsCanvas.SetActive(false);
    }


    public void resetAnneeRecherche()
    {
        inputAnneeRecherche.text = "";
    }
    public void resetNumPuceRecherche()
    {
        inputNumPuceRecherche.text = "";
    }

    public void resetRecherche()
    {
        inputRecherche.text = "";
        showRecherche();
        //reinitListFurets();
    }

    public void selectRecherche()
    {
        curTri = new List<GameObject>();
        for (int i = 0; i < furets.Count; i++)
        {
            if (listeFuretsTransform.transform.GetChild(i).gameObject.activeSelf)
            curTri.Add(listeFuretsTransform.transform.GetChild(i).gameObject);
        }
    }

    public void showRecherche()
    {
        int nbre = 0;
        if(curTri == null) return;
        if (curTri.Count > 0)
        {
            string texte = inputRecherche.text;
            for (int i = 0; i < curTri.Count; i++)
            {
                if (curTri[i].GetComponent<Furet>().identite.nom.Contains(texte) || curTri[i].GetComponent<Furet>().identite.nom.Contains(UppercaseFirst(texte)))
                {
                    nbre++;
                    curTri[i].SetActive(true);
                }
                else
                    curTri[i].SetActive(false);
            }
        }
        texteTotal.text = "Total : " + nbre;
    }
    
    void createPhotosFolder()
    {
        if (!Directory.Exists(fullPath))
            Directory.CreateDirectory(fullPath);
    }
    
    public void showPhotosFolder()
    {
        createPhotosFolder();
        Process.Start(fullPath);
    }
    

    public void applyGen(int genNbr)
    {
        if(genNumber<genNbr)
            genNumber = genNbr;
    }

    public int genNumber;
    [SerializeField] Transform firstGenGO;
    public void newGenealogy(furet fur)
    {
        // ici on entre juste l'identité du premier furet avec applyIdentite(), le reste se fait à partir de cette méthode
        
        
        FurGenealogie baseFur = baseFuret.GetComponent<FurGenealogie>();
        if (fur != null)
        {
            baseFur.identite = fur;
            baseFur.applyIdentite(0);
            firstGenGO.localPosition = new Vector3(0, 50+100*(6-genNumber), 0);
            // print(genNumber);
        }
        genealogyCanvas.SetActive(true);
    }
    
    public void clickFuretGen(string furName)
    {
        editCanvas.GetComponent<Canvas>().sortingOrder = 7;
        furet furGen = furets.Find(x => x.nom == furName);
        int index = furets.IndexOf(furGen);
        resetFicheFuret();
        enableEditFuret(furGen, index);
    }

    public void buttonGenealogy()
    {
        editCanvas.GetComponent<Canvas>().sortingOrder = 1;
        newGenealogy(curEditFuret);
    }

    public void endGenealogy()
    {
        genealogyCanvas.SetActive(false);
    }
    
    public void openPhotoFuret()
    {
        string furetPath = Path.Combine(fullPath, curEditFuret.nom + ".jpg");
        if(File.Exists(furetPath))
            Process.Start(furetPath);
        else
            popup.fading("Ce furet n'a pas de photo");
    }

    public void takeScreenshot()
    {
        StartCoroutine(screenshoted());
    }

    IEnumerator screenshoted()
    {
        string folderPath = Application.dataPath + "/GénéalogieScreenshots/";
        interfaceScreenshot.SetActive(false);
        yield return new WaitForEndOfFrame();
        var texture = ScreenCapture.CaptureScreenshotAsTexture();
        texture.Apply();
        SaveImageToGallery(texture, baseFuret.transform.GetChild(0).GetComponent<TMP_Text>().text, "Saving photo to android");
        Invoke("endScreenshot", 0.1f);
    }


    private static AndroidJavaObject _activity;
    private const string MediaStoreImagesMediaClass = "android.provider.MediaStore$Images$Media";

    public static string SaveImageToGallery(Texture2D texture2D, string title, string description)
    {
        if(Application.platform == RuntimePlatform.Android)
        {
            using (var mediaClass = new AndroidJavaClass(MediaStoreImagesMediaClass))
            {
                using (var cr = Activity.Call<AndroidJavaObject>("getContentResolver"))
                {
                    var image = Texture2DToAndroidBitmap(texture2D);
                    var imageUrl = mediaClass.CallStatic<string>("insertImage", cr, image, title, description);
                    return imageUrl;
                }
            }
        }else{
            string path = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);
            ScreenCapture.CaptureScreenshot(System.IO.Path.Combine(path,title + ".png"));
            return title;
        }
    }

    public static AndroidJavaObject Texture2DToAndroidBitmap(Texture2D texture2D)
    {
        byte[] encoded = texture2D.EncodeToPNG();
        using (var bf = new AndroidJavaClass("android.graphics.BitmapFactory"))
        {
            return bf.CallStatic<AndroidJavaObject>("decodeByteArray", encoded, 0, encoded.Length);
        }
    }
    public static AndroidJavaObject Activity
    {
        get
        {
            if (_activity == null)
            {
                var unityPlayer = new AndroidJavaClass("com.unity3d.player.UnityPlayer");
                _activity = unityPlayer.GetStatic<AndroidJavaObject>("currentActivity");
            }
            return _activity;
        }
    }


    void endScreenshot()
    {
        interfaceScreenshot.SetActive(true);
        popup.fading("Capture d'écran terminée");
    }

    public void resetTri()
    {
        buttonTriAll();
        inputAnneeRecherche.text = inputNumPuceRecherche.text = inputRecherche.text = "";
        triCouleur.value = 0;
        triAutreElevage.isOn = triMort.isOn = false;
        curTri = new List<GameObject>();
        reinitListFurets();
    }

    void reinitListFurets()
    {
        int nbre = 0;
        curTri = new List<GameObject>();
        for (int i = 0; i < furets.Count; i++)
        {
            GameObject obj = listeFuretsTransform.transform.GetChild(i).gameObject;
            curTri.Add(obj);
            bool afficher = furets[i].mort || furets[i].autreElevage ? true : false;
            obj.SetActive(!afficher);
            if(!afficher) nbre++;
        }
        texteTotal.text = "Total : " + nbre;
    }

    [SerializeField] GameObject triTousChild;
    [SerializeField] GameObject triMaleChild;
    [SerializeField] GameObject triFemelleChild;
    [SerializeField] Image triTousImg;
    [SerializeField] Image triMaleImg;
    [SerializeField] Image triFemelleImg;
    IEnumerator triFuret(furet fur, GameObject go)
    {
        if ((inputNumPuceRecherche.text == "" || inputNumPuceRecherche.text == null) || ((fur.numPuce != "" || fur.numPuce != null) && (fur.numPuce != null && fur.numPuce.Contains(inputNumPuceRecherche.text))))
        {
            if (triCouleur.options[triCouleur.value].text == fur.couleur || triCouleur.value == 0) // si la couleur du furet correspond à la valeur du dropdown ou bien à la valeur "Toutes"
            {
                if ((inputAnneeRecherche.text == "" || inputAnneeRecherche.text == null) || (fur.dateNaissance != null || fur.dateNaissance != "") && (fur.dateNaissance != null && fur.dateNaissance.Contains(inputAnneeRecherche.text)))
                {
                    if ((fur.sexe == 0 && triTousChild.activeSelf) || // si le sexe n'a pas d'importance
                        (fur.sexe == 1 && (triMaleChild.activeSelf || triTousChild.activeSelf)) || // si on cherche un mâle ou tout
                        (fur.sexe == 2 && (triFemelleChild.activeSelf || triTousChild.activeSelf))) // si on cherche une femelle ou tout
                    {
                        if (fur.mort == triMort.isOn) // si le furet est mort ou non
                        {
                            if(fur.autreElevage == triAutreElevage.isOn)
                            {
                                curTri.Add(go);
                                go.SetActive(true);
                            }
                            else
                                go.SetActive(false);
                        }
                        else
                            go.SetActive(false);
                    }
                    else
                        go.SetActive(false);
                }
                else
                    go.SetActive(false);
            }
            else
                go.SetActive(false);
        }
        else
            go.SetActive(false);
        yield return null;
    }

    public void trierFurets()
    {
        listeScrollBar.value = 0;
        listeFuretsTransform.localPosition = Vector2.zero;
        inputRecherche.text = "";
        curTri = new List<GameObject>();
        // trier par mort, couleur, sexe
        for (int i = 0; i < furets.Count; i++)
        {
            StartCoroutine(triFuret(furets[i], listeFuretsTransform.transform.GetChild(i).gameObject));
        }
        texteTotal.text = "Total : " + curTri.Count;
    }

    public void buttonTriAll()
    {
        triMaleImg.color = greyColor;
        triFemelleImg.color = greyColor;
        triTousImg.color = Color.white;
        triMaleChild.SetActive(false);
        triFemelleChild.SetActive(false);
        triTousChild.SetActive(true);
    }
    public void buttonTriMale()
    {
        triMaleImg.color = Color.white;
        triFemelleImg.color = greyColor;
        triTousImg.color = greyColor;
        triFemelleChild.SetActive(false);
        triTousChild.SetActive(false);
        triMaleChild.SetActive(true);
    }
    public void buttonTriFemelle()
    {
        triMaleImg.color = greyColor;
        triFemelleImg.color = Color.white;
        triTousImg.color = greyColor;
        triMaleChild.SetActive(false);
        triTousChild.SetActive(false);
        triFemelleChild.SetActive(true);
    }

    public void disableEditFuret()
    {
        editCanvas.SetActive(false);
    }
    public void enableEditFuret(furet fur, int index)
    {
        if (fur.pere != "" || fur.mere != "")
            boutonGenealogy.SetActive(true);
        else
            boutonGenealogy.SetActive(false);
        headerEdit.text = "Informations";
        inputsGO.SetActive(false);
        textesGO.SetActive(true);
        buttonDelete.SetActive(true);
        nouveauFuret = false;
        indexCurEditFuret = index;
        curEditFuret = fur;
        
        switch (fur.sexe)
        {
            case 0:
                sexeImage.sprite = inconnuSprite;
                break;
            case 1:
                sexeImage.sprite = maleSprite;
                buttonMale();
                break;
            case 2:
                sexeImage.sprite = femelleSprite;
                buttonFemelle();
                break;
        }
        texteNomFuret.text = inputNomFuret.text = fur.nom;
        if (texteNomFuret.text == "")
            texteNomFuret.text = "<color=#aa0000><i>Pas de nom</i></color>";
        if (string.IsNullOrEmpty(fur.note))
            texteNoteFuret.text = "Aucune note";
        else
        {
            texteNoteFuret.text = inputNoteFuret.text = fur.note;
        }
        inputCouleurFuret.value = couleurs.FindIndex(d => d == fur.couleur);
        texteCouleurFuret.text = fur.couleur;
        if (texteCouleurFuret.text == "Aucune")
            texteCouleurFuret.text = "<color=#aa0000><i>Aucune</i></color>";
        toggleMort.isOn = fur.mort;
        if (fur.mort)
            texteMort.text = "<color=#aa0000><i>Décédé</i></color>";
        else
            texteMort.text = "";
        toggleAutreElevage.isOn = fur.autreElevage;
        if (fur.autreElevage)
            texteAutreElevage.text = "<color=#aa0000><i>(autre élevage)</i></color>";
        else
            texteAutreElevage.text = "";
        if (fur.provenance != "" && fur.provenance != null)
            texteProvenanceFuret.text = inputProvenanceFuret.text = fur.provenance;
            else
            texteProvenanceFuret.text = "<color=#aa0000><i>Provenance inconnue</i></color>";
        if (fur.numPuce != "" && fur.numPuce != null)
            texteNumPuce.text = inputNumPuce.text = fur.numPuce;
        else
            texteNumPuce.text = "<color=#aa0000><i>Inconnu</i></color>";
        DateTime dDate;
        if (DateTime.TryParse(fur.dateNaissance, out dDate))
        {
            texteDateFuret.text = fur.dateNaissance;
            inputDateDayFuret.text = dDate.ToString("dd");
            inputDateMonthFuret.text = dDate.ToString("MM");
            inputDateYearFuret.text = dDate.ToString("yyyy");
        }
        else
            texteDateFuret.text = "<color=#aa0000><i>Inconnue</i></color>";
        if (texteDateFuret.text == "")
            texteDateFuret.text = "<color=#aa0000><i>Inconnue</i></color>";
        textePereFuret.text = inputPereFuret.text = fur.pere;
        if (textePereFuret.text == "")
            textePereFuret.text = "<color=#aa0000><i>Inconnu</i></color>";
        furet papa = furets.Find(x => x.nom == inputPereFuret.text);
        if (papa != null)
            textePereFuret.color = new Color(0, 0, 0.35f,1);
        else
            textePereFuret.color = Color.black;
        texteMereFuret.text = inputMereFuret.text = fur.mere;
        if (texteMereFuret.text == "")
            texteMereFuret.text = "<color=#aa0000><i>Inconnue</i></color>";
        furet maman = furets.Find(x => x.nom == inputMereFuret.text);
        if (maman != null)
            texteMereFuret.color = new Color(0, 0, 0.35f, 1);
        else
            texteMereFuret.color = Color.black;
        searchChilds(fur.nom);
        if (fur.enfants.Count > 0)
        {
            List<string> dates = new List<string>();
            for (int i = 0;i< fur.enfants.Count; i++)
            {
                furet petit = furets.Find(x => x.nom == fur.enfants[i]);
                if (!dates.Contains(petit.dateNaissance))
                    dates.Add(petit.dateNaissance);
            }
            if (dates.Count>1)
            texteEnfants.text = "<color=#000059>Nombre de petits : " + fur.enfants.Count + " (" + dates.Count + " portées)</color>";
            else
            texteEnfants.text = "<color=#000059>Nombre de petits : " + fur.enfants.Count + " (" + dates.Count + " portée)</color>";
        }
        else
            texteEnfants.text = "Pas de petit";
        editCanvas.SetActive(true);
        verifSizeNote();
    }

    public void editFuret()
    {
        headerEdit.text = "Modifier un furet";
        boutonGenealogy.SetActive(false);
        textesGO.SetActive(false);
        inputsGO.SetActive(true);
        buttonDelete.SetActive(true);
    }

    public void cancelEditFuret()
    {
        if (!nouveauFuret)
        {
            cancelFuret();
        }
        else
        {
            exitEditFuret();
        }
    }
    
    void cancelFuret()
    {
        headerEdit.text = "Informations";
        if (curEditFuret.pere != "" || curEditFuret.mere != "")
            boutonGenealogy.SetActive(true);
        else
            boutonGenealogy.SetActive(false);
        textesGO.SetActive(true);
        inputsGO.SetActive(false);
    }


    public void buttonNouveauFuret()
    {
        boutonGenealogy.SetActive(false);
        headerEdit.text = "Nouveau furet";
        textesGO.SetActive(false);
        inputsGO.SetActive(true);
        curEditFuret = new furet();
        nouveauFuret = true;
        editCanvas.SetActive(true);
        buttonDelete.SetActive(false);
    }

    Color greyColor = new Color(0.8f, 0.8f, 0.8f, 1);
    void setSexToZero()
    {
        sexe = 0;
        femelleImg.color = greyColor;
        maleImg.color = greyColor;
        femelleChild.SetActive(false);
        maleChild.SetActive(false);
    }

    public void buttonMale()
    {
        if (sexe != 1)
        {
            femelleImg.color = greyColor;
            maleImg.color = Color.white;
            sexe = 1;
            femelleChild.SetActive(false);
            maleChild.SetActive(true);
        }
        else
            setSexToZero();
    }
    public void buttonFemelle()
    {
        if (sexe != 2)
        {
            femelleImg.color = Color.white;
            maleImg.color = greyColor;
            sexe = 2;
            maleChild.SetActive(false);
            femelleChild.SetActive(true);
        }
        else
            setSexToZero();
    }
    
    public void editDateDay()
    {
        if(inputDateDayFuret.text.Length == 2)
        {
            EventSystem.current.SetSelectedGameObject(inputDateMonthFuret.gameObject, null);
            inputDateMonthFuret.OnPointerClick(new PointerEventData(EventSystem.current));
        }
    }
    public void editDateMonth()
    {
        if (inputDateMonthFuret.text.Length == 2)
        {
            EventSystem.current.SetSelectedGameObject(inputDateYearFuret.gameObject, null);
            inputDateYearFuret.OnPointerClick(new PointerEventData(EventSystem.current));
        }
    }

    public void buttonAccepterEdit()
    {
        // si le nom existe déjà, ne pas faire ce code et demander de changer (montrer quel furet porte ce nom ?)
        furet nouvFuret = furets.Find(x => x.nom == UppercaseFirst(inputNomFuret.text));
        GameObject furetGo;
        if (nouvFuret != null && nouvFuret.nom != "" && curEditFuret.nom != nouvFuret.nom)
        {
            popup.fading("Ce furet existe déjà !");
        }
        else
        {
                buttonStats.interactable = true;
            texteNomFuret.text = curEditFuret.nom = UppercaseFirst(inputNomFuret.text);
            if (texteNomFuret.text == "")
                texteNomFuret.text = "<color=#aa0000><i>Pas de nom</i></color>";
            texteNoteFuret.text = curEditFuret.note = inputNoteFuret.text;
            if (texteNoteFuret.text == "")
                texteNoteFuret.text = "Aucune note";
            texteCouleurFuret.text = curEditFuret.couleur = inputCouleurFuret.options[inputCouleurFuret.value].text;
            if (texteCouleurFuret.text == "Aucune")
                texteCouleurFuret.text = "<color=#aa0000><i>Aucune</i></color>";
            DateTime dDate;
            string newDate = inputDateDayFuret.text + "/" + inputDateMonthFuret.text + "/" + inputDateYearFuret.text;
            // print(newDate);
            if (DateTime.TryParse(newDate, out dDate))
                texteDateFuret.text = curEditFuret.dateNaissance = newDate;
            else
            {
                curEditFuret.dateNaissance = "";
                texteDateFuret.text = "<color=#aa0000><i>Inconnue</i></color>";
            }
            textePereFuret.text = curEditFuret.pere = UppercaseFirst(inputPereFuret.text);
            if (textePereFuret.text == "")
                textePereFuret.text = "<color=#aa0000><i>Inconnu</i></color>";
            if (inputProvenanceFuret.text != "")
                texteProvenanceFuret.text = curEditFuret.provenance = inputProvenanceFuret.text;
            if (inputNumPuce.text != "")
                texteNumPuce.text = curEditFuret.numPuce = inputNumPuce.text;
            texteMereFuret.text = curEditFuret.mere = UppercaseFirst(inputMereFuret.text);
            if (texteMereFuret.text == "")
                texteMereFuret.text = "<color=#aa0000><i>Inconnue</i></color>";
            curEditFuret.sexe = sexe;
            curEditFuret.mort = toggleMort.isOn;
            curEditFuret.autreElevage = toggleAutreElevage.isOn;
            if (toggleAutreElevage.isOn)
                texteAutreElevage.text = "<color=#aa0000><i>(autre élevage)</i></color>";
            else
                texteAutreElevage.text = "";
            if (toggleMort.isOn)
                texteMort.text = "<color=#aa0000><i>Décédé</i></color>";
            else
                texteMort.text = "";
            furet papa = furets.Find(x => x.nom == inputPereFuret.text);
            if (papa != null)
            {
                textePereFuret.color = new Color(0, 0, 0.35f, 1);
            }
            else
            {
                textePereFuret.color = Color.black;
            }
            furet maman = furets.Find(x => x.nom == inputMereFuret.text);
            if (maman != null)
            {
                texteMereFuret.color = new Color(0, 0, 0.35f, 1);
            }
            else
            {
                texteMereFuret.color = Color.black;
            }
            if (sexe == 0)
                sexeImage.sprite = inconnuSprite;
            else if (sexe == 1)
                sexeImage.sprite = maleSprite;
            else if (sexe == 2)
                sexeImage.sprite = femelleSprite;
            if (nouveauFuret)
            {
                furets.Add(curEditFuret);
                GameObject nouveau = Instantiate(furetPrefab, listeFuretsTransform, false) as GameObject;
                furetGo = nouveau;
                nouveau.GetComponent<Furet>().identite = curEditFuret;
                // texteTotal.text = "Total : " + listeFuretsTransform.childCount;
                sortFurets(nouveau);
                if (setParentNouveau)
                {
                    curEditFuret.enfants = new List<string>();
                    curEditFuret.enfants.Add(furetParentNouveau.nom);
                    if (sexParentNouveau == 1)
                        furetParentNouveau.pere = curEditFuret.nom;
                    else
                        furetParentNouveau.mere = curEditFuret.nom;
                    setParentNouveau = false;
                    sexParentNouveau = 0;
                    furetParentNouveau = null;
                }
                if (inputNomFuret.text != "")
                    searchLiens(UppercaseFirst(inputNomFuret.text), curEditFuret); // cherche les liens avec les parents, et met à ces parents leur nouvel enfant
                // exitEditFuret();
                nouveauFuret = false;
                indexCurEditFuret = nouveau.transform.GetSiblingIndex();
                // curEditFuret = fur;
            }
            else
            {
                furets[indexCurEditFuret] = new furet();
                Furet fur = listeFuretsTransform.GetChild(indexCurEditFuret).GetComponent<Furet>();
                fur.identite = furets[indexCurEditFuret] = curEditFuret;
                fur.applyIdentity();
                furetGo = listeFuretsTransform.GetChild(indexCurEditFuret).gameObject;
                sortFurets(furetGo);
                if (setParentNouveau)
                {
                    curEditFuret.enfants = new List<string>();
                    curEditFuret.enfants.Add(furetParentNouveau.nom);
                    if (sexParentNouveau == 1)
                        furetParentNouveau.pere = curEditFuret.nom;
                    else
                        furetParentNouveau.mere = curEditFuret.nom;
                    setParentNouveau = false;
                    sexParentNouveau = 0;
                    furetParentNouveau = null;
                }
                if (inputNomFuret.text != "")
                    searchLiens(UppercaseFirst(inputNomFuret.text), curEditFuret); // cherche les liens avec les parents, et met à ces parents leur nouvel enfant
                if (curEditFuret.enfants.Count > 0)
                {
                    List<string> dates = new List<string>();
                    for (int i = 0; i < curEditFuret.enfants.Count; i++)
                    {
                        furet petit = furets.Find(x => x.nom == curEditFuret.enfants[i]);
                        if (!dates.Contains(petit.dateNaissance))
                            dates.Add(petit.dateNaissance);
                    }
                    if (dates.Count > 1)
                        texteEnfants.text = "<color=#000059>Nombre de petits : " + curEditFuret.enfants.Count + " (" + dates.Count + " portées)</color>";
                    else
                        texteEnfants.text = "<color=#000059>Nombre de petits : " + curEditFuret.enfants.Count + " (" + dates.Count + " portée)</color>";
                }
                else
                    texteEnfants.text = "Pas de petit";
                if (curEditFuret.pere != "" || curEditFuret.mere != "")
                    boutonGenealogy.SetActive(true);
                else
                    boutonGenealogy.SetActive(false);
            }
            headerEdit.text = "Informations";
            textesGO.SetActive(true);
            inputsGO.SetActive(false);
            StartCoroutine(triFuret(curEditFuret,furetGo));
            StartCoroutine(SaveManager1.saveManager1.saveListeFurets());
            showAmountFurets();
        }
    }
    
    void showAmountFurets()
    {
        int nbre = 0;
        for (int i = 0; i < listeFuretsTransform.childCount;i++)
        {
            if(listeFuretsTransform.GetChild(i).gameObject.activeSelf)
                nbre++;
        }
        texteTotal.text = "Total : " + nbre;
    }

    void sortFurets(GameObject fur = null)
    {
        furets.Sort((p1, p2) => p1.nom.CompareTo(p2.nom));
        for (int i = 0; i < furets.Count; i++)
        {
            furets[i].index = i;
        }
        if (fur != null)
        fur.transform.SetSiblingIndex(fur.GetComponent<Furet>().identite.index);
    }

    public void buttonDeclineEdit()
    {
        exitEditFuret();
    }
    
    void resetFicheFuret()
    {
        curEditFuret = null;
        indexCurEditFuret = -1;
        sexe = 0;
        femelle.transform.GetChild(0).gameObject.SetActive(false);
        male.transform.GetChild(0).gameObject.SetActive(false);
        texteNomFuret.text = inputNomFuret.text = "";
        texteNoteFuret.text = "Aucune note";
        inputNoteFuret.text = "";
        inputCouleurFuret.value = 0;
        texteCouleurFuret.text = "";
        toggleAutreElevage.isOn = toggleMort.isOn = false;
        texteDateFuret.text = inputDateDayFuret.text = inputDateMonthFuret.text = inputDateYearFuret.text = "";
        textePereFuret.text = inputPereFuret.text = "";
        texteProvenanceFuret.text = inputProvenanceFuret.text = "";
        texteAutreElevage.text = "";
        texteNumPuce.text = inputNumPuce.text = "";
        texteMereFuret.text = inputMereFuret.text = "";
    }
    
    public void forceExitEditFuret()
    {
        queueFichesFurets.Clear();
        resetFicheFuret();
        editCanvas.SetActive(false);
    }
    
    public void exitEditFuret()
    {
        if(genealogyCanvas.activeSelf)
        {
            editCanvas.GetComponent<Canvas>().sortingOrder = 1;
            forceExitEditFuret();
            return;
        }
        if(queueFichesFurets.Count>0)
        {
            int index = furets.IndexOf(queueFichesFurets[0]);
            resetFicheFuret();
            enableEditFuret(queueFichesFurets[0], index);
            queueFichesFurets.RemoveAt(0);
        }
        else
        {
            forceExitEditFuret();
        }
    }

    public void buttonDeleteFuret()
    {
        deleteLiens(furets[indexCurEditFuret]);
        furets.RemoveAt(indexCurEditFuret);
        GameObject objet = listeFuretsTransform.GetChild(indexCurEditFuret).gameObject;
        objet.transform.SetParent(editCanvas.transform);
        Destroy(objet);
        sortFurets();
        // texteTotal.text = "Total : " + listeFuretsTransform.childCount;
        if (listeFuretsTransform.childCount == 0)
            buttonStats.interactable = false;
        else
            buttonStats.interactable = true;
        exitEditFuret();
        resetTri();
        StartCoroutine(SaveManager1.saveManager1.saveListeFurets());
    }

    void deleteLiens(furet fur)
    {
        if (fur.pere != "")
        {
            furet pere = furets.Find(x => x.nom == fur.pere);
            pere.enfants.Remove(fur.nom);
        }
        if (fur.mere != "")
        {
            furet mere = furets.Find(x => x.nom == fur.mere);
            mere.enfants.Remove(fur.nom);
        }
        for (int i = 0; i < fur.enfants.Count; i++)
        {
            furet enfant = furets.Find(x => x.nom == fur.enfants[i]);
            if (enfant != null)
            {
                if (fur.sexe == 1)
                {
                    enfant.pere = "";
                }else if (fur.sexe == 2)
                {
                    enfant.mere = "";
                }
            }
        }
    }

    public void disableSecondList()
    {
        StartCoroutine(enableListFurets());
        listeNomsCanvas.SetActive(false);
    }
    
    IEnumerator enableListFurets()
    {
        for (int i = 0; i < furets.Count; i++)
        {
            listeFuretsTransform.GetChild(i).gameObject.SetActive(!furets[i].mort);
        }
        scrollView.SetParent(listeFuretsAttach);
        scrollView.localScale = new Vector2(1, 1);
        scrollView.GetComponent<RectTransform>().localPosition = new Vector2(0, -300);
        listeScrollBar.value = scrollBarValue;
        yield return null;
        listeFuretsTransform.localPosition = new Vector2(0,listTransformY);
    }
    
    public void disableEnfantsList()
    {
        StartCoroutine(enableListFurets());
        listeEnfantsCanvas.SetActive(false);
    }


    public void loadListBySex(int sex)
    {
        for (int i = 0; i < furets.Count; i++)
        {
            if (furets[i].sexe != sex)
                listeFuretsTransform.GetChild(i).gameObject.SetActive(false);
            else
                listeFuretsTransform.GetChild(i).gameObject.SetActive(true);
        }
        scrollView.SetParent(listeNomsAttach);
        scrollView.localScale = new Vector2(1, 1);
        scrollView.GetComponent<RectTransform>().localPosition = new Vector2(0, -300);
        listeNomsCanvas.SetActive(true);
    }

    public void addParent(furet fur)
    {
        if (fur.sexe == 1)
        {
            inputPereFuret.text = fur.nom;
        }else if (fur.sexe == 2)
        {
            inputMereFuret.text = fur.nom;
        }
        disableSecondList();
    }
    
    public void searchParent(int sexe)
    {
        queueFichesFurets.Insert(0, curEditFuret);
        string nom = EventSystem.current.currentSelectedGameObject.GetComponent<TMP_Text>().text;
        bool found = false;
        for (int i = 0; i < listeFuretsTransform.childCount; i++)
        {
            if (furets[i].nom == nom)
            {
                enableEditFuret(furets[i], listeFuretsTransform.GetChild(i).GetSiblingIndex());
                found = true;
                break;
            }
        }
        if(!found)
        {
            // on crée une nouvelle fiche furet
            setParentNouveau = true;
            furetParentNouveau = curEditFuret;
            sexParentNouveau = sexe;
            nouvelleFicheAvecNom(nom);
            if (sexe == 1)
                buttonMale();
            else
                buttonFemelle();
        }
    }
    bool setParentNouveau;
    int sexParentNouveau;
    furet furetParentNouveau;
    public void nouvelleFicheAvecNom(string nom)
    {
        editCanvas.GetComponent<Canvas>().sortingOrder = 7;
        resetFicheFuret();
        buttonNouveauFuret();
        texteNomFuret.text = inputNomFuret.text = nom;
    }
    
    void searchChilds(string nom)
    {
        // print("searching childs...");
        List<furet> listeEnfants = furets.Where(e => (e.pere == nom) || (e.mere == nom)).ToList();
        if(listeEnfants.Count>0)
        {
            curEditFuret.enfants = new List<string>();
            List<string> dates = new List<string>();
            for (int i = 0; i < listeEnfants.Count; i++)
            {
                curEditFuret.enfants.Add(listeEnfants[i].nom);
                furet petit = furets.Find(x => x.nom == listeEnfants[i].nom);
                if (!dates.Contains(petit.dateNaissance))
                    dates.Add(petit.dateNaissance);
            }
            if (dates.Count > 1)
                texteEnfants.text = "<color=#000059>Nombre de petits : " + listeEnfants.Count + " (" + dates.Count + " portées)</color>";
            else
                texteEnfants.text = "<color=#000059>Nombre de petits : " + listeEnfants.Count + " (" + dates.Count + " portée)</color>";
        }
        else
            texteEnfants.text = "Pas de petit";
    }
    
    public void searchLiens(string nouveau, furet fur) // fur = curEditFuret
    {
        // print("seaching links..." + nouveau);
        furet nouv = furets.Find(x => x.nom == nouveau);
        if (nouv.pere != "")
        {
            furet ancien = furets.Find(x => x.nom == fur.nom);
            furet pere = furets.Find(x => x.nom == fur.pere);
            if (pere != null)
            {
                if (pere.enfants.Contains(ancien.nom))
                {
                    pere.enfants.Remove(ancien.nom);
                }
                if (!pere.enfants.Contains(nouveau))
                {
                    pere.enfants.Add(nouveau);
                }
            }
        }
        if (nouv.mere != "")
        {
            furet mere = furets.Find(x => x.nom == fur.mere);
            furet ancien = furets.Find(x => x.nom == fur.nom);
            if (mere != null)
            {
                if (mere.enfants.Contains(ancien.nom))
                {
                    mere.enfants.Remove(ancien.nom);
                }
                if (!mere.enfants.Contains(nouveau))
                {
                    mere.enfants.Add(nouveau);
                }
            }
        }
        searchChilds(nouveau);
        // chercher les enfants ?
    }

    public void showEnfants()
    {
        listTransformY = listeFuretsTransform.localPosition.y;
        scrollBarValue = listeScrollBar.value;
        if (curEditFuret.enfants.Count > 0)
        {
            for (int i = 0; i < furets.Count; i++)
            {
                if (furets[i].pere == curEditFuret.nom || furets[i].mere == curEditFuret.nom)
                {
                    listeFuretsTransform.GetChild(i).gameObject.SetActive(true);
                }
                else
                {
                    listeFuretsTransform.GetChild(i).gameObject.SetActive(false);
                }
            }
            scrollView.SetParent(listeEnfantsAttach);
            scrollView.localScale = new Vector2(1, 1);
            scrollView.GetComponent<RectTransform>().localPosition = new Vector2(0, -300);
            listeEnfantsCanvas.SetActive(true);
        }
    }

}

[Serializable]
public class furet
{
    public int index;
    public string nom;
    public string dateNaissance;
    public int sexe;
    public string couleur;
    public bool mort;
    public string pere;
    public string mere;
    public List<string> enfants;
    public string note;
    public string provenance;
    public bool autreElevage;
    public string numPuce;
}