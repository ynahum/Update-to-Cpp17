#include <iostream>

class Test {
  public:
	Test() { std::cout << "Default constructor\n"; }
	Test(const Test& ) { std::cout << "Copying\n"; }
};

Test func() {
    Test t;
    return t; // Named object, candidate for NRVO
}

int main() {
	std::cout << "Calling func()\n";
	Test test = func();
	(void)test;
	std::cout << "Returned from func()\n";
}
