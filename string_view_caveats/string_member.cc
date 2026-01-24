#include <iostream>
#include <string>

using namespace std::literals;

class ref_member {
	public:
	const std::string& str;
	ref_member(const std::string& str) : str(str) {}
};

int main() {
	//std::string str{"A long none optimized string against short-string optimization"};
	//ref_member rm(str);
	//ref_member rm("test"s);     // Error
	ref_member rm("A long none optimized string against short-string optimization"s);
	std::cout << rm.str << '\n';
}