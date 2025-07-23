#include<iostream>
#include<memory>
using namespace std;


// inherttence
class Animal
{
    public:
        void speak()
        {
            cout<<"Iam an animal\n";
        }

};

class Dog : public Animal
{
    public:
        void bark()
        {
            cout<<"Dog says Bark \n";
        }
};

// polymorphism
//Same interface, different behavior. Achieved via virtual functions.

class Animals
{
    public:
        virtual void sound()
        {
            cout<<"Some sound\n";
        }


};

class Cat : public Animals
{
    public:
        void sound() {cout<<"Meow\n";}
};

void MakeSound(Animals* a)
{
    a->sound();
}


// Abstraction
// Hiding complex implementation and showing only the interface.
// Shape is abstract — only defines interface. Circle provides implementation.

class Shape
{
public:
    virtual double area()=0;
};

class Circle : public Shape
{
    double r;
    public:
    Circle(double radius):r(radius) {}
    double area() override {return 3.1416*r*r;}
};

int main()
{   
    // Cat c;
    // MakeSound(&c);

    // Shape* s = new Circle(5);
    // delete s;
    // unique_ptr<Shape> s=make_unique<Circle>(5);
    // cout<<"Area : "<<s->area()<<endl;
    
    int arr[] = {10, 20, 30};
    int* ptr = arr;

    std::cout << *ptr++ << "\n";     // prints 10, ptr → arr[1]
    ptr = arr;
    std::cout << (*ptr)++ << "\n";   // prints 10, arr[0] becomes 11

    return 0;
}