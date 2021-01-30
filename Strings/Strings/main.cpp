//
//  main.cpp
//  Strings
//
//  Created by Cesar Montero on 1/29/21.
//  Copyright © 2021 Cesar Montero. All rights reserved.
//
/*
Input Format

You are given two strings,  and , separated by a new line. Each string will consist of lower case Latin characters ('a'-'z').

Output Format

In the first line print two space-separated integers, representing the length of  and  respectively.
In the second line print the string produced by concatenating  and  ().
In the third line print two strings separated by a space,  and .  and  are the same as  and , respectively, except that their first characters are swapped.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Complete the program
    string a, b;
    cin>>a;
    cin>>b;
    char wordA_first = a[0];
    char wordB_first = b[0];
    cout<<a.size()<<" "<<b.size()<<endl;
    cout<<a+b<<endl;
    a[0]=wordB_first;
    b[0]=wordA_first;
    cout<<a+" "+b<<endl;
    return 0;
}

