#include "Printer.h"
//namespace

using namespace Engine;
void Printer::printDefault()
{
	std::cout << "Default Print Messange" << std::endl;
}

void Printer::showType(){
	for (const auto el : _v) {
		std::cout << "Vehicle Type: " << std::endl;
		el->printType();
	}
	std::cout << std::endl;
}
