#pragma once
#include "Pacman.h"
#include "MovePacmanSlow.h"
#include "MovePacmanNormal.h"

using namespace std;

class PacmanGalactico : public Pacman
{
public:
	PacmanGalactico(Tile* _tile, string _texturaPacmanClasico, int _velocidad);
};


