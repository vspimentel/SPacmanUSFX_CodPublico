#include "Tile.h"

Tile::Tile(int _x, int _y) {
	posicionX = _x;
	posicionY = _y;

	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
}

