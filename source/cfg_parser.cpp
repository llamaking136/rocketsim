//
// cfg_parser.cpp
//
// created at 12/10/2021 20:24:32
// written by llamaking136
//


#include "cfg_parser.hpp"

void fatal_error(std::string text) {
	std::cerr << "fatal error: " << text << "\n";
}

bool is_dir(const char* cc) {
	struct stat buf;
	stat(cc, &buf);
	return S_ISDIR(buf.st_mode);
}

std::string fileread(std::string filename) {
	std::ifstream file(filename);
	std::string buffer;
	std::string data;
	if (file.fail()) {
		fatal_error("unable to open file: " + filename + " [errno " + std::to_string(errno) + "]");
		exit(1);
	} else if (is_dir(filename.c_str())) {
		fatal_error("is a directory: " + filename + " [errno 21]");
		exit(1);
	}

	// file >> data;
	while (std::getline(file, buffer)) {
		data += buffer + "\n";
	}
	file.close();
	return data;
}

void filewrite(std::string filename, std::string data) {
	std::ofstream file(filename);
	if (file.fail()) {
		fatal_error("unable to open file: " + filename + " [errno " + std::to_string(errno) + "]");
		exit(1);
	} else if (is_dir(filename.c_str())) {
		fatal_error("is a directory: " + filename + " [errno 21]");
		exit(1);
	}
	
	file << data;
	file.close();
}

void fileappend(std::string filename, std::string data) {
	std::ofstream file(filename, std::ios::out | std::ios::app);
	if (file.fail()) {
		fatal_error("unable to open file: " + filename + " [errno " + std::to_string(errno) + "]");
		exit(1);
	} else if (is_dir(filename.c_str())) {
		fatal_error("is a directory: " + filename + " [errno 21]");
		exit(1);
	}
	
	file << data;
	file.close();
}

std::vector<std::string> stringtok(std::string data, char by) {
	std::vector<std::string> result;	

	std::stringstream ss(data);
	std::string to;

	if (!(data == "")) {
		while (std::getline(ss, to, by)){
			result.push_back(to);
		}
	} 
	return result;
}

CFGFile parse_cfg_file(std::string file) {
	std::string filedata = fileread(file);
	std::vector<std::string> filesplit = stringtok(filedata, '\n');

	CFGFile result;

	for (unsigned int i = 0; i < filesplit.size(); i++) {
		std::vector<std::string> parsed_line = stringtok(filesplit[i], '#');
		if (parsed_line[0] == "") continue;
		std::string line = parsed_line[0];
		std::vector<std::string> split_line = stringtok(line, '=');
		if (split_line.size() != 2) {
			std::cerr << "error: line " << i + 1 << ", file " << file << ": parsing error!\n";
			continue;
		}
		std::string key = split_line[0];
		std::string value = split_line[1];
		result[key] = value;
	}

	return result;
}
