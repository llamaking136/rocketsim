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
#include "csv_parser.hpp"
#include "rocket.hpp"
#include <cfloat>

class Simulator {
private:
	Planet planet;
	Rocket rocket;
	std::string output_file;
	double* velocity;
	double* height;
	double* accel;
	double* mass;
	double* thrust;
	unsigned long steps;
	unsigned long current_step;
	unsigned long actual_steps;
	double duration;
	double dt;
public:
	 Simulator(Rocket, long, double);
	~Simulator();
	void run();
	void outputFile(const char*);
};

double get_rocket_mass_during_burn(double burn_time, double time, double wet_mass, double dry_mass);

double get_rocket_thrust_curve(double burn_time, double time, ThrustCurve curve);

float round_to_two(float var);

bool engine_running(double duration, double dt);

void data_to_csv(std::string filename, std::string header, unsigned long size, double one, double* two, double* three, double* four, double* five, double* six);

double get_acceleration(double thrust, double mass);

double get_velocity(double prev_velocity, double accel, double gravity, double dt);

double get_height(double prev_height, double velocity, double dt);

#endif // SIMULATION_HPP
