#include<iostream>
using namespace std;

class Base
{
    public:
        virtual void speak()
        {
            cout<<"Base\n";
        }
};

class Derived : public Base
{
    public:
        void speak()
        {
            cout<<"Derived\n";
        }
};

void SayHi(Base& b)
{
    b.speak();
}

class Resource
{
    int* data;
    public:
        Resource(int val) {data=new int(val); }
        ~Resource() {delete data;}
};

int main()
{   
    // Derived d;
    // SayHi(d);

    Resource r1(42);
    Resource r2=r1;

    return 0;
}