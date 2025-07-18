#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/* 

#include<bits/stdc++.h>
unique_ptr:-  stores one pointer only at a time. 
              We cannot copy unique_ptr, only transfer ownership of the object to another unique_ptr using the move() method.


 shared_ptr:  more than one pointer can point to same object at a time, and 
              it will maintain a reference counter using the use_count() method.

              
    It destroys itself when it goes out of its scope
*/

class rectangle
{
    int length;
    int breadth;

    public:
        rectangle(int l,int b)
        {
            length=l;
            breadth=b;
        }
        int area() { return length*breadth; }
};


int main()
{   
    // unique_ptr<rectangle> P1(new rectangle(10,5));
    // cout<<P1->area()<<endl;

    // unique_ptr<rectangle> P2;

    // //copy
    // P2=move(P1);
    // cout<<P2->area()<<endl;

    shared_ptr<rectangle> P1(new rectangle(10,5));
    cout<<P1->area()<<"\n";
}