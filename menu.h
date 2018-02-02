#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "rlutil.h"

void crear_menu(const std::string &titulo, std::vector<std::string> &opciones, int num_op)
{
	std::cout << std::setfill('*') << std::setw(rlutil::tcols()) << '*';
	std::cout << std::setfill(' ') << std::setw(rlutil::tcols() / 2) << titulo << '\n';
	std::cout << std::setfill('*') << std::setw(rlutil::tcols()) << '*' << '\n';

	for (int i = 0; i < num_op; i++)
		std::cout << std::setfill(' ') << i + 1 << ". " << opciones[i] << "\n\n";	
}
