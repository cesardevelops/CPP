//
//  main.cpp
//  ShapePlotter
//
//  Created by Cesar Montero on 3/27/21.
//

#include <iostream>
#include <vector>
#include <array>
using namespace std;



int main(int argc, const char * argv[]) {

    //vector<int> myvector(10);
    //cout << myvector.size() << endl;
    
    
    const int rows = 20;
    const int cols = 20;
    string myarray[rows][cols];
    cout << sizeof(myarray)/sizeof(myarray[0]) << endl;
    //center
    int radius = 4;
    
    //Filled circle
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            myarray[r][c] = ". ";
            //plot entire filled circle
            if(   round(pow((r-10),2)) + round(pow((c-10),2)) <= round(pow((radius),2))   ){
                myarray[r][c] = "1 ";
            }
            //add back some dots
            if(   round(pow((r-10),2)) + round(pow((c-10),2)) <= round(pow((radius-1),2))   ){
                myarray[r][c] = ". ";
            }
            cout << myarray[r][c];
        }
        cout << endl;
    }
     
    return 0;
    
    
}
