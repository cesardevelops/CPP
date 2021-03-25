//
//  main.cpp
//  TwoNumberSum
//
//  Created by Cesar Montero on 3/25/21.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> numbers = {3, 5, -4, 8, 11, 1, -1, 6};
    int targetsum = 10;

    
    for(int i = 0; i < numbers.size(); i++){
        for(int j = 0; j < numbers.size(); j++){
            if(i != j){
                if(numbers.at(i) + numbers.at(j) == targetsum){
                    cout << numbers.at(i) << " + " << numbers.at(j) << " = " << targetsum << endl;
                    return 0;
                }
                
            }
            
        }
        
    }
    return 0;
}
