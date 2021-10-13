//
// rocket.cpp
//
// created at 12/10/2021 20:02:57
// written by llamaking136
//


#include "rocket.hpp"

Rocket rocket_from_file(const char* filename, Planet planet) {
	Rocket result;

	CFGFile file = parse_cfg_file(std::string(filename));
	result.name = file["name"];
	result.file_name = filename;
	result.planet = planet;
	result.wet_mass = stod(file["wet mass"]);
	result.dry_mass = stod(file["dry mass"]);
	result.thrust = stod(file["thrust"]);
	result.isp = stod(file["isp"]);
	result.burn_time = stod(file["burn time"]);
	
	std::cout << "loaded rocket " << result.name << " from file " << filename << "\n";
		
	return result;
}
