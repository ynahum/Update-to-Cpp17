#include <iostream>
#include <unordered_map>
#include <string>
int main()
{
	std::unordered_map<std::string, int> umap = {
		{"Alice", 30},
		{"Bob", 25},
		{"Charlie", 35}
	};

	constexpr uint32_t TEST_NUMBER{0}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {

		// pre C++17, we would need to access elements via iterators or keys
		auto result = umap.insert({"Diana", 28});
		if (result.second) {
			std::cout << "Inserted Diana successfully.\n";
		} else {
			std::cout << "Diana already exists in the map.\n";
			std::cout << "Diana is " << umap["Diana"] << " years old.\n";
		}

		std::cout << "Using iterators to access elements:\n";
		for (auto it = umap.begin(); it != umap.end(); ++it) {
			std::cout << it->first << " is " << it->second << " years old.\n";
		}
	} else if constexpr (TEST_NUMBER == 1){
		
		if (auto [iter, inserted] = umap.insert({"Diana", 28}); inserted) {
			std::cout << "Inserted Diana successfully.\n";
		} else {
			std::cout << "Diana already exists in the map.\n";
			std::cout << "Diana is " << umap["Diana"] << " years old.\n";
		}
		// C++17 structured bindings to access elements
		std::cout << "Using structured bindings to access elements:\n";
		for (const auto& [name, age] : umap) {
			std::cout << name << " is " << age << " years old.\n";
		}
	}

}