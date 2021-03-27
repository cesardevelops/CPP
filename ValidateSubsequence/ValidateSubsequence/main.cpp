//
//  main.cpp
//  ValidateSubsequence
//
//  Created by Cesar Montero on 3/25/21.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
    vector<int> mysequence = {1, 6, -1, 10, 100};
    //int arrIndex = 0;
    
    
    int index = 0;
    
    //This for scans through the whole main array
    for(int i = 0; array.size(); i++){
        
        if(index == mysequence.size()){
            break;
            
        }
        if(mysequence.at(index) == array.at(i)){
            index += 1;
        }
    }
    
    //This means that for each number in mysquence, a +1 was added
    if(index == mysequence.size()){cout << "both arrays are equal"  << endl;}
    else{cout << "they are not equal" << endl;}
    
    return 0;
    


}

    /*
    int seqIndex = 0;
    for(int a = 0; a < arr.size(); a++){
        if(seqIndex == seq.size()){//we reach the end of the array
            break;
        }
        if(seq.at(seqIndex) == arr.at(a)){
            seqIndex +=  1;//each time we find a match we increase
        }
    }
    //if all elements were a match, then  the  size of subsequence equals the counter
    if(seqIndex == seq.size()){cout <<  "true"<< endl;} else{cout << "false" << endl;}
}
*/
