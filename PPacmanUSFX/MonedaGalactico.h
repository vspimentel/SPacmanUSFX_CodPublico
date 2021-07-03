#pragma once
#include "Moneda.h"
class MonedaGalactico :
    public Moneda
{
public:
    MonedaGalactico(Tile* _tile, string _monedaTextura);
    MonedaGalactico(Tile* _tile, string _monedaTextura, PODER_MONEDA _poder);
};

