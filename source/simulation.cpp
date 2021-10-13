//
// simulation.cpp
//
// created at 12/10/2021 21:59:46
// written by llamaking136
//


#include "simulation.hpp"

Simulator::Simulator(Rocket rocket, long duration, double dt) {
	this->steps = (unsigned long)(duration / dt);
	this->velocity = new double[(int)this->steps];
	this->height = new double[(int)this->steps];
	std::cout << "starting simulation\n";
}

Simulator::~Simulator() {
	std::cout << "stopping simulation\n";
	delete this->velocity;
	delete this->height;
}

void Simulator::run() {
	
}
