#include <iostream>

int main()
{

	constexpr uint32_t TEST_NUMBER{2}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		[[maybe_unused]]
		constexpr auto func = []() constexpr{
			return 42;
		};
	} else if constexpr (TEST_NUMBER == 1){
		[[maybe_unused]]
		constexpr auto func = []() {
			return 42;
		};
	} else if constexpr (TEST_NUMBER == 2){
		constexpr auto a{3};
		//auto b{3};

		[[maybe_unused]]
		constexpr auto func = [&]() {
			//return b+1; // Error - b is not a constant expression
			return a + 1;
		};
	}

}