#include "ParedGalactico.h"

ParedGalactico::ParedGalactico(Tile* _tile, string _paredTextura)
:Pared(_tile, _paredTextura)
{
	tipoTexturaPared = 10;
	setTexture(tipoTexturaPared);
	tileActual = _tile;
	state = 0;
}
