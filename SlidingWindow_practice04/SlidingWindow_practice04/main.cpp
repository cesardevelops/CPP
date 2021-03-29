//
//  main.cpp
//  SlidingWindow_practice04
//
//  Created by Cesar Montero on 3/29/21.
//
/*
 Given an input string and a value k, print how many unique chars are within a sliding window of size k going through this string.
 
 Input: s=”aaabcc”, k = 3
 
 Sliding window -> output;
 [aaa]bcc -> 1
 “a[aab]cc ->2
 Aa[abc]c -> 3
 Aaa[bcc] -> 2
 
 */


 


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void print_unique_k_chars_sliding_window(string  &str, int k){
    int left = 0;
    int right = left + k -1;
    bool loop = true;
    unordered_map<char, int> um_letters;
    
    while(loop == true){
        
        //add to the unordered map
        for(int i = left; i <= right; i++){
            um_letters[str[i]] += 1;
        }
        cout << um_letters.size() << endl;
        um_letters.clear();
        //check the size of the unordered map
        //chear the unordered map
        
        //break loop by checking if right = lenght of string
        left++;
        right = left + k -1;
        if(right == str.length()){
            loop = false;
        }
    }
}

int main(int argc, const char * argv[]) {

    string input = "aaabcc";
    print_unique_k_chars_sliding_window(input, 3);
    return 0;
}
