#include <iostream>
#include <string>

#if __cplusplus >= 201402L
#pragma message ("C++14 or later")
// C++14 version
// Not instantiated if T is std::string
template<typename T, std::enable_if_t<!std::is_same<std::string, T>::value, int> = 99>
std::string get_string(const T& arg)
{
    return std::to_string(arg);
}

// Instantiated only if T is std::string
template<typename T, std::enable_if_t<std::is_same<std::string, T>::value, int> = 99>
std::string get_string(const T& arg)
{
    return arg;
}

#else
#pragma message ("C++11 version")
// C++11 version
// Not instantiated if T is std::string
template<typename T, typename std::enable_if<!std::is_same<std::string, T>::value, int>::type = 99>
std::string get_string(const T& arg)
{
    return std::to_string(arg);
}

// Instantiated only if T is std::string
template<typename T, typename std::enable_if<std::is_same<std::string, T>::value, int>::type = 99>
std::string get_string(const T& arg)
{
    return arg;
}

#endif

int main()
{
	int x{42};
	std::cout << "x: " << x << '\n';
	std::cout << "get_string(x): " << get_string(x) << '\n';
	std::string str{"hello"};
	std::cout << "str: " << str << '\n';
	std::cout << "get_string(str): " << get_string(str) << '\n';
}