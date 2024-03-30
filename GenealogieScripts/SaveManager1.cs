using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using UnityEngine;
using UnityGoogleDrive;

public class SaveManager1 : MonoBehaviour
{
    public static SaveManager1 saveManager1;
    public List<furet> furets;
    [SerializeField] MenuManager manager;
    void Awake()
    {
        saveManager1 = this;
    }

    private void Start()
    {
        StartCoroutine(loadListeFurets());
    }
    
    [System.Serializable]
    public class FuretListWrapper
    {
        public List<furet> furetList;

        public FuretListWrapper(List<furet> list)
        {
            furetList = list;
        }
    }
    public IEnumerator saveListeFurets()
    {
        // on sauvegarde le bool contenant l'état de la connexion internet
        FileStream file;
        BinaryFormatter binary2 = new BinaryFormatter();
        using (file = new FileStream(Application.persistentDataPath + "/savefurets.dat",FileMode.Create))
        {
            Save1 save = new Save1();
            // DATA HERE !
            save.furets = new List<furet>(manager.furets);
            binary2.Serialize(file, save);
            file.Close();
            FuretListWrapper wrapper = new FuretListWrapper(manager.furets);
            string jsonData = JsonUtility.ToJson(wrapper);
            File.WriteAllText(Application.persistentDataPath + "/furetData.json", jsonData);
        }
        yield return null;
    }



    GoogleDriveFiles.DownloadRequest request;
    public IEnumerator loadListeFurets()
    {
        load();
        // loadJson();
        yield return null;
    }


    public void loadStream(UnityGoogleDrive.Data.File file = null)
    {
            if (file == null)
            {
                return;
            }else
            if(file.Content == null)
            {
                return;
            }
            File.WriteAllBytes(Application.persistentDataPath + "/savefurets.dat", file.Content);
            load();
        
    }
    
    public void load()
    {
        BinaryFormatter binary = new BinaryFormatter();
        FileStream file = File.Open(Application.persistentDataPath + "/savefurets.dat", FileMode.Open);
        Save1 save = (Save1)binary.Deserialize(file);
        file.Close();
        manager.furets = new List<furet>(save.furets);
        manager.initListeFurets();
        Debug.Log("Game loaded locally!"+Application.persistentDataPath);
    }
    
    public void loadJson()
    {
        string path = Application.persistentDataPath + "/furetData.json";
        if (File.Exists(path))
        {
            string jsonData = File.ReadAllText(path);
            FuretListWrapper wrapper = JsonUtility.FromJson<FuretListWrapper>(jsonData);
            manager.furets = new List<furet>(wrapper.furetList);
            manager.initListeFurets();
        }
        else
            Debug.Log("Mince !");
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
public class Save1
{
    // public bool localSave;
    public List<furet> furets;
}

[Serializable]
public class SaveInternet
{
    public bool localSave;
}



// code propre !

/*
using Firebase;
using Firebase.Storage;
using Firebase.Unity.Editor;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using UnityEngine;

public class SaveManager1 : MonoBehaviour
{
    public static SaveManager1 saveManager1;
    public List<furet> furets;
    MenuManager manager;
    FirebaseStorage storage;
    StorageReference storage_ref;
    void Awake()
    {
        saveManager1 = this;
    }

    private void Start()
    {
        manager = MenuManager.manager;
        storage = FirebaseStorage.DefaultInstance;
        storage_ref = storage.GetReferenceFromUrl("gs://genealogiefurets.appspot.com");
        loadListeFurets();
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
        BinaryFormatter binary = new BinaryFormatter();
        FileStream file;
        using (file = new FileStream(Application.persistentDataPath + "/savefurets.dat",FileMode.Create))
        {
            Save1 save = new Save1();
            // DATA HERE !
            save.furets = new List<furet>(manager.furets);
            save.localSave = internet;
            binary.Serialize(file, save);
            file.Close();
        }
        if (!internet)
        {
            manager.popup.fading("<color=#00ee00>Sauvegarde locale terminée</color>");
        }
        else
        {
            string local_file = Application.persistentDataPath + "/savefurets.dat";
            var taskScheduler = TaskScheduler.FromCurrentSynchronizationContext();
            StorageReference rivers_ref = storage_ref.Child("savefurets.dat");
            Stream stream = new FileStream(local_file, FileMode.Open);
            rivers_ref.PutStreamAsync(stream)
            //rivers_ref.PutFileAsync(local_file)
      .ContinueWith((Task<StorageMetadata> task) => {
          if (task.IsFaulted || task.IsCanceled)
          {
              GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = task.Exception.ToString();
              manager.popup.fading("Bug");
              Debug.Log(task.Exception.ToString());
          }
          else
          {
              manager.popup.fading("<color=#00ee00>Sauvegarde terminée</color>");
              Debug.Log("Finished uploading...");
              stream.Close();
              
          }
      }, taskScheduler);
        }
    }
    
    public void loadListeFurets()
    {
        if (Application.internetReachability == NetworkReachability.NotReachable)
        {
            manager.buttonSave.interactable = false;
            //manager.popup.fading("Chargement local");
            load();
            //GameObject.Find("MainUI/Fond/TextLocal").GetComponent<TMPro.TMP_Text>().text = "Pas de connexion internet, ne pas enregistrer";
        }
        else
        {
            manager.buttonSave.interactable = true;
            //manager.popup.fading("Chargement internet");
            StorageReference gs_reference =
          storage.GetReferenceFromUrl("gs://genealogiefurets.appspot.com/savefurets.dat");
            string local_url = Application.persistentDataPath + "/savefurets.dat";
            var taskScheduler = TaskScheduler.FromCurrentSynchronizationContext();
            // Download to the local filesystem
            gs_reference.GetFileAsync(local_url).ContinueWith(task =>
            {
                if (!task.IsFaulted && !task.IsCanceled)
                {
                    load();
                }
            }, taskScheduler);
        }
    }

    public void load()
    {
        BinaryFormatter binary = new BinaryFormatter();
        FileStream file = File.Open(Application.persistentDataPath + "/savefurets.dat", FileMode.Open);
        Save1 save = (Save1)binary.Deserialize(file);
        file.Close();
        manager.localSave = save.localSave;
        manager.furets = new List<furet>(save.furets);
        manager.initListeFurets();
        Debug.Log("Game loaded !");
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
Debug.Log("Game Deleted !");
    }
}

[Serializable]
public class Save1
{
    public bool localSave;
    public List<furet> furets;
}

 **/
