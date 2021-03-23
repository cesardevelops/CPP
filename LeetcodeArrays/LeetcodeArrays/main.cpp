//
//  main.cpp
//  LeetcodeArrays
//
//  Created by Cesar Montero on 3/22/21.
//
/*
 
 Find elements which are present in first array and not in second
 Input : a[] = {1, 2, 3, 4, 5, 10};
 b[] = {2, 3, 1, 0, 5};
 
 */

//Take the second array and iterate through it
   
   //Case 1: Remove from  A[] elements from B[] IF equal
   //2. Remove 2 from first array
   //3. Remove it from first array
   //1. Can't find 1, don't do anything
   //0. Cant find 0, dont do anything
   //5. Remove 5

//Time: O(N^2)

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
    {
        
        
        vector<int> a = {1, 2, 3, 4, 5, 10};
        vector<int> b = {2, 3, 1, 0, 5};
        
        for(int i = 0; i < b.size() ; i++)
            {
                for (int j = 0; j < a.size() ; j++)
                    {
                        //if it is equal, remove it
                        if(b[i] == a[j])
                            {
                                cout << "hello" << endl;
                                a.erase(a.begin()+j);
                            }
                    }
            }
        
        //print it
        for (int k = 0; k < a.size(); k++)
            {
                cout << a[k] << ", ";
            }
        
        return 0;
        
    }
