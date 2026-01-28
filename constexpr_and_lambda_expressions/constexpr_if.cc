#include <iostream>

constexpr bool my_function()
{
	constexpr int n{4};
	
	if constexpr (n % 2 == 1) {
		//std::cout << "n is odd\n";			
		return true;
	} else {	
		//std::cout << "n is even\n";
		return false;
	}
}

int main()
{
	// no my_function is created in disassembly as it is constexpr
	// see objdump -d constexpr_if
	constexpr bool result = my_function();
	std::cout << std::boolalpha << result << '\n';			
	constexpr bool COMPILE_LAMBDA{false};
	if constexpr (COMPILE_LAMBDA) {
		// Using a lambda expression
		constexpr int n{4};
		[n] ()  {
			if constexpr (n % 2 == 1) {
				std::cout << "n is odd\n";			
				return true;
			} else {	
				std::cout << "n is even\n";
				return false;
			}
		}();
	}
}