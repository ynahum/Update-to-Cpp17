#include <iostream>
#include <charconv>
#include <string>

int main()
{

	constexpr uint32_t TEST_NUMBER{0}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		std::string str{"123ab"};
		int number{};
		auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), number, 16);
		if (ec == std::errc()) {
			std::cout << "Converted string to number: " << number << '\n';
		} else {
			std::cout << "Conversion failed\n";
		}
	} else if constexpr (TEST_NUMBER == 1){
		std::string str{"123.456"};
		double number{};
		auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), number);
		if (ec == std::errc()) {
			std::cout << "Converted string to number: " << number << '\n';
		} else {
			std::cout << "Conversion failed\n";
		}
	}

}