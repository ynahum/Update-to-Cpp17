#include <iostream>
#include <variant>
#include <string>

using namespace std::literals;

struct Test
{
	/* data */
	//Test() = default;
	Test(int ii, double dd, const std::string& ss) : i{ii}, d{dd}, s{ss} {}
private:
	int i;
	double d;
	std::string s;
};

int main()
{

	constexpr uint32_t TEST_NUMBER{0}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		std::variant<std::monostate, Test> var;
		var = Test{1, 2.0, "three"s};
	} else if constexpr (TEST_NUMBER == 1){
	}

}