#pragma once
#include "Pacman.h"
#include "MovePacmanSlow.h"
#include "MovePacmanFast.h"
#include "MovePacmanNormal.h"

class PacmanClasico : public Pacman
{
public:
	PacmanClasico(Tile* _tile, string _texturaPacmanClasico, int _velocidad);
};
