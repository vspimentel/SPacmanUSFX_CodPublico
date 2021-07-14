#include "PacmanAsesino.h"

PacmanAsesino::PacmanAsesino(Tile* _tile, string _texturaPacmanAsesino, int _velocidad):
	Pacman(_tile, _texturaPacmanAsesino, _velocidad) {
	estrategiaMov = new MovePacmanNormal;
}
