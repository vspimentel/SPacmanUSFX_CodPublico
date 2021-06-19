#pragma once
#include "Moneda.h"
#include "Tile.h"
class MonedaClasico : public Moneda
{
public:
    MonedaClasico(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY);
    Moneda* clone();
};

