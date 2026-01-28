#include <iostream>
#include <tuple>
#include <string>
#include <functional>

using namespace std::literals;

int main()
{
	constexpr uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		auto func = [](int a, double b, const std::string& s) {
			std::cout << "Hello world apply! " << a << ", " << b << ", " << s << '\n';
		};
		std::apply(func, std::make_tuple(1, 2.5, "example"s));
	} else if constexpr (TEST_NUMBER == 1){
		std::invoke([](int a, double b, const std::string& s) {
			std::cout << "Hello world invoke! " << a << ", " << b << ", " << s << '\n';
		}, 1, 2.5, "example"s);
	}


}