#include "FantasmaClasico.h"

FantasmaClasico::FantasmaClasico(Tile* _tile, Texture* _fantasmaClasicoTextura, int _posicionX, int _posicionY, int _velocidadPatron) :
	Fantasma(_tile, _fantasmaClasicoTextura, _posicionX, _posicionY, _velocidadPatron){
	tipoFantasma = FANTASMA_CLASICO;
}

Fantasma* FantasmaClasico::clone()
{
	return new FantasmaClasico(*this);
}
