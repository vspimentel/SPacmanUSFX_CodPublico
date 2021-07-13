#pragma once

#include "Pacman.h"
#include "MovePacmanSlow.h"

class PacmanAsesino : public Pacman
{
public:
	PacmanAsesino(Tile* _tile, string _texturaPacmanClasico, int _velocidad);
};


