#include <iostream>
#include <string>
#include <type_traits>

template<typename T>
std::string get_string1(const T& arg) {
	if (std::is_same<std::string, T>::value)
		return arg;
	else
		return to_string(arg);
}

template<typename T>
std::string get_string2(const T& arg) {
	if constexpr (std::is_same_v<std::string, T>)
		return arg;
	else
		return std::to_string(arg);
}

int main()
{
	constexpr uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		std::cout << get_string1(42) << '\n';
	} else if constexpr (TEST_NUMBER == 1){
		std::cout << get_string2(32) << '\n';
	}

}