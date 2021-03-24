#include <string>
#include <iostream>

int myatoi(std::string &str){
    //check if the string is empty
    if(str == ""){
        return 0;
    }
    
    int result = 0;//store the resulting number here
    int sign = 1;//store the sign here
    int  i = 0;//store the current count here
    
    if(str[i] == '-'){
        sign = -1;
        i++;
    }
    
    for(; i<str.length(); i++){
        //Check if its not a number
        if(str[i] < '0' || str[i] > '9'){
            return 0;
        }
        //If it is a number
        else{
            //check for overflow
            if(result >= INT_MAX / 10){
                return 0;
            }
            result = (result * 10) + (str[i] - '0');
        }
    }
    
    return result * sign;
}


int main(){
    
    std::string mystring = "-123";
    std::cout << myatoi(mystring) << std::endl;
    return 0;
    
}


//CLASS BY CLEMENT BELOW
/*
 
     std::string -> int
     "123" -> 123
     "12a" -> 0
     " 12" -> 0
 

 //Behaviour
 + Going from left to right

     1) Check for sign, in fist character
         1.1 Store 1 or -1 in int, then we can multiply the result at the end
     2) For loop
         
         Increment: When we find a number, 0...9
         Stop: when the string is completed '\0'
         Edge cases:
             Anything that is not a number, return 0
             If its a string, return 0

 //int my_atoi(const char *str)

 // How to surface errors at the API level (C++)
 // - Exceptions: throw / catch
 // - extend your function
 //   `int my_atoi(std::string &str, int *err);`
 // - return a combination
 //   `result_t my_atoi(std::string &str);`

 struct result_t
 {
     int value = 0;
     bool error = false;
     std::string message = "";
 };

 enum class {
     kInvalidString = 0,
     kOverflow = 1,
 } errorType;

 int my_atoi(std::string &str, errorType *err)
 {
     bool requestedError = false;
     if (err != nullptr) {
         requestedError = true;
     }
     
     if (str.size() == 0) {
         if (requestedError) {
             *err = errorType::kInvalidString;
         }
     }
     
     if (str.size() == 0) {
         return {
             .error = true,
             .message = "empty string!",
         };
     }
     
     long int result = 0;
     int sign = 1;
     int i = 0;
     
     //Checking for sign
     if(str[0] == '-')
         {
             sign = -1;
             i++;
         }
         
     //calculating valid numbers
     // std::string
     // "123" -> .size() -> 3
     // C string -> const char*
     // "123\0"
     for(; i < str.size(); i++)
     for (; str[i] != '\0'; i++)
     {
             if(str[i] < '0' || str[i] > '9')
                 {
                     cout << ERROR: print character that is invalid<< endl;
                     return 0; //finish, its invalid
                 }
             else
                 {
                     //result += str[result]*10 + str[i] - '0';
                     
                     // check for overflow
                     if (result >= INT_MAX) {
                         return 0;
                     }
                     if (result >= INT_MAX / 10) {
                         
                     }

                     result = result * 10 + str[i] - '0';
                     //result = 1
                     //result = (1*10) + 2 = 12
                     //result = (12*10) + 3 = 123
                 }
         }
         
     return result * sign;
         
 }

 int main()
     {
         // Input edge cases:
         auto empty = "";
         auto valid = "123";
         auto invalid = "12a";
         auto negative = "-23";
         auto overflow = "112133213232132132131231231232132131231232121321";
         
         std::string mystring = "1234";
         cout << my_atoi(mystring) << endl;
         
         // if my_atoi fails, print error
         
         
         // How to use error thing.
         int giveMeErrorCode = 0;
         my_atoi("12a", &giveMeErrorCode);
         
         my_atoi("12a");
     }
 */
