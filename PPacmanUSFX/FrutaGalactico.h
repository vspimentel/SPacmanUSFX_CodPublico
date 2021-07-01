#pragma once
#include "Fruta.h"

class FrutaGalactico : public Fruta
{
public:
    FrutaGalactico(Tile* _tile, string _frutaTextura);
    Fruta* clone();
};

