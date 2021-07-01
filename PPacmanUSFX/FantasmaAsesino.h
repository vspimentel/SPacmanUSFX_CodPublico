#pragma once

#include "Fantasma.h"

class FantasmaAsesino : public Fantasma
{
public:
    FantasmaAsesino(Tile* _tile, string _fantasmaAsesinoTextura, int _velocidadPatron);
    Fantasma* clone();
};

