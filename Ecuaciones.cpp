#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <Windows.h>
#include "declaracion_ecuaciones.h"
#include "validacion_conversion.h"
#include "menu.h"

//Creado por Max Díaz Romaní. Diciembre 2017.

using namespace std;

void mostrar_barra_carga(int segundos)
{
	char barra_progreso[73];
	int porcentaje, nivel_progreso = 0;

	memset(barra_progreso, '\315', 72);
	barra_progreso[72] = '\0';

	cout << "\t\t\t Resolviendo la ecuaci\242n...\n";

	for (porcentaje = 0; porcentaje <= 100; porcentaje++)
	{
		nivel_progreso = (porcentaje * 72) / 100;
		memset(barra_progreso, '\376', nivel_progreso);
		cout << " (" << porcentaje << '\45' << ')' << '\r' << barra_progreso;
		Sleep(segundos * 1000 / 120);
	}
	cout << "\n\n";
}

void preguntar()
{
	char respuesta;
	string pregunta = "\250Desea resolver otra ecuaci\242n? (S)---(N):\t";

	do {
		respuesta = capturar_c(pregunta);
		respuesta = toupper(respuesta);

		if (respuesta != 'S' && respuesta != 'N')
			cerr << "ERROR. La respuesta no existe.\n\n";
	} while (respuesta != 'S' && respuesta != 'N');

	system("cls");

	if (respuesta == 'S')
		menu_principal();
	else
	{
		cout << "Gracias por utilizar la aplicaci\242n. Si encuentra alg\243n bug, por favor rep\242rtelo al correo maxdr.mat\100gmail.com.\n\n";
		cout << "Presione ENTER para finalizar el programa.\n";
		cin.get();
	}
}

void calcular_raiz_lineal()
{
	double coef_principal, ter_indep, raiz;
	string mensaje_1 = "Ingrese el valor de A:\t\t";
	string mensaje_2 = "Ingrese el valor de B:\t\t";

	cout << "La ecuaci\242n tiene la forma: AX + B = 0.\n\n";

	do {
		coef_principal = capturar_d(mensaje_1);

		if (coef_principal == 0)
			cerr << "ERROR. El valor de A debe ser distinto de cero.\n\n";
	} while (coef_principal == 0);

	ter_indep = capturar_d(mensaje_2);

	system("cls");

	mostrar_barra_carga(1);

	raiz = -ter_indep / coef_principal;

	cout << "La ra\241z de la ecuaci\242n es:\t\t" << raiz << "\n\n";

	preguntar();
}

void calcular_raices_cuadratica()
{
	double coef_principal, ter_lin, ter_indep, discr, raiz1, raiz2, parte_real, parte_imaginaria;
	string mensaje_1 = "Ingrese el valor de A:\t\t";
	string mensaje_2 = "Ingrese el valor de B:\t\t";
	string mensaje_3 = "Ingrese el valor de C:\t\t";

	cout << "La ecuaci\242n tiene la forma: AX^2 + BX + C = 0.\n\n";

	do {
		coef_principal = capturar_d(mensaje_1);

		if (coef_principal == 0)
			cerr << "ERROR. El valor de A debe ser distinto de cero.\n\n";
	} while (coef_principal == 0);

	ter_lin = capturar_d(mensaje_2);
	ter_indep = capturar_d(mensaje_3);

	system("cls");

	mostrar_barra_carga(2);

	discr = pow(ter_lin, 2) - 4 * coef_principal * ter_indep;

	if (discr >= 0)
	{
		if (discr == 0)
		{
			raiz1 = -ter_lin / (2 * coef_principal);
			cout << "La ecuaci\242n tiene una ra\241z doble.\n\n";
			cout << "La ra\241z es:\t\t" << raiz1 << "\n\n";
		}
		else
		{
			raiz1 = (-ter_lin + sqrt(discr)) / (2 * coef_principal);
			raiz2 = (-ter_lin - sqrt(discr)) / (2 * coef_principal);
			cout << "La ecuaci\242n tiene dos ra\241ces reales distintas.\n\n";
			cout << "Las ra\241ces son:\t\t" << raiz1 << "  y  " << raiz2 << "\n\n";
		}
	}
	else
	{
		parte_real = -ter_lin / (2 * coef_principal);
		parte_imaginaria = sqrt(-discr) / (2 * coef_principal);

		if (parte_real == 0)
		{
			cout << "La ecuaci\242n tiene dos ra\241ces imaginarias puras.\n\n";
			cout << "Las ra\241ces son:\t\t\t" << parte_imaginaria << 'i' << " y " << -parte_imaginaria << 'i' << "\n\n";
		}
		else
		{
			cout << "La ecuaci\242n tiene dos ra\241ces complejas.\n\n";
			cout << "Las ra\242ces son:\t\t\t" << parte_real << " + " << parte_imaginaria << 'i' << " y " << parte_real << " - " << parte_imaginaria << 'i' << "\n\n";
		}
	}
	preguntar();
}

void calcular_raices_cubica()
{
	double const PI = 3.141592;
	double coef_principal, ter_cuad, ter_lin, ter_indep, discr, aux1, aux2, angulo, raiz1, raiz2, raiz3, parte_real, parte_imaginaria;
	string mensaje_1 = "Ingrese el valor de A:\t";
	string mensaje_2 = "Ingrese el valor de B:\t";
	string mensaje_3 = "Ingrese el valor de C:\t";
	string mensaje_4 = "Ingrese el valor de D:\t";

	cout << "La ecuaci\242n tiene la forma: AX^3 + BX^2 + CX + D = 0.\n\n";

	do {
		coef_principal = capturar_d(mensaje_1);

		if (coef_principal == 0)
			cerr << "ERROR. El valor de A debe ser distinto de cero.\n\n";
	} while (coef_principal == 0);

	ter_cuad = capturar_d(mensaje_2);
	ter_lin = capturar_d(mensaje_3);
	ter_indep = capturar_d(mensaje_4);

	system("cls");

	mostrar_barra_carga(4);

	ter_cuad = ter_cuad / coef_principal;
	ter_lin = ter_lin / coef_principal;
	ter_indep = ter_indep / coef_principal;
	aux1 = (3 * ter_lin - pow(ter_cuad, 2)) / 3;
	aux2 = (2 * pow(ter_cuad, 3) - 9 * ter_cuad * ter_lin + 27 * ter_indep) / 27;
	discr = pow(aux2, 2) / 4 + pow(aux1, 3) / 27;

	if (discr >= 0)
	{
		if (discr == 0)
		{
			if (aux1 != 0 && aux2 != 0)
			{
				raiz1 = (-3 * aux2) / (2 * aux1) - ter_cuad / 3;
				raiz3 = (-4 * pow(aux1, 2)) / (9 * aux2) - ter_cuad / 3;

				cout << "La ecuaci\242n tiene una ra\241z doble y una ra\241z simple.\n\n";
				cout << "La ra\241z doble es:\t\t" << raiz1 << "\n\n";
				cout << "La ra\241z simple es:\t\t" << raiz3 << "\n\n";
			}
			else
			{
				raiz1 = -ter_cuad / 3;

				cout << "La ecuacion tiene una ra\241z triple.\n\n";
				cout << "La ra\241z triple es:\t\t" << raiz1 << "\n\n";
			}
		}
		else
		{
			raiz1 = cbrt(-aux2 / 2 + sqrt(discr)) + cbrt(-aux2 / 2 - sqrt(discr)) - ter_cuad / 3;
			parte_real = -(cbrt(-aux2 / 2 + sqrt(discr)) + cbrt(-aux2 / 2 - sqrt(discr))) / 2 - ter_cuad / 3;
			parte_imaginaria = sqrt(3) / 2 * (cbrt(-aux2 / 2 + sqrt(discr)) - cbrt(-aux2 / 2 - sqrt(discr)));

			cout << "La ecuaci\242n tiene una ra\241z real y dos ra\241ces imaginarias.\n\n";

			if (parte_real == 0)
			{
				cout << "La ra\241z real es:\t\t\t" << raiz1 << "\n\n";
				cout << "Las ra\241ces imaginarias puras son:\t\t" << parte_imaginaria << 'i' << " y " << " - " << parte_imaginaria << 'i' << "\n\n";
			}
			else
			{
				cout << "La ra\241z real es:\t\t\t" << raiz1 << "\n\n";
				cout << "Las ra\241ces complejas son:\t\t" << parte_real << " + " << parte_imaginaria << 'i' << " y " << parte_real << " - " << parte_imaginaria << 'i' << "\n\n";
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
		cout << "La ra\ces son:\t\t" << raiz1 << ", " << raiz2  << " y " << raiz3 << "\n\n";
	}
	preguntar();
}

void menu_principal()
{
	int op;
	string mensaje_op = "Seleccione una opci\242n:\t\t\t";
	string titulo = "==========MENU DE OPCIONES==========\n";
	vector<string> opciones = { "Resolver ecuaci\242n lineal\n", "Resolver ecuaci\242n cuadr\240tica\n", "Resolver ecuaci\242n c\243bica\n" };

	menu(titulo, opciones, 3);

	do {
		op = capturar_i(mensaje_op);

		if (op != 1 && op != 2 && op != 3)
			cerr << "ERROR. La opci\242n seleccionada no existe.\n\n";
	} while (op != 1 && op != 2 && op != 3);

	system("cls");

	switch (op)
	{
		case 1: {calcular_raiz_lineal(); } break;

		case 2: {calcular_raices_cuadratica(); } break;

		case 3: {calcular_raices_cubica(); } break;
	}
}

int main()
{
	system("title SOLUCIONADOR DE ECUACIONES");
	system("color 1A");

	menu_principal();

	return 0;
}