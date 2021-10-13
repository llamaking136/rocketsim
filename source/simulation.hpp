//
// simulation.hpp
//
// created at 12/10/2021 21:59:46
// written by llamaking136
//


#if !defined(SIMULATION_HPP)
#define SIMULATION_HPP

#include <string>
#include <iostream>
#include "cfg_parser.hpp"
#include "rocket.hpp"

class Simulation {
private:
	Planet planet;
	Rocket rocket;
	std::string output_file;
	double* velocity;
	double* height;
	unsigned long steps;
public:
	 Simulation(Rocket);
	~Simulation();
	run();
	outputFile(const char*);
};

#endif // SIMULATION_HPP
