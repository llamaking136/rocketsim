//
// rocket.cpp
//
// created at 12/10/2021 20:02:57
// written by llamaking136
//


#include "rocket.hpp"

Rocket rocket_from_file(const char* filename, Planet planet) {
	Rocket result;

	CFGFile cfg_file = parse_cfg_file(std::string(filename));
	CFGFile engine_file = parse_cfg_file("engines/" + std::string(cfg_file["engine"]) + "/info.cfg");
	result.name = cfg_file["name"];
	result.file_name = filename;
	result.planet = planet;
	result.wet_mass = stod(cfg_file["wet mass"]);
	result.dry_mass = stod(cfg_file["dry mass"]);
	result.burn_time = stod(engine_file["burn time"]);
	result.isp = stod(engine_file["isp"]);

	ThrustCurve thrust = load_thrust_curve_from_csv("engines/" + std::string(cfg_file["engine"]) + "/" + engine_file["file"]);
	result.thrust = thrust;

	std::cout << "loaded rocket " << result.name << " from file " << filename << "\n";
		
	return result;
}

ThrustCurve load_thrust_curve_from_csv(std::string filename) {
	CSVFile file = parse_csv_file(filename);
	ThrustCurve result;
	
	for (unsigned long i = 0; i < file.data.size(); i++) {
		result[stod(file.data[i][0])] = stod(file.data[i][1]);
	}

	return result;
}
