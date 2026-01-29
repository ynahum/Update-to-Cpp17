#include "function.h"
#include <cstdint>
#include <iostream>

void util_function() {
    // This function is intentionally left empty.
    func_inline();
    Test t;
    t.func_test();
    int answer = meaning_of_life();
    std::cout << "The meaning of life is: " << answer << '\n';

}