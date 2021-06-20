#include "FantasmaGalactico.h"


FantasmaGalactico::FantasmaGalactico(Tile* _tile, Texture* _fantasmaGalacticoTextura, int _posicionX, int _posicionY, int _velocidad) :
	Fantasma(_tile, _fantasmaGalacticoTextura, _posicionX, _posicionY, _velocidad){
	tipoFantasma = FANTASMA_GALACTICO;
};

Fantasma* FantasmaGalactico::clone()
{
	return new FantasmaGalactico(*this);
}
