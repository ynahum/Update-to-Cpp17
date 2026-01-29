#include <iostream>

class Test {
public:
	Test() {
		std::cout << "Default constructor called\n";
	}

	Test(const Test&) {
		std::cout << "Copy constructor called\n";
	}

	Test(Test&&) noexcept {
		std::cout << "Move constructor called\n";
	}
};

Test temp_object_test() {
	return Test();
}

Test nrvo_test() {
	Test test;
	return test;
}

int main()
{

	// to see the effect of copy elision in C++14:
	// g++ -std=c++14 -fno-elide-constructors ex.cc -o ex && ./ex
	const uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if (TEST_NUMBER == 0) {

		std::cout << "Creating test object...\n";
		[[maybe_unused]]
		Test test = temp_object_test();
		std::cout << "Test object created.\n";
	} else if (TEST_NUMBER == 1){
		// g++ -std=c++17  ex.cc -o ex && ./ex to see NRVO in action
		// g++ -std=c++17 -fno-elide-constructors ex.cc -o ex && ./ex to see no NRVO in action 
		// (it calls move constructor instead of eliding it)
		std::cout << "Creating test object with NRVO...\n";
		[[maybe_unused]]
		Test test = nrvo_test();
		std::cout << "Test object created with NRVO.\n";
	}

}