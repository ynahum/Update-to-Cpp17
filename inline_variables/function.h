#ifndef FUNCTION_H
#define FUNCTION_H

// Free function defined in header
inline
void func_inline() {}

// Member function defined in header
class Test {
public:
	void func_test() {}
};

void util_function();

// constexpr function defined in header
// like inline, this avoids multiple definition errors and is defined as weak symbol (external linkage)
// the linker will merge multiple definitions into one
constexpr int meaning_of_life() { return 42; }

#endif // FUNCTION_H
