#include <iostream>
#include <string_view>
#include <string>

int main()
{

	constexpr uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		std::string_view sv1{"Hello, World!"};
		std::cout << "Original string_view: " << sv1 << "\n";
		std::string_view sv2 = sv1.substr(7, 5); // Extract "World"
		std::cout << "Substring string_view: " << sv2 << "\n";

		std::string str{"Hello, C++!"};
		std::string_view sv3{str};
		std::cout << "String_view from std::string: " << sv3 << "\n";

		char arr[] = "Sample array";
		std::string_view sv4{arr}; // "Sample array"
		std::cout << "String_view from char array: " << sv4 << "\n";


	} else if constexpr (TEST_NUMBER == 1){
		std::string_view sv1{"Hello, World!"};
		sv1.remove_prefix(7); // Now sv1 is "World!"
		std::cout << "After remove_prefix(7): " << sv1 << "\n";
		sv1.remove_suffix(1); // Now sv1 is "World"
		std::cout << "After remove_suffix(1): " << sv1 << "\n";
		std::string str{sv1.data(), sv1.size()}; // Correct conversion to std::string
		std::cout << "Converted std::string: " << str << "\n";
		std::string str2{sv1.data()}; // Incorrect conversion to std::string
		std::cout << "Converted std::string: " << str2 << "\n";


	}

}