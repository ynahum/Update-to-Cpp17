#include <iostream>

/*
void func()
{
	// Could throw an exception in here
}
*/

void func() noexcept
{
	// Should not throw an exception in here
    throw 42; // this will call std::terminate
}


int main() 
{
    auto f = func;
    std::cout << std::boolalpha << noexcept(f()) << '\n';
    try
    {
        /* code */
        f();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}