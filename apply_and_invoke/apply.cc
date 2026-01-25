#include <iostream>
#include <tuple>
#include <string>
#include <array>
#include <any>
#include <functional>

using namespace std::literals;

void func(int i, double d, std::string s)
{
	std::cout << "i = " << i << ", d = " << d << ", s = " << s << '\n';
}

void func2(int i, int d, int s)
{
	std::cout << "i = " << i << ", d = " << d << ", s = " << s << '\n';
}

int main()
{
	std::tuple<int, double, std::string>  numbers_tuple(1, 2.0, "three"s);
	std::apply(func, numbers_tuple);             // Calls func(1, 2.0, "three"s);
	std::array<int, 3> numbers{1, 2, 3};
	std::apply(func2, numbers);             // Calls func2(1, 2, 3);
}