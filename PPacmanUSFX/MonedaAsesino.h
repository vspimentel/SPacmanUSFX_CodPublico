#pragma once
#include "Moneda.h"
class MonedaAsesino : public Moneda
{
public:
    MonedaAsesino(Tile* _tile, Texture* _monedaTextura);
    MonedaAsesino(Tile* _tile, Texture* _monedaTextura, PODER_MONEDA _poder);
};
