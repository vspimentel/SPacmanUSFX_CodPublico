#pragma once
#include "Moneda.h" 
class MonedaClasico : public Moneda
{
public:
    MonedaClasico(Tile* _tile, string _monedaTextura);
    MonedaClasico(Tile* _tile, string _monedaTextura, PODER_MONEDA _poder);
};

