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

bool isOnTile(vec2 pos, const vector<vec2>& tile){
    
    return false;
}

int main(int argc, const char * argv[]) {

    vec2 mouse {0.0f, 0.0f};
    vec2 PA {0.0f, 1.0f};
    vec2 PB {1.0f, 0.5f};
    vec2 PC {1.0f, -0.5f};
    vec2 PD {0.0f, -1.0f};
    vec2 PE {-1.0f, -0.5f};
    vec2 PF {-1.0f, 0.5f};
    

    vector<vec2> tile = {PA, PB, PC, PD, PE, PF};
    bool inside = isOnTile(mouse, tile);
    cout << "Inside: " << inside << endl;
    return 0;
}
