#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>
#include <execution>

void print_vector(const std::vector<int>& vec) {
	std::cout << "Vector contents: ";
	for (const auto& v : vec) {
		std::cout << v << " ";
	}
	std::cout << '\n';
}

int main()
{
	std::vector vec{3,1,4,1,5,9};

	constexpr uint32_t TEST_NUMBER{3}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		try {
			//std::sort(begin(vec), end(vec));
			std::sort(begin(vec), end(vec), [](int a, int b) {
				return a > b; }
				);
		}
		catch (std::exception& e) {
			std::cout << "Caught exception: " << e.what() << '\n';
		}
		// print the sorted vector
		print_vector(vec);
		return 0;
	} else if constexpr (TEST_NUMBER == 1){
		try {
			//std::sort(begin(vec), end(vec));
			std::sort(begin(vec), end(vec), [](int a, int b) {
				throw std::out_of_range("Oops");
				return a > b; }
				);
		}
		catch (std::exception& e) {
			std::cout << "Caught exception: " << e.what() << '\n';
		}
		// print the sorted vector
		print_vector(vec);	
		return 0;
	} else if constexpr (TEST_NUMBER == 2) {
		using namespace std::execution;
		namespace se = std::execution;
		std::sort(se::par_unseq, begin(vec), end(vec));
		// print the unsorted vector
		print_vector(vec);	
		return 0;
	} else if constexpr (TEST_NUMBER == 3) {
		using namespace std::execution;
		namespace se = std::execution;
		try {
			//std::sort(begin(vec), end(vec));
			std::sort(se::par_unseq, begin(vec), end(vec), [](int a, int b) {
				throw std::out_of_range("Oops");
				return a > b; }
				);
		}
		catch (std::exception& e) {
			std::cout << "Caught exception: " << e.what() << '\n';
		}
		// print the sorted vector
		print_vector(vec);	
		return 0;
	}

}