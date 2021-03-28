//
//  main.cpp
//  ShapePlotter
//
//  Created by Cesar Montero on 3/27/21.
//

#include <iostream>
#include <array>
using namespace std;

int main(int argc, const char * argv[]) {

    const int rows = 20;
    const int cols = 20;
    string myarray[rows][cols];
    //cout << sizeof(myarray)/sizeof(myarray[0]) << endl;
    //center
    int radius = 4;
    float circle;
    //Filled circle
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            myarray[r][c] = ". ";
            //plot entire filled circle
            circle = round(pow((r-10),2)) + round(pow((c-10),2));
            float rmax = round(pow(radius,2));//max radius
            float rmin = 2;//where to start filling with 1s
            if(circle  <= rmax && circle >= rmin ){
                myarray[r][c] = "1 ";
            }
            cout << myarray[r][c];
        }
        cout << endl;
    }
    return 0;
}
