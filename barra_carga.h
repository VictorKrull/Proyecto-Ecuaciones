#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cmath>
#include <iomanip>

void mostrar_barra_progreso(int tiempo, const std::string &mensaje, char simbolo)
{
	std::string barra_progreso;
	const double nivel_progreso = 1.42;

	std::cout << mensaje;

	for (double porcentaje = 0; porcentaje <= 100; porcentaje += nivel_progreso)
	{
		barra_progreso.insert(0, 1, simbolo);
		std::cout << "\r [" << std::setprecision(0) << ceil(porcentaje) << '%' << "] " << barra_progreso;
		std::this_thread::sleep_for(std::chrono::milliseconds(tiempo));		
	}
	std::cout << "\n\n";
}