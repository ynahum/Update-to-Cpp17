#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>
#include <execution>

template<typename T, std::enable_if_t<std::is_same_v<T, int>, int> = 42>
void func1(T var) {
	std::cout << "func called with int: " << var << '\n';
}

// C++11 syntax
template<typename T, typename std::enable_if<std::is_same<T, int>::value, int>::type = 42>
void func2(T var) {
	std::cout << "func called with int: " << var << '\n';
}

int main()
{
	constexpr uint32_t TEST_NUMBER{2}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		func1(13);
	} else if constexpr (TEST_NUMBER == 1){
		//func1(3.14); // Error - no matching function
	} else if constexpr (TEST_NUMBER == 2) {
		func2(123);
	}

}