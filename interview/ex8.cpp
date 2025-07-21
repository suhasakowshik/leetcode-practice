#include <iostream>

// class Engine {
// public:
//     Engine() { std::cout << "Engine Constructed\n"; }
//     ~Engine() { std::cout << "Engine Destroyed\n"; }
// };

// class Car {
// public:
//     Car() : engine() { std::cout << "Car Constructed\n"; }
//     ~Car() { std::cout << "Car Destroyed\n"; }
// private:
//     Engine engine;
// };

// int main() {
//     Car myCar;
//     return 0;
// }

class Base {
public:
    Base() { std::cout << "Base constructor\n"; }
    ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor\n"; }
    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}