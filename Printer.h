#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "main.cpp"
//namespace

namespace Engine {

	class Printer
	{
	public:
		void printDefault();
		void showType();
	private:		
		std::vector<std::shared_ptr<IVehicle>> _v; //= std::make_shared<IVehicle>();
	};
}


