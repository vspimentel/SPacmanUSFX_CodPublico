#pragma once
#include "Fruta.h"
class FrutaAsesino : public Fruta
{
public:
    FrutaAsesino(Tile* tile, Texture* _frutaTextura);
    Fruta* clone();
};

