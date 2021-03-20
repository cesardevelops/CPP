//
//  main.cpp
//  GameBoard
//
//  Created by Cesar Montero on 3/19/21.
// https://tinyurl.com/53ezbstm

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct vec2
    {
        float x;
        float y;
    };

float cross (const vec2& a, const vec2& b)
    {
        return a.x * b.y - a.y * b.x;
    }

// return true if the mouse is inside the tile
//  returnf alse if the mouse is outside the tile
vec2 makeVector(vec2 A, vec2 B)
    {
        vec2 result;
        result.x = B.x - A.x;
        result.y = B.y - A.y;
        return result;
    }


bool isOnTile(vec2 P, const vector<vec2>& tile)
    {
        //Please implement this funciton
        
        //If all cross products have the same sign, then it is inside
        int previous;
        
        //PA x AB
        vec2 PA = makeVector(P, tile.at(0));
        vec2 AB = makeVector(tile.at(0), tile.at(1));
        float PAxAB = cross(PA, AB);
        cout << PAxAB << endl;
        previous = PAxAB;
        
        //PB x BC
        vec2 PB = makeVector(P, tile.at(1));
        vec2 BC = makeVector(tile.at(1), tile.at(2));
        float PBxBC = cross(PB, BC);
        cout << PBxBC << endl;
        if(previous!=0)
            {
                if(previous < 0 && PBxBC > 0){ return false; }
                if(previous > 0 && PBxBC < 0){ return false; }
            }
            
        //PC x CD
        vec2 PC = makeVector(P, tile.at(2));
        vec2 CD = makeVector(tile.at(2), tile.at(3));
        float PCxCD = cross(PC, CD);
        cout << PCxCD << endl;
        if(previous!=0)
            {
                if(previous < 0 && PCxCD > 0){ return false; }
                if(previous > 0 && PCxCD < 0){ return false; }
            }
        
        //PD x DE
        vec2 PD = makeVector(P, tile.at(3));
        vec2 DE = makeVector(tile.at(3), tile.at(4));
        float PDxDE = cross(PD, DE);
        cout << PDxDE << endl;
        if(previous!=0)
            {
                if(previous < 0 && PDxDE > 0){ return false; }
                if(previous > 0 && PDxDE < 0){ return false; }
            }
        
        //PE x EF
        vec2 PE = makeVector(P, tile.at(4));
        vec2 EF = makeVector(tile.at(4), tile.at(5));
        float PExEF = cross(PE, EF);
        cout << PExEF << endl;
        if(previous!=0)
            {
                if(previous < 0 && PExEF > 0){ return false; }
                if(previous > 0 && PExEF < 0){ return false; }
            }

        //PF x FA
        vec2 PF = makeVector(P, tile.at(5));
        vec2 FA = makeVector(tile.at(5), tile.at(0));
        float PFxFA = cross(PF, FA);
        cout << PFxFA << endl;
        if(previous!=0)
            {
                if(previous < 0 && PFxFA > 0){ return false; }
                if(previous > 0 && PFxFA < 0){ return false; }
            }
        

        return true;
    }

int main(int argc, const char * argv[])
    {
        vec2 mouse = {0.0f, 0.0f};
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



