#include <iostream>
#include <string>
#include <cctype>
#include "lecturadatos.h"

using std::cout;
using std::cerr;
using std::string;

bool tipo_i_valido(string &s)
{
	if (s.length() == 1)
	{
		if (!isdigit(s[0]))
			return 0;		
	}
	else
	{
		if (s[0] == '+' || s[0] == '-' || isdigit(s[0]) != 0)
		{
			for (unsigned int i = 1; i < s.length(); i++)
			{
				if (!isdigit(s[i]))	
					return 0;							
			}
		}
		else
			return 0;					
	}
	return 1;
}

int capturar_i(const string &s)
{
	int numero;
	string cadena;
	bool es_valido;

	do {
		cout << s;		
		cadena = leer_dato_s();
		cout << '\n';

		es_valido = tipo_i_valido(cadena);

		if (!es_valido)
			cerr << "ERROR. Solo se puede ingresar n\243meros enteros.\n\n";
	} while (!es_valido);

	numero = stoi(cadena);

	return numero;
}

bool tipo_c_valido(string &s)
{
	if(s.length() == 1)
	{
		if(!isalpha(s[0]))		
			return 0;	
	}
	else
		return 0;
			
	return 1;
}

char capturar_c(string &s)
{
	char caracter;
	string cadena;
	bool es_valido;

	do {
		cout << s;	
		cadena = leer_dato_s();
		cout << '\n';

		es_valido = tipo_c_valido(cadena);

		if (!es_valido)
			cerr << "ERROR. Solo se puede ingresar letras.\n\n";
	} while (!es_valido);

	caracter = cadena[0];

	return caracter;	
}

bool tipo_d_valido(string &s)
{
	int cont_p = 0;

	if (s.length() == 1)
	{
		if (!isdigit(s[0]))
			return 0;
	}
	else
	{
		if (s[0] == '+' || s[0] == '-' || isdigit(s[0]) != 0)
		{
			for (unsigned int i = 1; i < s.length(); i++)
			{
				if (!isdigit(s[i]) && (s[i] != '.'))
					return 0;					
				else
				{
					if (s[i] == '.')
						cont_p++;
				}
			}
		}
		else
			return 0;
	}
	if (cont_p > 1)
		return 0;
	
	return 1;
}

double capturar_d(string &s)
{
	double numero;
	string cadena;
	bool es_valido;

	do {
		cout << s;
		cadena = leer_dato_s();
		cout << '\n';
		
		es_valido = tipo_d_valido(cadena);

		if (!es_valido)
			cerr << "ERROR. Solo se puede ingresar n\243meros decimales.\n\n";
	} while (!es_valido);

	numero = stod(cadena);

	return numero;
}
