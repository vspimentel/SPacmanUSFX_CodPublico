#include "MovePacmanFast.h"

void MovePacmanFast::move(GamePawn* pacman, MoveDirection direccion)
{
	switch (direccion)
	{
	case MOVE_UP:
		pacman->setPosicionY(std::max(pacman->getPosicionY() - 10, pacman->getTileSiguiente()->getPosicionY() * Tile::altoTile));
		break;
	case MOVE_DOWN:
		pacman->setPosicionY(std::min(pacman->getPosicionY() + 10, pacman->getTileSiguiente()->getPosicionY() * Tile::altoTile));
		break;
	case MOVE_LEFT:
		pacman->setPosicionX(std::max(pacman->getPosicionX() - 10, pacman->getTileSiguiente()->getPosicionX() * Tile::anchoTile));
		break;
	case MOVE_RIGHT:
		pacman->setPosicionX(std::min(pacman->getPosicionX() + 10, pacman->getTileSiguiente()->getPosicionX() * Tile::anchoTile));
		break;
	}
}
