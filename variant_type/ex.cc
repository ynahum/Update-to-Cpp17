#include <iostream>
#include <variant>
#include <string>

using namespace std::literals;

int main()
{

	constexpr uint32_t TEST_NUMBER{0}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		std::variant<std::string, int, double> var;
		std::cout << "Initial index of var: " << var.index() << "\n"; // Should be 0 (int)
		std::cout << "Initial value of var: " << std::get<std::string>(var) << "\n"; // Default int value 0

		var = 42; // var holds an int
		std::cout << "var holds int: " << std::get<int>(var) << "\n";

		var = 3.14; // var holds a double
		std::cout << "var holds double: " << std::get<double>(var) << "\n";

		var = "Hello, Variant!"s; // var holds a std::string
		std::cout << "var holds string: " << std::get<std::string>(var) << "\n";

		std::cout << "Current index of var: " << var.index() << "\n"; // Should be 2 (std::string)

		std::cout << "std::get_if<int>(&var): " << std::get_if<int>(&var) << "\n";
		if (auto intPtr = std::get_if<int>(&var);intPtr != nullptr) {
			std::cout << "Int value via get_if: " << *intPtr << "\n";
		}
		std::cout << "std::get_if<std::string>(&var): " << std::get_if<std::string>(&var) << "\n";
		if (auto strPtr = std::get_if<std::string>(&var);strPtr != nullptr) {
			std::cout << "String value via get_if: " << *strPtr << "\n";
		}

		if (auto isDouble = std::holds_alternative<double>(var); isDouble) {
			std::cout << "Variant holds a double: " << std::get<double>(var) << "\n";
		} else {
			std::cout << "Variant does not hold a double.\n";
		}
		if (auto isString = std::holds_alternative<std::string>(var); isString) {
			std::cout << "Variant holds a string: " << std::get<std::string>(var) << "\n";
		} else {
			std::cout << "Variant does not hold a string.\n";
		}

		// Attempt to get the wrong type
		try {
			std::cout << "Trying to get int from var: ";
			std::cout << std::get<int>(var) << "\n"; // This will throw
		} catch (const std::bad_variant_access& e) {
			std::cout << "Caught exception: " << e.what() << "\n";
		}
	} else if constexpr (TEST_NUMBER == 1){
	}

}