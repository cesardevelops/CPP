//
//  main.cpp
//  BubbleSort
//
//  Created by Cesar Montero on 1/30/21.
//  Copyright © 2021 Cesar Montero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

string GetSringFromArray(vector<int> inputArray)
    {
        string tmp;
        for(int i = 0; i < inputArray.size(); i++)
            {
                tmp = tmp + to_string(inputArray[i]) + " ";
            }
        
        return tmp;
    }

int main(int argc, const char * argv[])
    {
        vector<int> myArray;
        myArray = {12, 0, 3, 10, 5};// sample array
        
        //Print Entries
        cout<<"Unordered Array: ";
        cout<<GetSringFromArray(myArray);
        cout<<endl;

        int counter = 0;
        bool isArranged = false;
        while(isArranged == false)
            {
                isArranged = true;
                for(int i = 0; i < myArray.size() - 1 - counter; i++)
                    {
                        if(myArray[i] > myArray[i + 1])
                            {
                                int tmpA = myArray[i];
                                int tmpB = myArray[i + 1];
                                myArray[i] = tmpB;
                                myArray[i + 1] = tmpA;
                                isArranged = false;
                            }
                    }
                counter++;
            }
        
        //Print Results
        cout<<"Ordered Array: ";
        cout<<GetSringFromArray(myArray);
        cout<<endl;
        
         return 0;
    }
