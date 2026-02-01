#include <iostream>

int main()
{
	int i = 0x2a;
	std::cout << "i: " << i << "\n";
	
	// Is f a hexadecimal digit or a type suffix?
	// auto ambig = 0x2.f;                         // Error: hex floating constants require an exponent

	double d1 = 0xA.8p2; // 42.0
	std::cout << "d1: " << d1 << "\n";
	double d2 = 0xA.8p1; // 21.0
	std::cout << "d2: " << d2 << "\n";
	double d3 = 0xA.8p0; // 10.5
	std::cout << "d3: " << d3 << "\n";
	
	float f = 0xC.7Fp3;
	std::cout << "f: " << f << "\n";
}