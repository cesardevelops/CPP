//
//  main.cpp
//  PrefixSum
//
//  Created by Cesar Montero on 3/20/21.
//
// element 1, prefixsum + inputArray[0]:
// element 2, prefixsum + inputArray[1]

#include <array>
#include <iostream>


int main()
    {
        int inputArray[] = {1, 2, 3, 4, 5};

        int arraySize = sizeof(inputArray)/sizeof(inputArray[0]);
        int outputArray[arraySize];
        int prefixsum = 0;
        
        for(int i = 0; i < arraySize; i++)
            {
                prefixsum += inputArray[i];
                outputArray[i] = prefixsum;
                std::cout << "outputArray[" << outputArray[i] << "]: " << outputArray[i] << std::endl;
            }
        
    }
