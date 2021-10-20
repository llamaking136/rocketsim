#include <iostream>
#include <map>

int main() {
	std::map<double, double> test;
	test[0.1] = 0.1;
	test[0.2] = 0.5;
	test[0.25] = 0.6;
	std::cout << test[0.15] << "\n";
	return 0;
}
