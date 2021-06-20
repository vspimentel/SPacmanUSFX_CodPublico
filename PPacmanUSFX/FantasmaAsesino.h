#pragma once
#include "Fantasma.h"
#include "TileGraph.h"

class FantasmaAsesino : public Fantasma
{
public:
    FantasmaAsesino(Tile* _tile, Texture* _fantasmaAsesinoTextura, int _posicionX, int _posicionY, int _velocidadPatron);
};

