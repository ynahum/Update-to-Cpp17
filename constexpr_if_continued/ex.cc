#include <iostream>

template<size_t N>
size_t func() {
	return func<N - 1>() + func<N - 2>();
}

template<>
size_t func<0>() {
	return 0;
}

template<>
size_t func<1>() {
	return 1;
}

template<size_t N>
size_t func2() {
	if constexpr (N <= 1) {
		return N;
	} else {
		return func2<N - 1>() + func2<N - 2>();
	}
}

int main()
{

	constexpr uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		constexpr size_t n{10};
		std::cout << "The " << n << "th Fibonacci number is: " << func<n>() << '\n';
	} else if constexpr (TEST_NUMBER == 1){
		constexpr size_t n{6};
		std::cout << "The " << n << "th Fibonacci number is: " << func2<n>() << '\n';
	}

}