#include "ParedClasico.h"

ParedClasico::ParedClasico(Tile* _tile, Texture* _paredTextura)
	:Pared(_tile, _paredTextura)
{
	tipoTexturaPared = 17 + rand() % (22 - 17);
	setTexture(tipoTexturaPared);
	cont = 0;
}

void ParedClasico::update() {
	if (cont >= timeColor) {
		int color = 17 + rand() % (22 - 17);
		setTexture(color);
		cont = 0;
	}
	else
		cont++;
}