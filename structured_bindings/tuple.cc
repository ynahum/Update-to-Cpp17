#include <iostream>
#include <tuple>
#include <string>

using namespace std::literals;

int main()
{
#if __cplusplus < 201703L
	std::cout << "before C++17\n";	
	std::tuple<int, double, std::string> numbers = make_tuple(1, 2.0, "three"s);
	double d;
	int i;
	std::string str;

	std::tie(i, d, str) = numbers;                             // Store all elements in variables
	std::cout << "i = " << i << ", d = " << d << ", s = " << str << '\n';
#else
	std::cout << "C++17 or later is enabled\n";	
	std::tuple numbers = make_tuple(1, 2.0, "three"s);         // std::tuple<int, double, std::string>

	/*
	// C++11/14
	double d;
	int i;
	std::string str;

	std::tie(i, d, str) = numbers;                             // Store all elements in variables
	*/

	// C++17
	auto [i, d, str] = numbers;                                // Store all elements in variables

	std::cout << "i = " << i << ", d = " << d << ", s = " << str << '\n';
#endif
}