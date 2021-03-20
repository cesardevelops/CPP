//
//  main.cpp
//  Study
//
//  Created by Cesar Montero on 3/19/21.
//
//Determine if a point is inside of a triangle.
//Explanation: https://www.youtube.com/watch?v=H9qu9Xptf-w

#include <iostream>

using namespace std;

float GetTriangleArea(const float &x1, const float &y1, const float &x2, const float &y2, const float &x3, const  float &y3)
    {
        return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))/2);
    }

int main ()
    {

        float x1 = 0 ;
        float y1 = 0 ;
        
        float x2 = 10;
        float y2 = 10;
        
        float x3 = 30;
        float y3 = 0;
        
        float xp = 10;
        float yp = 11;
        
        float triangleArea =  GetTriangleArea(x1, y1, x2, y2, x3, y3);
        float A1 = GetTriangleArea(x1, y1, x2, y2, xp, yp);
        float A2 = GetTriangleArea(x1, y1, xp, yp, x3, y3);
        float A3 = GetTriangleArea(xp, yp, x2, y2, x3, y3);
        
        if(A1 + A2 + A3 == triangleArea )
            {
                cout << "point is inside" << endl;
            }
        else
            {
                cout << "point is  outside" << endl;
            }
        
    }
