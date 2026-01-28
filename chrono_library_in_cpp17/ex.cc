#include <iostream>
#include <chrono>

namespace sc = std::chrono;
using namespace std::literals;  // For suffixes

int main()
{

	constexpr uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		//sc::seconds s1 = 1023ms;                           // Error - data would be lost
		
		// explicit duration_cast
		sc::seconds s2 = sc::duration_cast<sc::seconds>(5043ms);     // OK - but s is truncated to 5 seconds
		std::cout << "5043ms converted to " << s2.count() << " seconds\n";
		
		sc::seconds s3 = sc::duration_cast<sc::seconds>(-5043ms);     // OK - but s2 is truncated to -5 seconds
		std::cout << "-5043ms converted to " << s3.count() << " seconds\n";
	} else if constexpr (TEST_NUMBER == 1){
		sc::seconds s1 = sc::floor<sc::seconds>(1023ms);
		std::cout << "1023ms converted to " << s1.count() << " seconds using floor\n";
		sc::seconds s2 = sc::ceil<sc::seconds>(5043ms);
		std::cout << "5043ms converted to " << s2.count() << " seconds using ceil\n";
		sc::seconds s3 = sc::round<sc::seconds>(5043ms);
		std::cout << "5043ms converted to " << s3.count() << " seconds using round\n";
		sc::seconds s4 = sc::round<sc::seconds>(5500ms);
		std::cout << "5053ms converted to " << s4.count() << " seconds using round\n";
	}

}