#include <iostream>
#include <memory>

struct Resource {
    int data;
    Resource(int d) : data(d) { std::cout << "Resource acquired: " << data << std::endl; }
    ~Resource() { std::cout << "Resource released: " << data << std::endl; }
};

struct MyDeleter {
    void operator()(Resource* res) {
        std::cout << "Custom deleter called for: " << res->data << std::endl;
        delete res;
    }
};


class A {};

class B : public A {};

class C : public B {};

int main() {
    //std::unique_ptr<Resource, MyDeleter> ptr(new Resource(42));
    C c;
    std::cout<<sizeof(c)<<std::endl;
    return 0;
}