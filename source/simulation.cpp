//
// simulation.cpp
//
// created at 12/10/2021 21:59:46
// written by llamaking136
//


#include "simulation.hpp"

Simulator::Simulator(Rocket rocket, long duration, double dt) {
	this->planet = rocket.planet;
	this->rocket = rocket;
	this->dt = dt;
	this->steps = (unsigned long)(duration / dt);
	this->velocity = new double[(int)this->steps];
	this->height = new double[(int)this->steps];
	this->accel = new double[(int)this->steps];
	this->mass = new double[(int)this->steps];
	this->velocity[0] = 0;
	this->height[0] = 0;
	this->accel[0] = 0;
	this->mass[0] = this->rocket.wet_mass;
	std::cout << "simulation configured, ready to run\n";
}

Simulator::~Simulator() {
	std::cout << "stopping simulation\n";
	std::cout << "writing to output file " << this->output_file << "\n";

	data_to_csv(this->output_file, "Time,Acceleration,Velocity,Height,Mass", this->actual_steps,
			this->dt,
			this->accel,
			this->velocity,
			this->height,
			this->mass);

	delete this->velocity;
	delete this->height;
	delete this->accel;
	delete this->mass;
}

void Simulator::run() {
	std::cout << "running simulation\n";
	float done_percent = 0.0f;
	double current_thrust = 0.0;
	double current_mass = 0.0f;
	this->actual_steps = 0;
	for (this->current_step = 0; this->current_step <= this->steps; this->current_step++) {
		this->duration += this->dt;
		this->rocket.duration_time = this->duration;

		// ded
		if (this->actual_steps != 0) {
			if (this->height[this->current_step - 1] < 0) {
				break;
			}
		}

		// launch
		if (this->current_step == 0) {
			this->rocket.launched = true;
			current_thrust = this->rocket.thrust;
		}
		// burnout
		if (!engine_running(this->rocket.burn_time, this->duration) && this->rocket.launched) {
			this->rocket.launched = false;
			current_thrust = 0;
		}

		// powered flight
		if (engine_running(this->rocket.burn_time, this->duration) && this->rocket.launched) {
			current_mass = get_rocket_mass_during_burn(this->rocket.burn_time, this->duration, this->rocket.wet_mass, this->rocket.dry_mass);
		}


		this->accel[this->current_step + 1] = current_thrust / current_mass;
		this->velocity[this->current_step + 1] = this->velocity[this->current_step] + (this->accel[this->current_step + 1] + -this->rocket.planet.gravity) * this->dt;
		this->height[this->current_step + 1] = this->height[this->current_step] + this->velocity[this->current_step + 1];
		this->mass[this->current_step + 1] = current_mass;

		done_percent = round_to_two((this->current_step / this->steps) * 100);
		std::cout << "done percent: " << done_percent << "\r";
		this->actual_steps++;
	}
}

void Simulator::outputFile(const char* filename) {
	this->output_file = std::string(filename);
	std::cout << "set output simulation file to " << this->output_file << "\n";
}

double get_rocket_mass_during_burn(double burn_time, double time, double wet_mass, double dry_mass) {
	return wet_mass - ((wet_mass - dry_mass) * (time / burn_time));
}

bool engine_running(double duration, double dt) { // XXX: rename dt to something else, it isn't ∆t
	// engine ignition is usually 0 on dt, so i think it'll work
	if (dt > duration) {
		return false;
	} else {
		return true;
	}
}

float round_to_two(float var)
{
    // 37.66666 * 100 =3766.66
    // 3766.66 + .5 =3767.16    for rounding off value
    // then type cast to int so value is 3767
    // then divided by 100 so the value converted into 37.67
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}

void data_to_csv(std::string filename, std::string header, unsigned long size, double one, double* two, double* three, double* four, double* five) {
	filewrite(filename, header + "\n");
	double time = 0.0;
	for (unsigned long i = 0; i < size; i++) {
		time += one;
		fileappend(filename, std::to_string(time) + "," + std::to_string(two[i]) + "," + std::to_string(three[i]) + "," + std::to_string(four[i]) + "," + std::to_string(five[i]) + "\n");
	}
	std::cout << "finished writing output file " << filename << "\n";
}

double get_acceleration(double thrust, double mass) {
	return thrust / mass;
}

double get_velocity(double prev_velocity, double accel, double gravity, double dt) {
	return prev_velocity + ((accel + gravity) * dt);
}

double get_height(double prev_height, double velocity, double dt) {
	return prev_height + velocity * dt;
}
