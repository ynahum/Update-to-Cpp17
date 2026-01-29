#include <iostream>
#include <tuple>
#include <vector>

using namespace std::literals;

int main()
{

	constexpr uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		std::pair p1{42, 3.14};
		std::cout << "First element: " << p1.first << ", Second element: " << p1.second << '\n';
		std::tuple t1{1, 2.5, "example"s};
		std::cout << "Tuple elements: " << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << '\n';
		std::vector vec{1, 2, 3, 4, 5};
		std::cout << "Vector elements: ";
		for (const auto& v : vec) {
			std::cout << v << " ";
		}
		std::cout << '\n';
	} else if constexpr (TEST_NUMBER == 1){
		std::vector vec1{1, 2, 3, 4, 5};
		std::vector vec2{6, 7, 8, 9, 10};
		std::vector vec3{vec1, vec2}; // vector of vectors
		std::cout << "Vector elements:\n";
		size_t index{0};
		for (const auto& v : vec3) {
			std::cout << "vec: " << index << "\n";
			for (const auto& elem : v) {
				std::cout << elem << " ";
			}
			index++;
			std::cout << '\n';
		}
		std::cout << '\n';
	}

}