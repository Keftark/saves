// using Firebase;
// using Firebase.Storage;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading.Tasks;
using UnityEngine;
using UnityGoogleDrive;

public class SaveManagerGoogle : MonoBehaviour
{
    public static SaveManagerGoogle saveManagerGoogle;
    public List<furet> furets;
    MenuManager manager;
    // FirebaseStorage storage;
    // StorageReference storage_ref;
    void Awake()
    {
        saveManagerGoogle = this;
    }

    private void Start()
    {
        GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Starting";
        manager = MenuManager.manager;
        // storage = FirebaseStorage.DefaultInstance;
        GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Starting1";
        // storage_ref = storage.GetReferenceFromUrl("gs://genealogiefurets.appspot.com");
        StartCoroutine(loadListeFurets());
    }

    public void saveListeFurets()
    {
        bool internet = false;
        if (Application.internetReachability == NetworkReachability.NotReachable)
        {
            internet = false;
            manager.localSave = true;
        }
        else
        {
            internet = true;
            manager.localSave = false;
        }

        // on sauvegarde le bool contenant l'état de la connexion internet
        BinaryFormatter binary = new BinaryFormatter();
        FileStream file;
        using (file = new FileStream(Application.persistentDataPath + "/saveInternet.dat", FileMode.Create))
        {
            SaveInternet save = new SaveInternet();
            // DATA HERE !
            save.localSave = !internet;
            binary.Serialize(file, save);
            file.Close();
        }



        BinaryFormatter binary2 = new BinaryFormatter();
        using (file = new FileStream(Application.persistentDataPath + "/savefurets.dat",FileMode.Create))
        {
            Save1 save = new Save1();
            // DATA HERE !
            save.furets = new List<furet>(manager.furets);
            binary2.Serialize(file, save);
            file.Close();
        }
        if (!internet)
        {
            manager.popup.fading("<color=#00ee00>Sauvegarde locale terminée</color>");
        }
        else
        {
            
            string local_file = Application.persistentDataPath + "/savefurets.dat";
            Stream stream = new FileStream(local_file, FileMode.Open);
            MemoryStream memStream =new MemoryStream();
            stream.CopyTo(memStream);
            var fileGoogle = new UnityGoogleDrive.Data.File() { Name = Application.persistentDataPath + "/savefurets.dat", Content = memStream.ToArray() };
            GoogleDriveFiles.Create(fileGoogle).Send();
            stream.Close();
        }
    }
    
    public IEnumerator loadListeFurets()
    {
        GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Loading...";
        // on charge le bool contenant l'état de la connexion internet lors de la sauvegarde
        if (File.Exists(Application.persistentDataPath + "/saveInternet.dat"))
        {
            BinaryFormatter binary = new BinaryFormatter();
            FileStream file = File.Open(Application.persistentDataPath + "/saveInternet.dat", FileMode.Open);
            SaveInternet save = (SaveInternet)binary.Deserialize(file);
            file.Close();
            manager.localSave = save.localSave;
        }

        if (Application.internetReachability == NetworkReachability.NotReachable) // si pas de connexion internet, rien ne change puisqu'on ne peut que prendre la sauvegarde locale
        {
            GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Local, sans connexion";
            load();
        }
        else // si on a une connexion internet, on doit vérifier l'état du bool 
        {
            if (manager.localSave) // si la sauvegarde était locale, on charge la sauvegarde locale
            {
                GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Local, avec connexion";
                load();
            }
            else // sinon, on charge la sauvegarde d'internet
            {
                GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Téléchargement";
                GoogleDriveFiles.DownloadRequest request = GoogleDriveFiles.Download("savefurets.dat");
                yield return request.Send();
                // request.Send().OnDone += loadFile;
                if (request.IsError || request.ResponseData == null)
                {
                    GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Failed to retrieve file.  ";
                    yield break;
                }else
                {
                    GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Téléchargé";
                    loadFile(request.ResponseData);
                }
            }
        }
        // GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Finished Loading";
        yield return null;
    }
    
    void loadFile(UnityGoogleDrive.Data.File file)
    {
        // file.BeginRead
        BinaryFormatter binary = new BinaryFormatter();
        FileStream fileStr = new FileStream("savefurets.dat", FileMode.Create);
        for (int i = 0; i < file.Content.Length;i++)
            fileStr.WriteByte(file.Content[i]);
        SaveGoogle save = (SaveGoogle)binary.Deserialize(fileStr);
        fileStr.Close();
        manager.furets = new List<furet>(save.furets);
        manager.initListeFurets();
        GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Game loaded from cloud!";
    }

    public void load()
    {
        if (File.Exists(Application.persistentDataPath + "/savefurets.dat"))
        {
            BinaryFormatter binary = new BinaryFormatter();
            FileStream file = File.Open(Application.persistentDataPath + "/savefurets.dat", FileMode.Open);
            SaveGoogle save = (SaveGoogle)binary.Deserialize(file);
            file.Close();
            manager.furets = new List<furet>(save.furets);
            manager.initListeFurets();
            GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Game loaded locally!";
        }
    }

    public void deleteSave()
    {
        if (File.Exists(Application.persistentDataPath + "/savefurets.dat"))
        {
            File.Delete(Application.persistentDataPath + "/savefurets.dat");
        }
        if (File.Exists(Application.persistentDataPath + "/saveInternet.dat"))
        {
            File.Delete(Application.persistentDataPath + "/saveInternet.dat");
        }
        Debug.Log("Game Deleted!");
    }
}

[Serializable]
public class SaveGoogle
{
    public bool localSave;
    public List<furet> furets;
}
