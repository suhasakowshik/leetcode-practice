#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{   
    int var=10;

    int *ptr1=&var;
    int **ptr2=&ptr1;

    cout<<*ptr1<<"\n";
    cout<<**ptr2<<"\n";

    return 0;
}