#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

class Encapsulation
{

private:
    int x;
public:
    void setter(int a) {x=a;}
    int getter() {return x;}

};

class abstraction
{

private:
    int p,q;
public:
    void setter(int x,int y)
    {
        p=x;
        q=y;
    }
    void display()
    {
        cout<<"p: "<<p<<"\n";
        cout<<"q: "<<q<<"\n";
    }

};

class funcOverloading
{

public:
    void func(int x)
    {
        cout<<"Value of X is : "<<x<<endl;
    }
    void func(double x)
    {
        cout<<"Value of X is : "<<x<<endl;
    }
    void func(int x,int y)
    {
        cout<<"Value of X is : "<<x<<", Value of y is : "<<y<<endl;
    }

};

class opOverload
{
private:
    int real,imag;

public:
    opOverload(int r=0,int i=0)
    {
        real=r;
        imag=i;
    }

    opOverload operator+(opOverload const& obj)
    {
        opOverload op;
        op.real=real+obj.real;
        op.imag=imag+obj.imag;
        return op;
    }

    void print()
    {
        cout<<real<<" + "<<imag<<"i\n";
    }
};

class runtimePoly
{
public:
    virtual void print()
    {
        cout<<"print base class "<<endl;
    }
    void show()
    {
        cout<<"Show base class"<<endl;
    }
};

class derived : public runtimePoly
{
    void print() { cout<<"print derived class"<<endl; }
    void show() {cout<<" show derived class "<<endl;}
};

class Person
{
    int id;
    char name[100];

public: 
    void set_p(int id,char* name)
    {
        strcpy(this->name,name);
        this->id=id;
    }
    void display_p()
    {
        cout<<endl<<id<<"\t"<<name<<"\t";
    }
};

class Student : private Person
{
    char course[50];
    int fee;

public:
    void set_s(int id, char* name, char* course, int fee)
    {
        set_p(id, name);

        strcpy(this->course, course);

        this->fee = fee;
    }

    void display_s()
    {
        display_p();

        cout << course << "\t" << fee << endl;
    } 
};


int main()
{
    Encapsulation obj;
    abstraction abs;
    funcOverloading fover;
    opOverload opo1(15,3), opo2(3,5);

    runtimePoly* bptr;
    derived d;
    bptr=&d;

    // obj.setter(13);
    // cout<<obj.getter()<<endl;

    // abs.setter(1,2);
    // abs.display();

    // fover.func(1);
    // fover.func(2.3);
    // fover.func(1,2);

    // opOverload opo3=opo1+opo2;
    // opo3.print();

    // bptr->print();
    // bptr->show();

    Student s;
    char name[] = "XYZ";
    char course[] = "ABC";
    s.set_s(132451, name, course, 100000);
    s.display_s();

}