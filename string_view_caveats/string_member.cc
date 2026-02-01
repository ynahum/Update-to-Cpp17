#include <iostream>
#include <string>
#include <string_view>

using namespace std::literals;

class ref_member {
	public:
	const std::string& str;
	ref_member(const std::string& str) : str(str) {}
};

int main() {
	//std::string str{"A long none optimized string against short-string optimization"};
	//ref_member rm(str);
	ref_member rm1("test"s);     // Error
	std::cout << rm1.str << '\n';
	// also bad it just extends lifetime of temporary string
	ref_member rm2("A long none optimized string against short-string optimization"s);
	std::cout << rm2.str << '\n';

}