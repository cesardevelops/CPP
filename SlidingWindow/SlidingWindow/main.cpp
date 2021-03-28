//
//  main.cpp
//  SlidingWindow
//
//  Created by Cesar Montero on 3/28/21.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int main(int argc, const char * argv[]) {
    
    string stringInput = "aaabcc";
    unordered_map<char, int> um_letters;
    
    int k = 3;
    int left = 0;
    int right = left + k - 1;
    bool move = true;

    
    while(move == true){
        
        for(int i = 0; i < stringInput.length(); i++){

            //Print a line
            if(i == left){cout << '[';}
            cout << stringInput[i];
            if(i == right){cout << ']';}

            //Create unordered map set
            if(i >= left && i <= right ){
                um_letters[stringInput[i]] += 1;
            }
        }
        cout << "-> "<< um_letters.size() << endl;
        //clear the unordered map
        um_letters.clear();
        
        //increase counters and evaluate if we should continue the loop
        left++;
        right = right = left + k - 1;
        if(right == stringInput.length()){move = false;}//we reach the end of the array
    }

    return 0;
}

// nlogn
