//
//  main.cpp
//  BlubbleSort
//
//  Created by Cesar Montero on 3/24/21.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {

    
    vector<int> numberset = {3, 4, 1, 6};
    bool ordered = false;
    int counter = 0;
    
    int currentnumber;
    int nextnumber;
    
    while(ordered == false){
        counter = 0;
        for(int i = 0; i < numberset.size() -1; i++){
            
            currentnumber = numberset.at(i);
            nextnumber = numberset.at(i + 1);
            if(currentnumber > nextnumber){
   
                numberset.at(i) = nextnumber;
                numberset.at(i + 1) = currentnumber;
                counter++;
            }
        }
        if(counter == 0){ordered = true;}
    }
    
    //print ordered list of numbers
    for(int i = 0; i < numberset.size(); i++){
        cout << numberset.at(i) << endl;
        
    }
    
    return 0;
}
