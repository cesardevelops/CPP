//
//  main.cpp
//  PrefixSum_practice01
//
//  Created by Cesar Montero on 3/28/21.
//
/*
You have an array of integers and a list of ranges. Find the range with the highest sum
 

 
 */
#include <iostream>
#include <array>
using namespace std;

//It takes the left and right index values and calculates the difference to find the sum


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int inputArray[] = {1, 2, 3, 4, 2, -2};
    int inputArrayLenght = sizeof(inputArray)/sizeof(inputArray[0]);
    int prefixSums[sizeof(inputArray)/sizeof(inputArray[0])] = {};
    int currentSum = 0;
    
    //Calculate prefix sums
    for(int i = 0; i < inputArrayLenght; i++){
        currentSum +=  inputArray[i];
        prefixSums[i] = currentSum;
        //cout << prefixSums[i] << endl;
    }
    
    //find biggest range
    //int rangeSize = 2;
    int ranges[2][2] = {{0,3}, {2,4}};
    int rangesSize = sizeof(ranges)/sizeof(ranges[0]);
    int left = 0;
    int right = 0;
    int biggestSum = 0;
    
    for(int i = 0; i < rangesSize; i++){
        
        left = ranges[i][0];
        right = ranges[i][1];
        cout << "left: " << ranges[i][0] << endl;
        cout << "right: " << ranges[i][1] << endl;
        if(left == 0){
            biggestSum = prefixSums[right];
        }
        else{
            biggestSum = prefixSums[right] - prefixSums[left - 1];
        }
    }
    
    cout << "biggest sum: "<< biggestSum << endl;
    return 0;
}
