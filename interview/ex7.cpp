#include <iostream>
#include <functional>

int main() {
 int x = 5;
 std::function<int(int)> adder = [&x](int y) { return x + y; };
 x = 10;
 std::cout << adder(3) << std::endl;
 return 0;
}