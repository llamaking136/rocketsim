//
// cfg_parser.hpp
//
// created at 12/10/2021 20:24:32
// written by llamaking136
//


#if !defined(CFG_PARSER_HPP)
#define CFG_PARSER_HPP

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <sys/stat.h>
#include <fstream>
#include <sstream>

typedef std::map<std::string, std::string> CFGFile;

void fatal_error(std::string text);

bool is_dir(const char* cc);

std::string fileread(std::string filename);

std::vector<std::string> stringtok(std::string data, char by);

CFGFile parse_cfg_file(std::string file);

#endif // CFG_PARSER_HPP
