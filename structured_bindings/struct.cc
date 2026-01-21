#include <iostream>
#include <string>

using namespace std::literals;

struct Numbers {
	int x;
	double y;
	std::string z;
};

int main()
{
#if __cplusplus < 201703L
	std::cout << "before C++17\n";	
	Numbers numbers{1, 2.0, "three"s};
	int i = numbers.x;
	double d = numbers.y;
	std::string s = numbers.z;
#else
	Numbers numbers{1, 2.0, "three"s};

	// C++17
	auto [i, d, s] = numbers;

#endif
	std::cout << "i = " << i << ", d = " << d << ", s = " << s << '\n';
}