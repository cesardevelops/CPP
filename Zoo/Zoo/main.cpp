//
//  main.cpp
//  Zoo
//
//  Created by Cesar Montero on 2/1/21.
//
//https://www.geeksforgeeks.org/inheritance-in-c/
//https://www.youtube.com/watch?v=gq2Igdc-OSI
//https://www.youtube.com/watch?v=DHAAy4GJ684
//https://medium.com/@VIRAL/mac-xcode-and-c-file-handling-78ba999032df

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void ReadFile()
    {
        cout << "opening data1.txt....\n";
        ifstream infile("test.txt");
        int n=0;
     
        if (infile.is_open())
        {
            while (infile >> n)
            {
                
                cout << n;
                
                cout<<"\b";
                
            }
            infile.close();
        }
        else
        {
            cout<<"ERROR";
        }
    }

class Animal
    {
        private:


        protected:
            float friendly = 0;
            int ID;
            float weight;
        public:
            void setID(int x)
                {
                    ID = x;
                }
            int getID()
                {
                    return ID;
                }
            void setWeight(float w)
                {
                    weight = w;
                }
            float getWeight()
                {
                    return weight;
                }
            void increaseFriendly()
                {
                    friendly += 1;
                }
            void setFriendly(float f)
                {
                    friendly = f;
                }
    };

class Dog : public Animal
    {
        private:
            string breed;
            string name = "Dog";

        public:
            void setBreed(string b)
                {
                    breed = b;
                }
        string getBreed()
            {
                return breed;
            }

        void pet()
            {
                if(friendly<5)
                    {
                        cout<<name<<": GRRRR..."<<endl;
                    }
                else
                    {
                        cout<<name<<": Wooof!!"<<endl;
                    }
            }
    };

int main(int argc, const char * argv[])
    {
        Dog Link;
        Link.setID(1);
        Link.setFriendly(5);
        Link.pet();
        
        Dog Grumps;
        Grumps.setID(2);
        Grumps.setFriendly(1);
        Grumps.pet();
        //cout << Link.getID() << endl;
        ReadFile();
        return 0;
    }
