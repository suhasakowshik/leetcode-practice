#include<iostream>
#include<stack>

using namespace std;

class Employee
{
public:
    int days;

    Employee(int days)
    {
        cout<<" Constructor called "<<days<<endl;
        this->days=days;
    }

    Employee(const Employee &employee)
    {
        cout<<"Copy constructor called"<<employee.days;
        cout<<endl;
        this->days = employee.days;
    }
    
    ~Employee()
    {
        cout<<"Destuctor called "<<days<<endl;
    }
};

int main()
{
    stack<int> numbers;
    cout<<"Size: "<<numbers.size()<<endl;

    if(numbers.empty())
    {
        cout<<"Stack is empty. "<<endl;
    }

    numbers.push(8);

    cout<<"Size : "<<numbers.size()<<endl;

    cout<<"top : "<<numbers.top()<<endl;

    numbers.push(9);
    numbers.push(5);

    stack<int> other_stack;
    other_stack.push(4);
    other_stack.swap(numbers);

    cout<<"Other_stack size: "<<other_stack.size()<<endl;
    cout<<"numbers stack size: "<<numbers.size()<<endl;

    cout<<"Elements of other stack: \n";
    while(!other_stack.empty())
    {
        cout << other_stack.top() << " ";
        other_stack.pop();
    }
    cout<<endl;

    cout<<"Elements of numbers stack: \n";
    while(!numbers.empty())
    {
        cout << numbers.top() << " ";
        numbers.pop();
    }
    cout<<endl;


    stack<Employee> employee_stack;
    Employee joe(10);

    employee_stack.push(joe);

    employee_stack.emplace(20);

    employee_stack.pop();

    return 0;
}