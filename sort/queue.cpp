#include<iostream>
#include<queue>

using namespace std;

// First in First out 

int main()
{   
    queue<int> numbers;

    cout<<"size: "<<numbers.size()<<endl;

    numbers.push(8);
    numbers.push(5);
    numbers.push(3);

    cout<<"Front: "<<numbers.front()<<endl;
    cout<<"Back: "<<numbers.back()<<endl;

    numbers.pop();

    cout<<"Front: "<<numbers.front()<<endl;
    cout<<"Back: "<<numbers.back()<<endl;

    return 0;
}