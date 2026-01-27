#include <iostream>
#include <fstream>
#include <filesystem>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	std::string filename{"test.txt"};
	std::ofstream test(filename); // create file
	test.put('A'); // add a character to the file
	test.put('B'); // add a character to the file
	test.close();

	// Create a path object
	fs::path test_file("test.txt");
	std::cout << "test_file path is " << test_file << '\n';
	
	// Get the size of the file in bytes
	std::cout << "Size of the file: " << fs::file_size(test_file) << " bytes\n";
}