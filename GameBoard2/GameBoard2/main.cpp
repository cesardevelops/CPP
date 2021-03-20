//
//  main.cpp
//  GameBoard2
//
//  Created by Cesar Montero on 3/19/21.
//

#include <iostream>
#include <vector>
using namespace std;

struct vec2
    {
        float x;
        float y;
    };

float GetCrossProduct(vec2 A, vec2 B)
    {
        return (A.x * B.y) - (A.y * B.x);
    }

vec2 GetVector(vec2 A, vec2 B)
    {
        vec2 vector;
        vector.x = B.x - A.x;
        vector.y = B.y - A.y;
        return vector;
    }

bool CheckSideVariation(const float &previous, const float &value)
    {
        if(previous != 0)
            {
                if(previous < 0 && value > 0) {return false;}
                if(previous > 0 && value < 0) {return false;}
            }
        return true;
    }


bool isOnTile(vec2 P, const vector<vec2>& tile)
    {
        //PAxAB
        float previous;
        vec2 PA = GetVector(P, tile.at(0));
        vec2 AB = GetVector(tile.at(0), tile.at(1));
        float PAxAB = GetCrossProduct(PA, AB);
        cout << PAxAB << endl;
        previous = PAxAB;
        
        //PBxBC
        vec2 PB = GetVector(P, tile.at(1));
        vec2 BC = GetVector(tile.at(1), tile.at(2));
        float PBxBC = GetCrossProduct(PB, BC);
        cout << PBxBC << endl;
        if(CheckSideVariation(previous, PBxBC) == false){return false;}

        //PCxCD
        vec2 PC = GetVector(P, tile.at(2));
        vec2 CD = GetVector(tile.at(2), tile.at(3));
        float PCxCD = GetCrossProduct(PC, CD);
        cout << PCxCD << endl;
        if(CheckSideVariation(previous, PCxCD) == false){return false;}
        
        //PDxDE
        vec2 PD = GetVector(P, tile.at(3));
        vec2 DE = GetVector(tile.at(3), tile.at(4));
        float PDxDE = GetCrossProduct(PD, DE);
        cout << PDxDE << endl;
        if(CheckSideVariation(previous, PDxDE) == false){return false;}
        
        //PExEF
        vec2 PE = GetVector(P, tile.at(4));
        vec2 EF = GetVector(tile.at(4), tile.at(5));
        float PExEF = GetCrossProduct(PE, EF);
        cout << PExEF << endl;
        if(CheckSideVariation(previous, PExEF) == false){return false;}
        
        //PFxFA
        vec2 PF = GetVector(P, tile.at(5));
        vec2 FA = GetVector(tile.at(5), tile.at(0));
        float PFxFA = GetCrossProduct(PF, FA);
        cout << PFxFA << endl;
        if(CheckSideVariation(previous, PFxFA) == false){return false;}
        
        //if all signs are posirive or negative, then the point is inside the hexagon
        //if so, return 1
        return 1;
        
    }

int main(int argc, const char * argv[])
    {
        vec2 mouse = {0.0f, -1.0f};
        vec2 A = {0.0f, 1.0f};
        vec2 B = {1.0f, 0.5f};
        vec2 C = {1.0f, -0.5f};
        vec2 D = {0.0f, -1.0f};
        vec2 E = {-1.0f, -0.5f};
        vec2 F = {-1.0f, 0.5f};
        
         /*
              a1
            /    \
           a6    a2
            |     |
           a5    a3
            \    /
              a4
         */
        
        vector<vec2> tile{A, B, C, D, E, F};
        bool inside = isOnTile(mouse, tile);
        cout <<  "Location(in = 1, out = 0):  " << inside << endl;
        
    }
