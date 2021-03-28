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
    bool slide = true;
    unordered_map<char, int> um_letters;
    //run the loop until the right reaches the end of the string
    while(slide == true){
        
        //store in unorder map the sliding window entries
        for(int i = left; i <= right; i++){
            um_letters[str[i]] += 1;
        }
        //Get unique characters
        cout << um_letters.size() << endl;
        um_letters.clear();
        
        //move the area of evaluation
        left++;
        right = left + k - 1;
        
        //break sliding window loop
        if(right == str.length()){
            slide = false;
        }
    }
    
}

int main(int argc, const char * argv[]) {

    string str = "aaabcc";
    print_unique_k_chars_sliding_windiow(str, 3);
    return 0;
}
