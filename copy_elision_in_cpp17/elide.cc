#include <iostream>

class Test {
  public:
	Test() { std::cout << "Default constructor\n"; }
    
	// Copy constructor with side effect
	Test(const Test& ) { std::cout << "Copying\n"; }
};

// Function returning a temporary object
Test func()
{
    return Test{};
}

int main()
{
	std::cout << "Calling func()\n";
	
	// How many times is "Copying" printed out?
	Test test = func();

	(void)test;  // To avoid unused variable warning
	
	// in c++14 we can disable copy elision with -fno-elide-constructors but in C++17 copy elision is mandatory in this case
	// g++ -std=c++14 -fno-elide-constructors copy_elision_in_cpp17/elide.cc -o copy_elision_in_cpp17/elide && ./copy_elision_in_cpp17/elide
	std::cout << "Returned from func()\n";
}
