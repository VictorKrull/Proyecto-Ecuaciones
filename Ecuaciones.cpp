/*
Copyright (c) 2017 - 2018, Max Díaz Romaní

Este programa es una pequeña aplicación de consola (CLI) que sirve para 
resolver ecuaciones de primer hasta tercer grado. Surgió como producto 
de mis práticas durante el curso de Programación I en el semestre 2017-II. 
Es por eso que está escrito completamente en C++ (Visual C++).

La actual (tercera) versión de este programa ha sido escrita durante el
mes de enero de 2018. 

Para ver el progreso de los cambios de este proyecto puede consultar el
enlace: https://github.com/VictorKrull/Proyecto-Ecuaciones
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include "validacion_datos.h"
#include "menu.h"
#include "barra_progreso.h"
#include "consola.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

char preguntar();
void resolver_ecuacion_lineal(double, double);
void resolver_ecuacion_cuadratica(double, double, double);
void resolver_ecuacion_cubica(double, double, double, double);

int main()
{
	int opcion;
	double coef_principal, ter_cuadratico, ter_lineal, ter_independiente;
	char respuesta;	
	vector<string> opciones_menu = {"Resolver ecuaci\242n lineal", "Resolver ecuaci\242n cuadr\240tica", "Resolver ecuaci\242n c\243bica"};
	
	editar_consola("CALCULADORA DE ECUACIONES", 1, 10);

	do
	{
		crear_menu("\tMENU PRINCIPAL", opciones_menu, 3);

		do {
			opcion = capturar_i("Seleccione una opci\242n:\t\t");

			if (opcion != 1 && opcion != 2 && opcion != 3)
				cerr << "ERROR. La opci\242n seleccionada no existe.\n\n";
		} while (opcion != 1 && opcion != 2 && opcion != 3);

		cls();

		switch (opcion)
		{
			case 1: {
				cout << "La ecuaci\242n tiene la forma:\n\n" << setw(47) << "AX + B = 0.\n\n";

				do {
					coef_principal = capturar_d("Ingrese el valor de A:\t");

					if (coef_principal == 0.0)
						cerr << "ERROR. El valor de A debe ser distinto de cero.\n\n";
				} while (coef_principal == 0.0);

				ter_independiente = capturar_d("Ingrese el valor de B:\t");
				
				cls();
				mostrar_barra_progreso(10, "\t    Resolviendo ecuaci\242n...", char(219));				
				resolver_ecuacion_lineal(coef_principal, ter_independiente);
				respuesta = preguntar();
			} break;

			case 2: {
				cout << "La ecuaci\242n tiene la forma:\n\n" << setw(50) << "AX^2 + BX + C = 0.\n\n";

				do {
					coef_principal = capturar_d("Ingrese el valor de A:\t");

					if (coef_principal == 0.0)
						cerr << "ERROR. El valor de A debe ser distinto de cero.\n\n";
				} while (coef_principal == 0.0);

				ter_lineal = capturar_d("Ingrese el valor de B:\t");
				ter_independiente = capturar_d("Ingrese el valor de C:\t");

				cls();
				mostrar_barra_progreso(25, "\t    Resolviendo ecuaci\242n...", char(219));				
				resolver_ecuacion_cuadratica(coef_principal, ter_lineal, ter_independiente);
				respuesta = preguntar();
			} break;

			case 3: {
				cout << "La ecuaci\242n tiene la forma:\n\n" << setw(55) << "AX^3 + BX^2 + CX + D = 0.\n\n";

				do {
					coef_principal = capturar_d("Ingrese el valor de A:\t");

					if (coef_principal == 0.0)
						cerr << "ERROR. El valor de A debe ser distinto de cero.\n\n";
				} while (coef_principal == 0.0);

				ter_cuadratico = capturar_d("Ingrese el valor de B:\t");
				ter_lineal = capturar_d("Ingrese el valor de C:\t");
				ter_independiente = capturar_d("Ingrese el valor de D:\t");

				cls();
				mostrar_barra_progreso(50, "\t    Resolviendo ecuaci\242n...", char(219));				
				resolver_ecuacion_cubica(coef_principal, ter_cuadratico, ter_lineal, ter_independiente);
				respuesta = preguntar();
			} break;
		}
	} while (respuesta == 'S');

	if (respuesta == 'N')
	{
		cout << "Gracias por utilizar la aplicaci\242n. Si encuentra alg\243n bug, por favor rep\242rtelo al correo maxdr.mat\100gmail.com.\n\n";		
		anykey("Presione cualquier tecla para cerrar el programa.\n");
	}

	return 0;
}

char preguntar()
{
	char rpta;

	do {
		rpta = capturar_c("\250Desea resolver otra ecuaci\242n? (S)---(N):\t");
		rpta = toupper(rpta);

		if (rpta != 'S' && rpta != 'N')
			cerr << "ERROR. La respuesta es incorrecta.\n\n";
	} while (rpta != 'S' && rpta != 'N');
	
	cls();

	return rpta;
}

void resolver_ecuacion_lineal(double coef_prin, double ter_indep)
{
	double raiz;	

	raiz = -ter_indep / coef_prin;	

	cout << "La ra\241z de la ecuaci\242n es:\t" << fixed << setprecision(2) << raiz << "\n\n";
}

void resolver_ecuacion_cuadratica(double coef_prin, double ter_lin, double ter_indep)
{
	double discr, raiz1, raiz2, parte_real, parte_imaginaria;	

	cout << fixed << setprecision(2);

	discr = pow(ter_lin, 2) - 4 * coef_prin * ter_indep;

	if (discr >= 0.0)
	{
		if (discr == 0.0)
		{
			raiz1 = -ter_lin / (2 * coef_prin);
			cout << "La ecuaci\242n tiene una ra\241z doble.\n\n";
			cout << "La ra\241z es:\t" << raiz1 << "\n\n";
		}
		else
		{
			raiz1 = (-ter_lin + sqrt(discr)) / (2 * coef_prin);
			raiz2 = (-ter_lin - sqrt(discr)) / (2 * coef_prin);
			cout << "La ecuaci\242n tiene dos ra\241ces reales distintas.\n\n";
			cout << "Las ra\241ces son:\t" << raiz1 << "  y  " << raiz2 << "\n\n";
		}
	}
	else
	{
		parte_real = -ter_lin / (2 * coef_prin);
		parte_imaginaria = sqrt(-discr) / (2 * coef_prin);

		if (parte_real == 0.0)
		{
			cout << "La ecuaci\242n tiene dos ra\241ces imaginarias.\n\n";
			cout << "Las ra\241ces son:\t" << parte_imaginaria << 'i' << "  y  " << -parte_imaginaria << 'i' << "\n\n";
		}
		else
		{
			cout << "La ecuaci\242n tiene dos ra\241ces complejas.\n\n";
			cout << "Las ra\242ces son:\t" << parte_real << " + " << parte_imaginaria << 'i' << "  y  " << parte_real << " - " << parte_imaginaria << 'i' << "\n\n";
		}
	}
}

void resolver_ecuacion_cubica(double coef_prin, double ter_cuad, double ter_lin, double ter_indep)
{
	double const PI = 3.141592;
	double discr, aux1, aux2, aux3, aux4, angulo, raiz1, raiz2, raiz3, parte_real, parte_imaginaria;	

	cout << fixed << setprecision(2);

	ter_cuad = ter_cuad / coef_prin;
	ter_lin = ter_lin / coef_prin;
	ter_indep = ter_indep / coef_prin;
	aux1 = (3 * ter_lin - pow(ter_cuad, 2)) / 3;
	aux2 = (2 * pow(ter_cuad, 3) - 9 * ter_cuad * ter_lin + 27 * ter_indep) / 27;
	discr = pow(aux2, 2) / 4 + pow(aux1, 3) / 27;

	if (discr >= 0.0)
	{
		if (discr == 0.0)
		{
			if (aux1 != 0.0 && aux2 != 0.0)
			{
				raiz1 = (-3 * aux2) / (2 * aux1) - ter_cuad / 3;
				raiz3 = (-4 * pow(aux1, 2)) / (9 * aux2) - ter_cuad / 3;

				cout << "La ecuaci\242n tiene una ra\241z doble y una ra\241z simple.\n\n";
				cout << "La ra\241z doble es:\t" << raiz1 << "\n\n";
				cout << "La ra\241z simple es:\t" << raiz3 << "\n\n";
			}
			else
			{
				raiz1 = -ter_cuad / 3;

				cout << "La ecuacion tiene una ra\241z triple.\n\n";
				cout << "La ra\241z triple es:\t" << raiz1 << "\n\n";
			}
		}
		else
		{
			aux3 = cbrt(-aux2 / 2 + sqrt(discr));
			aux4 = -aux1 / (3 * aux3);
			raiz1 = aux3 + aux4 - ter_cuad / 3;			
			parte_real = (-aux3 - aux4) / 2 - ter_cuad / 3;
			parte_imaginaria = sqrt(3) / 2 * (aux3 - aux4);

			cout << "La ecuaci\242n tiene una ra\241z real y dos ra\241ces complejas.\n\n";

			if (parte_real == 0.0)
			{
				cout << "La ra\241z real es:\t\t" << raiz1 << "\n\n";
				cout << "Las ra\241ces imaginarias son:\t" << parte_imaginaria << 'i' << "  y  " << " - " << parte_imaginaria << 'i' << "\n\n";
			}
			else
			{
				cout << "La ra\241z real es:\t\t" << raiz1 << "\n\n";
				cout << "Las ra\241ces complejas son:\t" << parte_real << " + " << parte_imaginaria << 'i' << "  y  " << parte_real << " - " << parte_imaginaria << 'i' << "\n\n";
			}
		}
	}
	else
	{
		angulo = acos((-aux2 / 2) / (sqrt(-pow(aux1 / 3, 3))));
		raiz1 = 2 * sqrt(-aux1 / 3) * cos(angulo / 3) - ter_cuad / 3;
		raiz2 = 2 * sqrt(-aux1 / 3) * cos((angulo + 2 * PI) / 3) - ter_cuad / 3;
		raiz3 = 2 * sqrt(-aux1 / 3) * cos((angulo + 4 * PI) / 3) - ter_cuad / 3;

		cout << "La ecuaci\242n tiene tres ra\241ces reales distintas.\n\n";
		cout << "La ra\241ces son:\t" << raiz1 << ", " << raiz2  << "  y  " << raiz3 << "\n\n";
	}
}