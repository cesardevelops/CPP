//
//  main.cpp
//  ClassLearning
//
//  Created by Cesar Montero on 1/31/21.
//

#include <iostream>
#include <vector>
using namespace std;


//Get the vector between two points
//the vector((Bx-Ax), (By-Ay))
vector<int> GetVector(vector<int> A, vector<int> B)
    {
        //return {1,2};
        return {A.at(0) - B.at(0), A.at(1) - B.at(1), A.at(2) - B.at(2)};
    }

//Get the dot product of two vectors
float GetDotProduct(vector<int> A, vector<int> B)
    {
        return (A.at(0) * B.at(0)) + (A.at(1) * B.at(1)) + (A.at(2) * B.at(2));
    }

float GetMagnitude(vector<int> A)
    {
        return sqrt(A.at(0)*A.at(0) + A.at(1)*A.at(1) + A.at(2)*A.at(2));
    }

//Find the angle between two vectors
float GetAngleRadians(vector<int> A, vector<int> B)
    {
        return acos(
                     GetDotProduct(A, B)
                     /
                     (GetMagnitude(A) * GetMagnitude(B))
                    );
    }

//Find the unit vector
vector<int> GetUnitVector(vector<int> A)
    {
        vector<int> unitVector;
        float magnitude = GetMagnitude(A);
        unitVector.at(0) = unitVector.at(0) / magnitude;
        unitVector.at(1) = unitVector.at(1) / magnitude;
        unitVector.at(2) = unitVector.at(2) / magnitude;
        return unitVector;
    }

int main(int argc, const char * argv[])
    {
        float RadtoDeg = 57.295779513;
        vector<int> pointA{1,-1,1};
        vector<int> pointB{1,1,-1};
        vector<int> ABVector = GetVector(pointA, pointB);
        float RadiansResult = GetAngleRadians(pointA, pointB);
        cout << "Vector: " << ABVector.at(0) << ", "<< ABVector.at(1) << ", " << ABVector.at(2) << endl;

        cout <<"Radians Result: " << RadiansResult * RadtoDeg << endl;
        return 0;
    }

