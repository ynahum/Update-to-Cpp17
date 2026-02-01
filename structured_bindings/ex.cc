#include <iostream>
#include <tuple>
#include <string>

using namespace std::literals;

int main()
{

	uint32_t TEST_NUMBER{0}; // Change this value to test different scenarios

	if (TEST_NUMBER == 0) {

#if __cplusplus < 201703L
	std::cout << "before C++17\n";	
	std::pair<int, std::string> p1 = std::make_pair<int, std::string>(42, "The answer");
	int num;
	std::string text;
	std::tie(num, text) = p1;
	std::cout << "Number: " << num << ", Text: " << text << "\n";

	std::tuple<int, double, std::string> numbers = make_tuple(1, 2.0, "three"s);
	double d;
	int i;
	std::string str;

	std::tie(i, d, str) = numbers;                             // Store all elements in variables
	std::cout << "i = " << i << ", d = " << d << ", s = " << str << '\n';
#else
	std::cout << "C++17 or later is enabled\n";	
	std::pair p1{42, "The answer"};
	auto [num, text] = p1; // Structured binding
	std::cout << "Number: " << num << ", Text: " << text << "\n";
	std::tuple numbers = make_tuple(1, 2.0, "three"s);         // std::tuple<int, double, std::string>
	auto [i, d, str] = numbers;                                // Store all elements in variables
	std::cout << "i = " << i << ", d = " << d << ", s = " << str << '\n';
#endif
	} else if (TEST_NUMBER == 1){
	}

}