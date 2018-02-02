#include <string>
#include "rlutil.h"

void editar_consola(const std::string &mensaje, int color_fondo, int color_letra)
{
	rlutil::setConsoleTitle(mensaje);
	rlutil::setBackgroundColor(color_fondo);
	rlutil::cls();
	rlutil::setColor(color_letra);
}
