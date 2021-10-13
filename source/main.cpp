//
// main.cpp
//
// created at 29/05/2021 16:22:23
// written by llamaking136
//


#include "main.hpp"

int main(int argc, const char* argv[]) {
	if (!argv[1] || !argv[2]) {
		std::cout << "usage: " << argv[0] << " <input file> [output file]\n";
		return 1;
	}

	Planet earth = {9.807, true, 0.47};
	Rocket rocket = rocket_from_file(argv[1], earth);

	/*
	Simulator simulation = {rocket};
	simulation.run();
	simulation.outputFile(argv[2]);
	*/

	return 0;
}
