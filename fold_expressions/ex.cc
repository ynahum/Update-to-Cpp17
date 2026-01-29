#include <iostream>
template <typename... Args>
auto add(Args... args) {
	return ("" + ... + args);    // Left fold
	// Equivalent to (((args1 + args2) + args3) + ...)
}
using namespace std::literals;

template <typename... Args>
std::ostream& print(std::ostream& os, Args... args) {
	(os << ... << args);    // Left fold
	return os;
}

template <typename... Args>
bool any_of(Args... args) {
	return (... || args);    // Left fold
	// Equivalent to ((args1 || args2) || args3)
}

int main()
{

	constexpr uint32_t TEST_NUMBER{2}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		//std::cout << "add(1, 2, 3, 4, 5, 6, 7, 8) gives " << add(1, 2, 3, 4, 5, 6, 7, 8) << '\n';
		std::cout << R"(add("1"s, "2"s, "3"s, "4"s) gives )" << add("1"s, "2"s, "3"s, "4"s) << '\n';
	} else if constexpr (TEST_NUMBER == 1){
		print(std::cout,"Hello, "s, "world!"s, "\n"s);
	} else if constexpr (TEST_NUMBER == 2){
		std::cout << std::boolalpha << any_of(false, false, true, false) << '\n';
	}

}