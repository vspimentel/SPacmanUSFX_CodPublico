#pragma once
#include "Moneda.h"
class MonedaGalactico :
    public Moneda
{
public:
    MonedaGalactico(Tile* _tile, Texture* _monedaTextura);
    MonedaGalactico(Tile* _tile, Texture* _monedaTextura, PODER_MONEDA _poder);
};

