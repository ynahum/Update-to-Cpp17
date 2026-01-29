#include <iostream>
#include <charconv>

int main()
{

	constexpr uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		int a{42};
		char buffer[10];
		auto [ptr, ec] = std::to_chars(buffer, buffer + sizeof(buffer), a);
		if (ec == std::errc()) {
			std::cout << "Converted number to string: ";
			std::cout.write(buffer, ptr - buffer) << '\n';
		} else {
			std::cout << "Conversion failed\n";
		}
	} else if constexpr (TEST_NUMBER == 1){
		double a{42.53123456778876};
		char buffer[30];
		auto [ptr, ec] = std::to_chars(buffer, buffer + sizeof(buffer), a, std::chars_format::scientific, 5);
		if (ec == std::errc()) {
			std::cout << "Converted number to string: ";
			std::cout.write(buffer, ptr - buffer) << '\n';
		} else if (ec == std::errc::value_too_large) {
			std::cout << "value too large failed\n";	
		} else {
			std::cout << "Conversion failed\n";
		}
	}

}