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
//https://www.w3schools.com/cpp/cpp_files.asp

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

void ReadFile2()
    {
        int sum = 0;
        int x;
        ifstream inFile;
        
        inFile.open("test.txt");
        if (!inFile) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }
        
        while (inFile >> x) {
            sum = sum + x;
        }
        
        inFile.close();
        cout << "Sum = " << sum << endl;
        //return 0;
    }

void ReadFile3()
    {
        ifstream myReadFile;
        myReadFile.open("test.txt");
        char output[100];
        if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {


           myReadFile >> output;
           cout<<output;


        }
       }
       myReadFile.close();
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
        ReadFile3();
        return 0;
    }
