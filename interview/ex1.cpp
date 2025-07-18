#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;

int main()
{   
    int var=10;

    int *ptr1=&var;
    int **ptr2=&ptr1;

    cout<<*ptr1<<"\n";
    cout<<**ptr2<<"\n";

    int* p=new int[10];
    *p=5;

    cout<<"P : "<<*p<<"\n";

    delete p;

    auto p1 = make_unique<int>(5);  // creates a unique_ptr managing an int initialized to 5

    *p1 = 5;  // optional here, since it's already 5 from make_unique<int>(5)
    
    std::cout << "Value pointed by p1: " << *p1 << "\n";
    std::cout << "Raw pointer (address): " << p1.get() << "\n";  // shows address, not value



    return 0;
}