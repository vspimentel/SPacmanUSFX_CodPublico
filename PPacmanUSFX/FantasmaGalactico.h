#pragma once
#include "Fantasma.h"

class FantasmaGalactico : public Fantasma
{
public:
    FantasmaGalactico(Tile* _tile, string _fantasmaGalacticoTextura, int _velocidadPatron);
    Fantasma* clone();
};
