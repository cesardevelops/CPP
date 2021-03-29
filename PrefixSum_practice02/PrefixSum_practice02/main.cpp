//
//  main.cpp
//  PrefixSum_practice02
//
//  Created by Cesar Montero on 3/28/21.
//
// array = {1, 2, 3, 4, 2, -2};
// prefixsum =  {{0,3}, {2,4}};
#include <iostream>
#include <vector>
using namespace std;


//O = n + k
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> list = {0, 1, 2, 3, 4, 5};

    vector<int> prefixsums(list.size());
    
    //get prefix sums
    int currentSum = 0;
    
    //n
    for(int i = 0 ; i < list.size(); i++){
        currentSum += list.at(i);
        prefixsums[i] = currentSum;
        //cout << prefixsums[i] << endl;
    }
   
    
    //calculate biggest range based on the difference of the prefix sums
    vector<vector<int>> ranges = {{0,3}, {2,4}};
    int leftIndex = 0;
    int rightIndex = 0;
    int biggestRangeSum = 0;
    int currentRangeSum = 0;
    
    for(int i = 0; i < ranges.size(); i++){
        
        leftIndex = ranges.at(i).at(0);
        rightIndex = ranges.at(i).at(1);
        //cout << "leftIndex: " << leftIndex << " rightIndex: " << rightIndex <<endl;
        if(leftIndex == 0){
            currentRangeSum = prefixsums.at(rightIndex);
        }
        else{
            currentRangeSum = prefixsums.at(rightIndex) - prefixsums.at(leftIndex - 1);
        }
        //check if the current calculation is bigger
        
        if(biggestRangeSum < currentRangeSum){
            biggestRangeSum = currentRangeSum;
            
        }
    }
    
    cout << biggestRangeSum << endl;
    return 0;
}
