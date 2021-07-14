#include "MovePacmanNormal.h"

void MovePacmanNormal::move(GamePawn* pacman, MoveDirection direccion)
{
	switch (direccion)
	{
	case MOVE_UP:
		pacman->setPosicionY(std::max(pacman->getPosicionY() - pacman->getVelocidad(), pacman->getTileSiguiente()->getPosicionY() * Tile::altoTile));
		break;
	case MOVE_DOWN:
		pacman->setPosicionY(std::min(pacman->getPosicionY() + pacman->getVelocidad(), pacman->getTileSiguiente()->getPosicionY() * Tile::altoTile));
		break;
	case MOVE_LEFT:
		pacman->setPosicionX(std::max(pacman->getPosicionX() - pacman->getVelocidad(), pacman->getTileSiguiente()->getPosicionX() * Tile::anchoTile));
		break;
	case MOVE_RIGHT:
		pacman->setPosicionX(std::min(pacman->getPosicionX() + pacman->getVelocidad(), pacman->getTileSiguiente()->getPosicionX() * Tile::anchoTile));
		break;
	}
}
