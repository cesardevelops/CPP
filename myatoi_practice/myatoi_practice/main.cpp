//
//  main.cpp
//  myatoi_practice
//
//  Created by Cesar Montero on 3/24/21.
//

//check if empty

//check for minus sign
    //add to counter
//loop
    //check for invalid character: a
        //add  to result
        //add to counter
    //check if invalid range
//return result

#include <iostream>
#include <string>


int myatoi(std::string str){
    int result = 0;
    int sign = 1;
    int i = 0;
    
    //invalid empty string
    if(str.length() == 0){
        return 0;
    }
    
    //take care of sign
    if(str[0] == '-'){
        sign = -1;
        i++;
    }
    
    //main loop
    for(; i < str.length(); i++){
        
        //invalid letter case
        if(str[i] < '0' || str[i] > '9'){
            return 0;
        }
        //valid string, 0 to 9
        else{
            //out of range exception
            if(result >= INT_MAX/10){
                result = result * 10 + (str[i] - '0');
            }
        }
    }
    
    return result * sign;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << myatoi("-1s23") << std::endl;
    
    return 0;
}
