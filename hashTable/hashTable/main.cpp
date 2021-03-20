//
//  main.cpp
//  hashTable
//
//  Created by Cesar Montero on 2/24/21.
// https://www.youtube.com/watch?v=UOxTMOCTEZk&t=647s
//https://forum.openframeworks.cc/t/charcodeat-equivalent/23605/3
//https://www.programiz.com/cpp-programming/examples/ASCII-value-character
//https://github.com/cesardevelops/JAVASCRIPT/blob/main/HashTable.js
//https://www.educative.io/edpresso/how-to-implement-a-hash-table-in-cpp

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

//Does not work
int HashStringToInt(string s, int tableSize)
    {
        int primeA=13;
        int primeB=17;
        int hash = primeA * primeB;
        for(int i = 0; i < s.size(); i++)
            {
                hash = (hash * int(s.at(i))) % tableSize;
                cout << "hash: " << hash << endl;
            }
       return hash;
    }

//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
int  HashFunction(string word, int size)
// POST: the index of entry is returned
{       int sum = 0;
        for (int k = 0; k < word.length(); k++)
            sum = sum + int(word[k]);
        return  sum % size;
}

//https://www.youtube.com/watch?v=jtMwp0FqEcg
int  HashWord(string word, int size)
    {
        int g = 31;
        int hash = 0;
        for(int i = 0; i < word.length(); i++)
            {
                hash = g * hash + int(word.at(i));
            }
        return hash;
        
    }

class HashTable
    {
        private:

        
        public:
            string table[1000];
        
            HashTable()
                {
                    
                }
            void setItem(string key, string value)
                {
                    int idx = HashStringToInt(key, sizeof(table));
                    table[idx] = value;
                }
            string getItem(string key)
                {
                    int idx = HashStringToInt(key, sizeof(table));
                    return table[idx];
                }
    };

 
int main(int argc, const char * argv[]) {

    
    //HashTable myTable;
    //myTable.setItem("firstName", "Cesar");
    //myTable.setItem("lastName", "Montero");
    //myTable.getItem("firstName");
    //cout << myTable.getItem("firstName") << "\n";
    //cout << myTable.getItem("lastName") << "\n";
    
    //vector<string> aTable(100);
    
    //testing characters.
    //string word = "cesar";
    //int hash = 1 * 31 + int(word.at(2));
    //cout << "Result: " << hash << endl;
    
    //return hash;
    
    cout << "Result: " << HashWord("firstName", 100) << endl;
    
    
    return 0;
}
