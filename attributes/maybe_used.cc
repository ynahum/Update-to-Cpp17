#include <iostream>

int func([[maybe_unused]] int x) 
{
#ifdef USE_X
	return x;
#else
	return 99;
#endif
}

int main() 
{
	std::cout << func(42) << std::endl;
}