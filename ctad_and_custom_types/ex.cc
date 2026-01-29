#include <iostream>
#include <string>
#include <vector>

template <typename T1, typename T2>
class Test {
public:	
	Test() {
		std::cout << "Default constructor called\n";
	}

	Test(const T1& a, const T2& b) : a(a), b(b) {
		std::cout << "templated constructor called\n";
	}

	Test(const Test&) {
		std::cout << "Copy constructor called\n";
	}

	Test(Test&&) noexcept {
		std::cout << "Move constructor called\n";
	}
private:
	T1 a;
	T2 b;
};

template <typename T>
class MyVector {
public:	
	MyVector() {
		std::cout << "Default constructor called\n";
	}
	template<typename Iter>
	MyVector(Iter begin, Iter end) : data(begin, end) {
		std::cout << "Iterator constructor called\n";
	}

	void print() const {
		for (const auto& item : data) {
			std::cout << item << " ";
		}
		std::cout << '\n';
	}

private:
	std::vector<T> data;
};

template <typename Iter>
MyVector(Iter, Iter) -> MyVector<typename std::iterator_traits<Iter>::value_type>;

int main()
{

	constexpr uint32_t TEST_NUMBER{1}; // Change this value to test different scenarios
	if constexpr (TEST_NUMBER == 0) {
		Test<int, double> test1(42, 3.14);
		Test<std::string, std::string> test2("Hello", "World");
		Test test3(100, 200.5); // Class template argument deduction
		//Test test4; // Default constructor error
		static_assert(std::is_same_v<decltype(test3), Test<int, double>>);
		//static_assert(std::is_same_v<decltype(test3), Test<std::string, double>>);

	} else if constexpr (TEST_NUMBER == 1){
		std::vector vec{1, 2, 3, 4, 5};
		// Equivalent to MyVector<int> MyVector2{begin(vec), end(vec)}	
		MyVector myVector2{begin(vec), end(vec)};
		myVector2.print();
	}

}