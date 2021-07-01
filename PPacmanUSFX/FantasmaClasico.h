#pragma once
#include "Fantasma.h"

class FantasmaClasico : public Fantasma
{
public:
    FantasmaClasico(Tile* _tile, string _fantasmaClasicoTextura, int _velocidadPatron);
    Fantasma* clone();
};

