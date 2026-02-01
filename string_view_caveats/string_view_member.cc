#include <iostream>
#include <string_view>
#include <string>

using namespace std::literals;

class ref_member {
	std::string_view str;
public:
	ref_member(std::string_view str): str(str) {}
	void print() { std::cout << str << '\n'; }
};

class local_member {
	std::string str;
public:
	local_member(std::string str): str(str) {}
	void print() { std::cout << str << '\n'; }
};

int main()
{
	//ref_member rm{"Long string to initialize the class"s};
	//rm.print();
	//ref_member rm2{"short"s};
	//rm2.print();

	// better to use pass by value and store string internally as we use the move semantics
	local_member lm{"Long string to initialize the class"s};
	lm.print();
	local_member lm2{"short"s};
	lm2.print();

}