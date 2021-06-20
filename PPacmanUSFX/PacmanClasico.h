#pragma once
#include "Pacman.h"

using namespace std;

class PacmanClasico : public Pacman
{
public:
	//Constructores y destructores
	PacmanClasico(Tile* _tile, Texture* _texturaPacmanClasico, int _posicionX, int _posicionY, int _velocidad);
	~PacmanClasico();
};
