#pragma once
#include "Fruta.h"
class FrutaAsesino : public Fruta
{
public:
    FrutaAsesino(Tile* tile, Texture* _frutaTextura, int _posicionX, int _posicionY);
    Fruta* clone();
};

