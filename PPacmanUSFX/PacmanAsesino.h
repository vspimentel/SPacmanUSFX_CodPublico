#pragma once

#include "Pacman.h"
#include "MovePacmanSlow.h"
#include "MovePacmanNormal.h"

class PacmanAsesino : public Pacman
{
public:
	PacmanAsesino(Tile* _tile, string _texturaPacmanClasico, int _velocidad);
};


