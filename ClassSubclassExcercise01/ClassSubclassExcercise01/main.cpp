//
//  main.cpp
//  ClassSubclassExcercise01
//
//  Created by Cesar Montero on 3/20/21.
//
//How to make Classes: https://www.youtube.com/watch?v=ABRP_5RYhqU
//Parent, Child class: https://www.youtube.com/watch?v=jTS7JTud1qQ
//When too use . : or :: - https://tinyurl.com/ph7tkzx6
//Constructor: https://tinyurl.com/yzk8e7he
//Constructors: https://www.youtube.com/watch?v=_b7odUc7lg0
//https://stackoverflow.com/questions/4475634/c-pass-a-string

#include <iostream>
#include <string>


class Foo
    {
    //PROBLEM: Missing Public
    public:
        Foo(int value)
            {
                std::cout << "Foo()" << std::endl;
                m_value = value;
            }
        //PROBLEM: need to make base destructor virtual to make sure derived class is destroyed properly
        virtual ~Foo()
            {
                std::cout << "~Foo()" << std::endl;
            }
        //PROBLEM: This method needs to be virtual so that the subclass method can be called
        //PROBLEM: Could use reference instead of copying string
        virtual void print(std::string message)
            {
                std::cout << "Foo:print() " << message << std::endl;
            }
        //PROBLEM: Need to change from private to protected for subclases to reach
        protected:
        // PROBLEM: m_value was not innitialized before,
        // PROBLEM: type was int, changed to unsigned int
        int m_value = 5;
    };// PROBLEM: it was missing a semicolon


class Bar : public Foo
    {
    //PROBLEM: Missing Public
    public:
        //PROBLEM: Need to call also the parent class which is expecting a value by default.
        Bar(int val):Foo(val)
            {
                std::cout << "Bar()" << std::endl;
            }
        ~Bar()
            {
                std::cout << "~Bar()" << std::endl;
            }
        //PROBLEM: Could use reference instead of copying string
        void print(std::string message)
            {
                //PROBLEM: since it is unsigned, it can jump to max of unsigned once it goes negative
                for(int i = m_value; i >= 0; --i)
                std::cout << "Bar::print() " << message << std::endl;
            }
    };

int main(int argc, const char * argv[])
    {
        // insert code here...
        //Add a subclass with specialized print() function for printing text multiples times
        
        Foo* myBar = new Bar(2);
        //std::string ;
        //myBar->print(std::string("Hello from main"));
        myBar->print("Hello from main");
        delete myBar;
        
        
    }
