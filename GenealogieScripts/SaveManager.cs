using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using UnityEngine;
//using UnityGoogleDrive;

public class SaveManager : MonoBehaviour
{
    public static SaveManager saveManager;
    public List<furet> furets;
    MenuManager manager;

    void Awake()
    {
        saveManager = this;
    }

    private void Start()
    {
        //deleteSave();
        manager = MenuManager.manager;
        loadListeFurets();
    }

    public void saveListeFurets()
    {
        BinaryFormatter binary = new BinaryFormatter();
        FileStream file = File.Create(Application.persistentDataPath + "/savefurets.dat");
        Save1 save = new Save1();

        // DATA HERE !
        save.furets = new List<furet>(manager.furets);

        binary.Serialize(file, save);

        //var filee = new UnityGoogleDrive.Data.File { Name = "savefurets.dat", Content = getBytes(file), };
        //GoogleDriveFiles.Create(filee).Send();
        file.Close();
        //manager.popup.fading("<color=#00ee00>Sauvegarde terminée</color>");
    }

    public byte[] getBytes(FileStream file)
    {
        using (var memoryStream = new MemoryStream())
        {
            file.CopyTo(memoryStream);
            return memoryStream.ToArray();
        }
    }
    public void loadListeFurets()
    {
        if (File.Exists(Application.persistentDataPath + "/savefurets.dat"))
        {
            Debug.Log("Game loaded !");
            BinaryFormatter binary = new BinaryFormatter();
            FileStream file = File.Open(Application.persistentDataPath + "/savefurets.dat", FileMode.Open);
            Save1 save = (Save1)binary.Deserialize(file);
            file.Close();

            // DATA HERE !
            manager.furets = new List<furet>(save.furets);
            manager.initListeFurets();
        }
        else
        {

        }
    }

    private void OnApplicationQuit()
    {
        saveListeFurets();
    }

    public void QuitApp()
    {
        Application.Quit();
    }


    public void deleteSave()
    {
        if (File.Exists(Application.persistentDataPath + "/savefurets.dat"))
        {
            File.Delete(Application.persistentDataPath + "/savefurets.dat");
        }
        Debug.Log("Game Deleted !");
    }
}

[Serializable]
public class Save
{
    public List<furet> furets;
}

