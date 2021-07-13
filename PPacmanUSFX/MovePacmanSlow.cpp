#include "MovePacmanSlow.h"

#include <SDL.h>
#include <algorithm>

#include "MoveDirection.h"

void MovePacmanSlow::move(GamePawn* pacman, MoveDirection direccion)
{
	switch (direccion)
	{
	case MOVE_UP:
		pacman->setPosicionY(std::max(pacman->getPosicionY() - 3, pacman->getTileSiguiente()->getPosicionY() * Tile::altoTile));
		break;
	case MOVE_DOWN:
		pacman->setPosicionY(std::min(pacman->getPosicionY() + 3, pacman->getTileSiguiente()->getPosicionY() * Tile::altoTile));
		break;
	case MOVE_LEFT:
		pacman->setPosicionX(std::max(pacman->getPosicionX() - 3, pacman->getTileSiguiente()->getPosicionX() * Tile::anchoTile));
		break;
	case MOVE_RIGHT:
		pacman->setPosicionX(std::min(pacman->getPosicionX() + 3, pacman->getTileSiguiente()->getPosicionX() * Tile::anchoTile));
		break;
	}
}
