#pragma once
#include "Pacman.h"

using namespace std;

class PacmanGalactico : public Pacman
{
public:
	PacmanGalactico(Tile* _tile, Texture* _texturaPacmanClasico, int _posicionX, int _posicionY, int _velocidad);
	~PacmanGalactico();
};


