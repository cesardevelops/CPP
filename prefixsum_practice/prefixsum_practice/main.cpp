//
//  main.cpp
//  prefixsum_practice
//
//  Created by Cesar Montero on 3/24/21.
//
//“prefix sum”


#include <iostream>
#include <vector>
using namespace std;

int getRangeSum(vector<int> range, vector<int> sums){
    
    int left = range.at(0);
    int right = range.at(1);
    if(left == 0){
        //From the sum list, return the index which equals the second number of the given range
        return sums.at(right);
    }
    else{
        return sums.at(right)
        - sums.at(left - 1);
    }
}

int main(int argc, const char * argv[]) {
    //0, 1, 3, 6, 10, 15
    //0  1  2  3  4   5
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5};
    std::vector<int> sums(numbers.size());
    int runningsum = 0;
    
    //add new running sum
    for(int i = 0; i < numbers.size(); i++){
        runningsum += numbers.at(i);
        sums.at(i) = runningsum;
        //std::cout << runningsum << std::endl;
    }
    
    //Find biggest range
    //{{0,3},{2,4}}
    vector<vector<int>> ranges;// = {{0,3},{2,4}};
    vector<int> range1 = {0,3};
    vector<int> range2 = {2,4};
    ranges.push_back(range1);
    ranges.push_back(range2);
    
    //cout << ranges.at(0).at(1) <<endl;
    //Get biggest range sum
    int biggestRangeSum = 0;
    int currentRangeSum = 0;
    //cout << ranges.size() << endl;
    
    for(int i = 0; i  < ranges.size(); i++){
        vector<int> currentRange = ranges.at(i);
        currentRangeSum = getRangeSum(currentRange, sums);//We will get back to this shortly
        if(biggestRangeSum < currentRangeSum){
            biggestRangeSum = currentRangeSum;
        }
         
    }
    
    cout << "The biggest Range is: " << biggestRangeSum << endl;
    
    return 0;
}
