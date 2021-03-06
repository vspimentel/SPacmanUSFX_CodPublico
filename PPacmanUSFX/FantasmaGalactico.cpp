#include "FantasmaGalactico.h"


FantasmaGalactico::FantasmaGalactico(Tile* _tile, string _fantasmaGalacticoTextura, int _velocidad) :
	Fantasma(_tile, _fantasmaGalacticoTextura, _velocidad){
	tipoFantasma = FANTASMA_GALACTICO;
};

Fantasma* FantasmaGalactico::clone()
{
	return new FantasmaGalactico(*this);
}
