//
// csv_parser.hpp
//
// created at 17/10/2021 16:49:01
// written by llamaking136
//


#if !defined(CSV_PARSER_HPP)
#define CSV_PARSER_HPP

#include <string>
#include <vector>
#include <map>
#include "cfg_parser.hpp"

struct CSVFile {
	std::vector<std::string> header;
	std::vector<std::vector<std::string> > data;
	std::string filename;
};

CSVFile parse_csv_file(std::string);

typedef std::map<double, double> ThrustCurve;

#endif // CSV_PARSER_HPP
