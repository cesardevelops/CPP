//
//  main.cpp
//  StringStream
//
//  Created by Cesar Montero on 1/29/21.
//  Copyright © 2021 Cesar Montero. All rights reserved.
//

/*
 Function Description

 Complete the parseInts function in the editor below.

 parseInts has the following parameters:

 string str: a string of comma separated integers
 Returns

 vector<int>: a vector of the parsed integers.
 Note You can learn to push elements onto a vector by solving the first problem in the STL chapter.

 Input Format

 There is one line of  integers separated by commas.

 Constraints

 The length of  is less than .
 
*/

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    vector<int> myVector;
    stringstream mySS(str);
    int myInt;
    char comma;
    while(mySS>>myInt)
        {
            myVector.push_back(myInt);
            mySS>>comma;
        }
    return myVector;
}

int main()
    {
        string str;
        cin >> str;
        vector<int> integers = parseInts(str);
        for(int i = 0; i < integers.size(); i++)
            {
                cout << integers[i] << "\n";
            }
        
        return 0;
    }
