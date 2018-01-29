#include <iostream>
#include <string>
#include <cctype>
#include <cwctype>
#include <exception>

int capturar_i(const std::string &mensaje)
{
	std::string num;
	int numero;
	unsigned int cont_car_convert = 0;

	do {
		std::cout << mensaje;
		std::getline(std::cin, num);
		std::cout << '\n';

		try
		{
			numero = std::stoi(num, &cont_car_convert);

			if (num.length() == 0 || (cont_car_convert < num.length()))
				throw num;
		}
		catch (const std::string &s)
		{
			std::cerr << "ERROR. Solo se puede ingresar n\243meros enteros.\n\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << "ERROR. Solo se puede ingresar n\243meros enteros.\n\n";
		}
	} while (num.length() == 0 || (cont_car_convert < num.length()));

	return numero;
}

double capturar_d(const std::string &mensaje)
{
	std::string num;
	double numero;
	unsigned int cont_car_convert = 0;

	do {
		std::cout << mensaje;
		std::getline(std::cin, num);
		std::cout << '\n';

		try
		{
			numero = std::stod(num, &cont_car_convert);

			if (num.length() == 0 || (cont_car_convert < num.length()))
				throw num;
		}
		catch (const std::string &s)
		{
			std::cerr << "ERROR. Solo se puede ingresar n\243meros decimales.\n\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << "ERROR. Solo se puede ingresar n\243meros decimales.\n\n";
		}
	} while (num.length() == 0 || (cont_car_convert < num.length()));

	return numero;
}

char capturar_c(const std::string &mensaje)
{
	std::string cadena;
	char caracter;
	unsigned int cant_car_convert = 0;

	do {
		std::cout << mensaje;
		std::getline(std::cin, cadena);
		std::cout << '\n';

		try
		{
			caracter = cadena[0];

			if (cadena.length() != 1 || !iswalpha(caracter))
				throw cadena;
		}
		catch (const std::string &cadena)
		{
			std::cerr << "ERROR. Solo se puede ingresar una letra.\n\n";
		}
	} while (cadena.length() != 1 || !iswalpha(caracter));

	return caracter;
}