#pragma once
#include "Fantasma.h"
class FantasmaClasico : public Fantasma
{
public:
    FantasmaClasico(Tile* _tile, Texture* _fantasmaClasicoTextura, int _posicionX, int _posicionY, int _velocidadPatron);
    Fantasma* clone();
};

