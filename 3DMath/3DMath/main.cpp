//
//  main.cpp
//  3DMath
//
//  Created by Cesar Montero on 3/22/21.
//

#include <iostream>
#include <vector>
using namespace std;

//Calculate  vector  from 2 points
vector<float> Get3DVector(vector<float> A, vector<float> B)
    {
        return {B.at(0) - A.at(0), B.at(1) - A.at(1), B.at(2) - A.at(2)};
    }

float GetMagnitude(vector<float> A)
    {
        return sqrt( pow(A.at(0), 2)  + pow(A.at(1), 2) + pow(A.at(2), 2));
    }

float GetDotProduct(vector<float> A, vector<float> B)
    {
        return (A.at(0) * B.at(0) + A.at(1) * B.at(1) + A.at(2) * B.at(2));
    }

float GetAngleInRadians(vector<float> A, vector<float> B)
    {
        return acos(
                GetDotProduct(A, B)
                /
                GetMagnitude(A) * GetMagnitude(B)
                    );
    }

vector<float> UnitVector(vector<float> A)
    {
        float magnitude = GetMagnitude(A);
        return {A.at(0)/magnitude, A.at(1)/magnitude, A.at(2)/magnitude};
    }

int main(int argc, const char * argv[])
    {
        //vector<float> vectorA = {0, 10, 0};
        //cout << GetMagnitude(vectorA);
        
        float RadtoDeg = 57.295779513;//180/3.1416
        vector<float> pointA{2, 3, 0};
        vector<float> pointB{-3, 2, 0};
        //vector<float> pointA{1,0,0};
        //vector<float> pointB{-1,0,0};
        vector<float> ABVector = Get3DVector(pointA, pointB);

        //cout << pointA.at(0);
        float RadiansResult = GetAngleInRadians(pointA, pointB);
        cout << "Vector: " << ABVector.at(0) << ", "<< ABVector.at(1) << ", " << ABVector.at(2) << endl;

        cout <<"Radians Result: " << RadiansResult * RadtoDeg << endl;
        return 0;
    }

