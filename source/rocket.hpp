//
// rocket.hpp
//
// created at 12/10/2021 19:58:50
// written by llamaking136
//


#if !defined(ROCKET_HPP)
#define ROCKET_HPP

#include "cfg_parser.hpp"

struct Planet {
	double gravity;
	bool atmosphere;
	double drag_coefficient;
};

struct Rocket {
	Planet planet;
	std::string name;
	const char* file_name;
	double wet_mass;
	double dry_mass;
	double mass;
	double thrust;
	double isp;
	double alt;
	double vel;
	double burn_time;
	double duration_time;
	bool launched;
	bool landed;
	bool crashed;
};

Rocket rocket_from_file(const char* file, Planet planet);

#endif // ROCKET_HPP
