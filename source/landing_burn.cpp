//
// landing_burn.cpp
//
// created at 12/10/2021 19:57:52
// written by llamaking136
//


#include <iostream>
#include <cmath>

#define euler exp(1.0f)

struct Planet {
	double gravity;
	bool atmosphere;
	double drag_coefficient;
};

struct Rocket {
	Planet planet;
	double wet_mass;
	double dry_mass;
	double thrust;
	double isp;
	double alt;
	double vel;
	double duration_time;
	bool landed;
};

void calculate_landing_burn(double gravity, double alt, double vel, double isp, double mass, double thrust, double* orig_time, double* orig_height) {
	double time = (mass - (mass / pow(euler, (((vel + sqrt(2 * gravity * alt)) / (gravity * isp)))))) / (thrust / (gravity * isp));
	double height = ((vel + sqrt(2 * gravity * alt)) / 2) * time;

	*orig_time = time;
	*orig_height = height;
}

int not_main() {
	double time;
	double height;
	calculate_landing_burn(9.8, 100, 10, 49.61, 1, 14.38, &time, &height);
	std::cout << "Time: " << time << ", Height: " << height << "\n";
	return 0;
}

