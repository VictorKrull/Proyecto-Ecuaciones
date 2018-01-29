#include <iostream>
#include <string>
#include <vector>

void crear_menu(std::string &titulo, std::vector<std::string> &opciones, int num_op)
{
	std::cout << '\n' << titulo << "\n\n";

	for (int i = 0; i < num_op; i++)
		std::cout << i + 1 << ". " << opciones[i] << "\n\n";
}
