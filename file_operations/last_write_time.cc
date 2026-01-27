#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	std::string filename{"test2.txt"};
	std::ofstream test(filename); // create file
	test.put('A'); // add a character to the file
	test.put('B'); // add a character to the file
	test.close();

	fs::path test_file{filename};
	std::cout << "test_file path is " << test_file << "\n";
	
	auto last_time = fs::last_write_time(test_file);

	// Convert file_time_type to system_clock time_point to print it
	auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
		last_time - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
	);

	std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);
	std::cout << "Last write time: " << std::asctime(std::localtime(&cftime));
}