//
//  main.cpp
//  BiggestSumRange
//
//  Created by Cesar Montero on 3/21/21.
//

//

/*
PROBLEM:
You have an array of integers and a list of ranges. Find the range with the highest sum.


ASSUMPTIONS
Array of integers: {1,2,3,4,2,-2}
List of ranges: {{0,3},{2,4}}

DEDUCTIONS
Calculate prefix sum, then use prefix sum to iterate through ranges to find biggest range um
{0,3} = 1, 2, 3, 4 = 10
{2, 4} = 3, 4, 2 = 9
Prefix sum {1, 3, 6, 10, 12, 10}

A = prefixsum[4] = 12
B = prefixsum[2 - 1] = prefixsum[1] = 3
A - B = 9

EDGE CASES
if first number is 0, then return the right side of the range.
Range with highest sum: {0,3}

 */

#include <iostream>
#include <array>
using namespace std;


int main(int argc, const char * argv[])
    {

        int inputArray[] = {1,2,3,4,2,-2};
        int ranges[2][2] = {{0,3},{2,4}};
        int size = sizeof(inputArray)/sizeof(inputArray[0]);
        int sumsArray[size];
        int prefixsum = 0;
        
        for(int i = 0; i < size; i++)
            {
                prefixsum += inputArray[i];
                sumsArray[i] = prefixsum;
            }
        
        
        int rows = sizeof(ranges)/sizeof(ranges[0]);
        
        int biggestRange[] = {0, 0};
        int currentSum = 0;
        int biggestSum = 0;
        int leftIndex, rightIndex;
        
        for(int i = 0; i < rows; i++)
            {
                leftIndex = ranges[i][0];
                rightIndex = ranges[i][1];
                if (leftIndex == 0)
                    {
                        currentSum = sumsArray[rightIndex];
                    }
                else
                    {
                        currentSum = sumsArray[rightIndex] - sumsArray[leftIndex - 1];
                    }
                
                if(currentSum > biggestSum)
                    {
                        biggestSum = currentSum;
                        biggestRange[0] = leftIndex;
                        biggestRange[1] = rightIndex;
                    }
            }
        cout << "BiggestSum is " << biggestSum <<endl;
        cout << "Range: {"<< biggestRange[0]<<", " << biggestRange[1] << "}"<<endl;
        
    }


