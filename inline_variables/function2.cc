#include "function.h"
#include <cstdint>
#include <iostream>

// g++ -std="c++17" -Wall -Wextra -pthread -o ./function ./function.cc ./function2.cc -ltbb -Wl,-Map="./function.map"      
int main()
{
    constexpr uint32_t TEST_NUMBER{0}; // Change this value to test different scenarios
    if constexpr (TEST_NUMBER == 0) {
        func_inline();
        Test t;
        t.func_test();
        auto answer = meaning_of_life();
        std::cout << "The meaning of life is: " << answer << '\n';
        util_function();

    } else if constexpr (TEST_NUMBER == 1){
    } else if constexpr (TEST_NUMBER == 2){

    }
}