#pragma once
#include "Fruta.h"
class FrutaGalactico : public Fruta
{
public:
    FrutaGalactico(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY);
    Fruta* clone();
};

