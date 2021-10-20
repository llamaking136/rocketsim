//
// csv_parser.cpp
//
// created at 17/10/2021 16:49:01
// written by llamaking136
//


#include "csv_parser.hpp"

CSVFile parse_csv_file(std::string file) {
	std::string data = fileread(file);
	CSVFile result;
	std::vector<std::string> file_split = stringtok(data, '\n');
	if (file_split.size() <= 1) {
		std::cout << "error: csv file " << file << " doesn't have two or more lines!\n";
		exit(1);
	}
	result.header = stringtok(file_split[0], ',');
	std::vector<std::string> temp_data;
	for (unsigned long i = 1; i < file_split.size(); i++) { // i is 1 because we already read the header.
		temp_data = stringtok(file_split[i], ',');

		if (temp_data.size() < result.header.size()) {
			std::cout << "error: csv file " << file << ", line " << i + 1 << ": too many colons!\n";
			exit(1);
		}

		result.data.push_back(temp_data);
	}

	std::cout << "loaded csv file " << file << "\n";

	return result;
}
