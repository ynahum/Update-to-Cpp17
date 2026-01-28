#include <iostream>

//[[nodiscard]]
int function()
{
	return 42;
}

int main()
{

	constexpr uint32_t TEST_NUMBER{2}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		function(); // Warning - return value is discarded
	} else if constexpr (TEST_NUMBER == 1){
		[[maybe_unused]] int value = function(); // No warning - return value is used
	} else if constexpr (TEST_NUMBER == 2){
		auto a{3};
		switch (a)
		{
		case 3:
			std::cout << "In case 3\n";
			[[fallthrough]];
		case 4:
			std::cout << "In case 4\n";
			break;
		default:
			break;
		}
	}

}