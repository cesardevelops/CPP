//
//  main.cpp
//  ClassSubclassExcercise02
//
//  Created by Cesar Montero on 3/21/21.
//
/*
20: missing public:
34: initialize m_value
33: change private to protected so subclass can read it
25: need to add virtual word
29: pass by reference by making a variable on main to store message
31: missing ; after }
38: missing public:
39: call parent constructor Bar(ing val):Foo(val)
48: infinite loop, change type?
 
29: need to put virtual so that the method is called correctly
 */

#include <iostream>
#include <string>
using namespace std;

class Dog{
public:
    Dog(int num){
        std::cout << "Dog()" << std::endl;
        setID(num);
    }
    
    virtual ~Dog(){
        std::cout << "~Dog()" << std::endl;
    }
    void setID(int num){
        id = num;
    }
    void setName(std::string n){
        name = n;
    }
    virtual void bark(std::string message){
        cout << message << endl;
    }
    
protected:
    int id = 0;
    std::string name = "N/A";
    int age = 0;
    int weigh = 0;
    int barkCount = 5;
    
};

class ShihTzu : public Dog{
public:
    ShihTzu(int num):Dog(num){
        std::cout << "ShihTzu()" << endl;
    }
    ~ShihTzu(){
        std::cout << "~ShihTzu()"<< std::endl;
    }
    void bark(std::string message){
        for(int i = 0; i < barkCount; i++){
            std::cout << message << endl;
        }
    }
};

int main(int argc, const char * argv[]) {

    //Dog* Canito = new Dog(10);
    //Canito->setName("Canito");
    //delete Canito;
    
    Dog* Neo  = new ShihTzu(20);
    Neo->bark("woof!");
    delete Neo;
    
    return 0;
}
