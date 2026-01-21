#include <iostream>
#include "bank_account_cpp17.h"

int main()
{
	// Use the static data member
	bank_account::interest_rate = 0.75;
	std::cout << "Interest rate: " << bank_account::interest_rate << "\n";
}