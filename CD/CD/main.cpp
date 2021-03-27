//
//  main.cpp
//  CD
//
//  Created by Cesar Montero on 3/25/21.
//

#include <iostream>
using namespace std;

//cwd = current working directory
//arg = argument

bool isLetter(char &str){
    //lower cap letters
    if((str >= 'a') && (str <= 'z')){return true;}
    else if((str >= 'A') && (str <= 'Z')){return true;}
    else{return false;}
}

bool isDash(char &str){
    if(str == '/'){return true;}
       else{return false;}
}

bool isDot(char &str){
    if(str == '.'){return true;}
       else{return false;}
}
       
std::string cd(std::string &cwd, std::string &arg){

    string finalpath = "";
    
    //cd("/", "a/b") -> "/a/b"
    //If we get a "/" as current path, and "a/b" as argument, then log into the folder
    //The argument contains = folder/folder
    
    string pattern = "";
    string str = "randomFolder/stuff";
    
    //c
    for(int i = 0; i < str.size(); i++){
        cout << isLetter(str.at(i)) << endl;
    }
    
    return "nothing";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string cwd = "/";
    string arg = "nameA/nameB";
    cout << cd(cwd, arg);
    return 0;
}
