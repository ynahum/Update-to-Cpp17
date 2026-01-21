#include <iostream>
#include <array>
#include "inline.h"

int main()
{
	std::array<int, nplanets> planet_distances = {57, 108, 150, 228, 778, 1427, 2871, 4497};

	std::cout << "nplanets = " << nplanets << "\n";
	std::cout << "planet_distances.size() = " << planet_distances.size() << "\n";
}