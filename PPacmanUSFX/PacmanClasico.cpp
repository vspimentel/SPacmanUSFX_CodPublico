#include "PacmanClasico.h"

PacmanClasico::PacmanClasico(Tile* _tile, string _texturaPacmanClasico, int _velocidad) :
	Pacman(_tile, _texturaPacmanClasico, _velocidad) {
	estrategiaMov = new MovePacmanNormal;
}

