#include "ParedAsesino.h"

ParedAsesino::ParedAsesino(Tile* _tile, Texture* _paredTextura)
	:Pared(_tile, _paredTextura)
{
	//isElectrica = true;
	tipoTexturaPared = 10;
	setTexture(tipoTexturaPared);
	state = 0;
}
