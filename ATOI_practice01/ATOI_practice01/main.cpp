//
//  main.cpp
//  ATOI_practice01
//
//  Created by Cesar Montero on 3/28/21.
//

// Invalid strings = anything other than 0-9, return 0
// negative numbers
// Overflow, too big of a result?
// return 0 when it fails

#include <iostream>
#include <string>
using namespace std;

int myatoi(const char* str){
    
    //variable definition
    int result = 0;
    int sign = 1;
    int counter = 0;
    
    //check if string is empty
    if(strlen(str) == 0){
        return 0;
    }
    
    //check for sign
    if(str[0] == '-'){
        sign = - 1;
        counter++;
    }
    
    //iterate through each character
    for(;counter != strlen(str); counter++){
        
        //Check if the characer is outside the range 0-9
        if(str[counter] < '0' || str[counter] > '9'){
            return 0;
        }
        
        //Check for Overflow, Overflow = we went above INT_MAX
        if(result > INT_MAX/10){
            return 0;
        }
        
        //If we get here, then we only have numbers
        result = (result * 10) + str[counter] - '0';
    }
    return result * sign;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    const char* str = "-123";
    cout << myatoi(str) << endl;
    return 0;
}
