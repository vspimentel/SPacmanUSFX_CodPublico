#include "FantasmaAsesino.h"

FantasmaAsesino::FantasmaAsesino(Tile* _tile, string _fantasmaAsesinoTextura, int _velocidad) :
	Fantasma(_tile, _fantasmaAsesinoTextura, _velocidad)
{
	tipoFantasma = FANTASMA_ASESINO;
};

Fantasma* FantasmaAsesino::clone() {
	return new FantasmaAsesino(*this);
}