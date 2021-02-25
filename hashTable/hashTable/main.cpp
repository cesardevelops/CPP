//
//  main.cpp
//  hashTable
//
//  Created by Cesar Montero on 2/24/21.
// https://www.youtube.com/watch?v=UOxTMOCTEZk&t=647s

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hashStringToInt(string s)
    {
        return 5;
    }
class HashTable
    {
        private:
            vector<string> table;
        public:
            void setItem(string key, string value)
                {
                    int idx = hashStringToInt(key);
                    table[idx] = value;
                }
            string getItem(string key)
                {
                    return "hello \n";
                }
    };

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    HashTable mytable;
    mytable.setItem("firstname", "Bob");
    string result = mytable.getItem("firstname");
    cout << result;
    return 0;
}
