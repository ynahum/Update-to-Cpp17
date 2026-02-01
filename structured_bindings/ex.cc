#include <iostream>
#include <tuple>
#include <string>

using namespace std::literals;

struct TestStruct {
	int id;
	std::string name;
	double value;
};

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

	std::tuple<int, double, std::string> numbers = std::make_tuple(1, 2.0, "three"s);
	double d;
	int i;
	std::string str;

	std::tie(i, d, str) = numbers;                             // Store all elements in variables
	std::cout << "i = " << i << ", d = " << d << ", s = " << str << '\n';

	int id;
	std::string name;
	double value;
	TestStruct ts{1, "Test", 3.14};
	std::tie(id, name, value) = std::make_tuple(ts.id, ts.name, ts.value);
	std::cout << "id = " << id << ", name = " << name << ", value = " << value << '\n';
#else
	std::cout << "C++17 or later is enabled\n";	
	std::pair p1{42, "The answer"};
	auto [num, text] = p1; // Structured binding
	std::cout << "Number: " << num << ", Text: " << text << "\n";
	std::tuple numbers = std::make_tuple(1, 2.0, "three"s);         // std::tuple<int, double, std::string>
	auto [i, d, str] = numbers;                                // Store all elements in variables
	std::cout << "i = " << i << ", d = " << d << ", s = " << str << '\n';

	TestStruct ts{1, "Test"s, 3.14};
	auto [id, name, value] = ts; // Structured binding
	std::cout << "id = " << id << ", name = " << name << ", value = " << value << '\n';
#endif
	} else if (TEST_NUMBER == 1){
	}

}