//
//  main.cpp
//  PrefixSum
//
//  Created by Cesar Montero on 3/20/21.
//


#include <iostream>
#include <array>
using namespace std;

/*
 
{10, 30, 40, 45, 60}

 prefix sum = 0
 prefi sum = 10 = inputArray[0]
 prefix sum = 30 = inputArray[0] + inputArray[1] .... prefixsum += inputArray[i]

 */

int main(int argc, const char * argv[])
    {
        
        int inputArray[] = {10, 20, 10, 5, 15};
        int inputSize = sizeof(inputArray)/sizeof(inputArray[0]);
        int outputArray[inputSize];
        int prefixsum = 0;
        for(int i = 0; i < inputSize; i++)
            {
                prefixsum += inputArray[i];
                outputArray[i] = prefixsum;
            }
        
        cout << "Prefix Sum: ";
        for(int i = 0; i < inputSize; i++)
            {
                cout << outputArray[i] << ", ";
            }
        cout << endl;
        
        return 0;
    }
