#pragma once
#include "Moneda.h"
class MonedaAsesino : public Moneda
{
public:
    MonedaAsesino(Tile* _tile, string _monedaTextura);
    MonedaAsesino(Tile* _tile, string _monedaTextura, PODER_MONEDA _poder);
};
