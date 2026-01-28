#include <iostream>
#include <any>

int main()
{

	constexpr uint32_t TEST_NUMBER{0}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		std::any a;
		if (!a.has_value()) {
			std::cout << "a is empty\n";
		}
		a = 42;
		if (a.has_value()) {
			std::cout << "a contains an int with value: " << std::any_cast<int>(a) << '\n';
		}
		a = std::string{"Hello, std::any!"};
		if (a.has_value()) {
			std::cout << "a contains a string with value: " << std::any_cast<std::string>(a) << '\n';
		}
		try {
			std::cout << "Attempting to cast a to int...\n";
			std::cout << std::any_cast<int>(a) << '\n'; // This will throw
		} catch (const std::bad_any_cast& e) {
			std::cout << "Caught bad_any_cast exception: " << e.what() << '\n';
		}
	} else if constexpr (TEST_NUMBER == 1){
	}

}