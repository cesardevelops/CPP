//
//  main.cpp
//  SlidingWindow02
//
//  Created by Cesar Montero on 3/28/21.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void print_unique_k_chars_sliding_windiow(string &str, int k){
    int left = 0;
    int right = left + k - 1;
    bool loop = true;
    unordered_map<char, int> um_letters;
    
    //General loop
    while(loop == true){
        
        //count occurences
        for(int i = left; i <= right; i++){
            um_letters[str[i]] +=1;
        }
        //unique characters
        cout << um_letters.size() << endl;
        
        //clear count to start with next range of sliding window
        um_letters.clear();
        
        //break the loop?
        left++;
        right = left + k - 1;
        if(right == str.length()){loop = false;}
    }
    
}

int main(int argc, const char * argv[]) {

    string str = "aaabcc";
    print_unique_k_chars_sliding_windiow(str, 3);
    return 0;
}
