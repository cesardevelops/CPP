
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//A user can have Actions

class User{
public:
    User(){}
    ~User(){}
    void getID(){}
    void setID(){}
    
protected:
    int ID = 0;
    //vector<Actions> = {};
};

//One Engine Session can have many users
class EngineSession{
public:
    EngineSession(){}
    ~EngineSession(){}
    void addUserToSession(){}
    void removeUserFromSession(){}

protected:
    unordered_map<int, int> activeUsers;
    
};


//This hols the asset info. It is important to define a time/space
//relationship to synch back and forth between software packages
class Asset{
public:
    Asset(){}
    ~Asset(){}
protected:
    //information related to the asset regardless of time/space
    float size;
    string type;
    string fileName;
    
    //time & space information to keep syncronisity while moving around
    string localPath;
    string remotePath;
    vector<string> timeStamps;
    
    //variables to relate to other assets?
    vector<Asset> dependencies;
    
};

//Mostly to interface with the subclasses methods
class Importer{
public:
    Importer(){};
    virtual ~Importer(){};

    //Each sub-asset type of asset would have its own type of importing
    virtual void ReadFile(){}
    virtual void GetFileSize(){}
    virtual void Import(){}
    
    //All files imported have some shared methods?
    void SetFilePath(string &&s){filePath = s;}
    string GetFilePath(){ return filePath;};
    void setImportStatus(){}
    int getImportStatus(){ return 0;}
    
protected:
    int importStatus = 0;
    int importID = 0;
    string filePath = "";
    
};


//Importer for FBX
class FBXImporter: public Importer{
public:
    FBXImporter(): Importer(){}
    ~FBXImporter(){}
    
    //exist on parent, but defined only on subclass
    void ReadFile(){
        ParseFBX();
    }
    
    //some methods particular to the subclass and no other type of asset
private:
    void ParseFBX(){}
    void StoreLocal(){} //
    void CleanFBX(){} //sometimes are quite dirty
    
protected:
    vector<Asset> FBXAssets = {};
};



//Importer for PNG...and so on for the rest of the items.
//...A subclass for each importer/exporter to make it more modular


//...A subclass for each importer/exporter to make it more modular
class Exporter{
public:
    
};


int main(int argc, const char * argv[]) {

    //Make an Importer
    Importer* myImporter= new FBXImporter();
    myImporter->SetFilePath("/Documents/Cesar");
    cout << myImporter->GetFilePath() << endl;
    
    //std::cout << "Hello, World!\n";
    return 0;
}
