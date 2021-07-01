#pragma once
#include "Fruta.h"
class FrutaAsesino : public Fruta
{
public:
    FrutaAsesino(Tile* tile, string _frutaTextura);
    Fruta* clone();
};

