//
//  main.cpp
//  TestPractice
//
//  Created by Cesar Montero on 3/27/21.
//

#include <iostream>
#include <vector>
using namespace std;

struct vec2{
    float x;
    float y;
};



vec2 make2DVector(vec2 A, vec2 B){
    return {B.x - A.x, B.y - A.y};
}

float crossProduct2D(vec2 A, vec2 B){
    //returns 1, 0 or -1
    return (A.x * B.y) - (A.y * B.x);
}



bool isOnTile(vec2 pos, const vector<vec2>& tile){
    
    // vector of: mouse to point in hexagon
    vec2 PA = make2DVector(pos, tile.at(0));
    vec2 PB = make2DVector(pos, tile.at(1));
    vec2 PC = make2DVector(pos, tile.at(2));
    vec2 PD = make2DVector(pos, tile.at(3));
    vec2 PE = make2DVector(pos, tile.at(4));
    vec2 PF = make2DVector(pos, tile.at(5));
    
    //vector of: point in hexagon to point in hexagon
    vec2 AB = make2DVector(tile.at(0), tile.at(1));
    vec2 BC = make2DVector(tile.at(1), tile.at(2));
    vec2 CD = make2DVector(tile.at(2), tile.at(3));
    vec2 DE = make2DVector(tile.at(3), tile.at(4));
    vec2 EF = make2DVector(tile.at(4), tile.at(5));
    vec2 FA = make2DVector(tile.at(5), tile.at(0));
    
    float PAxAB = crossProduct2D(PA, AB);
    float PBxBC = crossProduct2D(PB, BC);
    float PCxCD = crossProduct2D(PC, CD);
    float PDxDE = crossProduct2D(PD, DE);
    float PExEF = crossProduct2D(PE, EF);
    float PFxFA = crossProduct2D(PF, FA);
    
    //Print Cross Products
    cout << PAxAB << endl;
    cout << PBxBC << endl;
    cout << PCxCD << endl;
    cout << PDxDE << endl;
    cout << PExEF << endl;
    cout << PFxFA << endl;
    cout << endl;
    //Check signs
    vector<float> results {PAxAB,PBxBC,PCxCD,PDxDE,PExEF,PFxFA};
    for(int i = 0; i < results.size() -1; i++){
        if(results.at(i) != 0){
            if(results.at(i) * results.at(i+1) < 0){return false;}
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {

    vec2 PM {0.0f, 0.0f};
    vec2 A {0.0f, 1.0f};
    vec2 B {1.0f, 0.5f};
    vec2 C {1.0f, -0.5f};
    vec2 D {0.0f, -1.0f};
    vec2 E {-1.0f, -0.5f};
    vec2 F {-1.0f, 0.5f};
    
    
    vector<vec2> tile = {A, B, C, D, E, F};
    bool inside = isOnTile(PM, tile);
    
    if(inside == true){
        cout << "Inside" <<  endl;
        
    }
    else {
        cout << "Outside" <<  endl;
        
    }
    
    return 0;
}



