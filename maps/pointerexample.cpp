#include <iostream>
using namespace std;
void func(int& x) {
    x = x + 1;
}

int main() 
{   
    int a=5;
    func(a);
    cout<<a<<endl;
    return 0;
}