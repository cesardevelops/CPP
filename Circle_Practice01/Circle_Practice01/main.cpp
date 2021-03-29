//
//  main.cpp
//  Circle_Practice01
//
//  Created by Cesar Montero on 3/28/21.
//
/*
 Coding: write a function that will draw the outline of a circle of radius R within a NxM matrix.
 1) How would you fill the circle?
 */

#include <iostream>
#include <string>
#include <array>
using namespace std;

void DrawCircle(int &r){
//pow(r, 2) = pow(x - xcenter, 2) + pow(y - ycenter, 2)
    int gridsize = 30;
    int center = gridsize/2;
    int circle = 0;
    int circleThickness = 1;
    int rmax = round(pow(r, 2));
    int rmin  = round(pow(r - circleThickness, 2));
    
    for(int i = 0; i < gridsize; i++){
        for(int j = 0; j < gridsize; j++){
            circle = round(pow(i - center, 2) + pow(j - center, 2));
            if((circle <= rmax ) && (circle >= rmin)){
                cout << "1 ";
            }
            else{
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {

    int radius = 10;
    DrawCircle(radius);
    return 0;
}
