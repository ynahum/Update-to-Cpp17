#include <iostream>
#include <tuple>

template <auto... args>
struct HeterogenousValueList {
	template <size_t Index>
    static constexpr auto get() {
        return std::get<Index>(std::tuple(args...));
    }
};

using Numbers = HeterogenousValueList<1, '2', 3u>;

int main()
{
	Numbers numbers;
	std::cout << numbers.template get<0>() << '\n'; // 1
	std::cout << numbers.template get<1>() << '\n'; // '2'
	std::cout << numbers.template get<2>() << '\n'; // 3u

}