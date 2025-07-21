//diamond inheritence

#include<iostream>
using namespace std;

struct Base
{
    virtual void foo()=0;
    Base() { }
};

struct Derived : Base
{
    void foo() {cout<<"Derived \n";}
};


class A {
    public:
        int x;
        void foo() {cout<<"A::foo\n";}
};

class B:virtual public A {};
class C:virtual public A {};

class D:public B,public C {};


// class MyClass
// {
//     public:
//         static int count;
//         MyClass() {count++;}
// };

// int MyClass::count=0;

class Shape {
public:
    virtual double area() = 0; 
};

class Circle : public Shape {
double radius;
public:
    Circle(double r) : radius(r) {}
    double area() { return 3.14 * radius * radius; }
};

class Square : public Shape {
double side;
public:
    Square(double s) : side(s) {}
    double area() { return side * side; }
};

class MyClass {
private:
  int value;
public:
  MyClass(int val) : value(val) {}
  int getValue() const {
    cout<<value<<endl;
    return value;
  }
  void setValue(int val) {
    value = val;
  }
};

int main()
{
    // Derived d;
    // d.foo();

    // D d;
    // d.foo();

    // MyClass obj1;
    // MyClass obj2;

    // cout<<MyClass::count<<endl;

    //Shape* shapePtr;
    //Shape* shapePtr = new Circle(5.0);
    //Shape* shapePtr = new Square(4.0);
    //Shape shapeObj;

    const MyClass obj(10);
    //obj.setValue(20);
    //obj.value=20;
    obj.getValue();

    return 0;
}
