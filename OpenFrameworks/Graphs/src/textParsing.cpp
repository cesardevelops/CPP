//
//  textParsing.cpp
//  Graphs
//
//  Created by Cesar Montero on 2/28/21.
//

#include "ofApp.h"
#include "textParsing.hpp"

using namespace std;

//removes a single character fro a string
void RemoveChar(string &myString, char &char_to_remove){
    //Explanation of this line of code can be found here: https://tinyurl.com/3bjkzt45
    myString.erase(std::remove(myString.begin(), myString.end(), char_to_remove), myString.end());
}

//removes characters from a string
void RemoveCharacters(string &myString, vector<char> &list){
    for(int i = 0; i < list.size(); i++){
        RemoveChar(myString, list.at(i));
    }
}

//counts how many words of size X exist in a string.
vector<int> CountWords(string myString){
    vector<char> remove_list = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '\n', '{', '}', ':', '"', ',', '?', '.', '<', '>', '^'};
    RemoveCharacters(myString, remove_list); //Remove unnecessary characters
    vector<string> splitString = ofSplitString( myString, " "); //Separate text into a vector containing words.
    vector<int> countsVector(1);
    string currentString;
    int newSize = 0;
    //Counts the size each word, and adds +1 on a vector keeping score of all word sizes.
    for(int i = 0; i < splitString.size(); i++){
        currentString = splitString[i];
        //Extends the vector if the current size is not enough to store a word of this size.
        if(currentString.length() + 1 > countsVector.size()){
            countsVector.resize(currentString.length() + 1, 0);
        }
        countsVector.at(currentString.length()) += 1;
    }
    return countsVector; //return the word counts.
}

// returns the biggest in from a vector
int GetBiggestInt(vector<int> &counts){
    int max = 0;
    //Reads each item in a vector and keeps the biggest one.
    for(int i = 0; i < counts.size(); i++){
        if(max<counts[i]){
            max = counts[i];
        }
    }
    return max;
}

//reads a file by passing it it the path to it.
string ReadFile(string &path){
    ofFile file;
    file.open(ofToDataPath(path), ofFile::ReadWrite, false);
    ofBuffer buff = file.readToBuffer();
    return buff.getText();
}

/*
//Removes a new line in a string. Not used
void rm_nl(string &s){
    for (int p = s.find("\n"); p != (int) string::npos; p = s.find("\n")){
        s.erase(p, 1);
    }
}
*/
