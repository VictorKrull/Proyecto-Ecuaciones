#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cmath>
#include <iomanip>
#include "rlutil.h"

void mostrar_barra_progreso(int tiempo_ms, const std::string &mensaje, char simbolo)
{
	std::string barra_progreso;
	double nivel_progreso = 100.0 / (rlutil::tcols() - 8);

	std::cout << std::setw(rlutil::tcols() / 2 + 10) << mensaje << "\n\n";

	for (double porcentaje = 0.0; porcentaje <= 100.0; porcentaje += nivel_progreso)
	{
		barra_progreso += simbolo;
		std::cout << "\r[" << std::setprecision(0) << ceil(porcentaje) << '%' << "] " << barra_progreso << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(tiempo_ms));		
	}
	std::cout << "\n\n";
}