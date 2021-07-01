#include "FantasmaClasico.h"

FantasmaClasico::FantasmaClasico(Tile* _tile, string _fantasmaClasicoTextura, int _velocidadPatron) :
	Fantasma(_tile, _fantasmaClasicoTextura, _velocidadPatron){
	tipoFantasma = FANTASMA_CLASICO;
}

Fantasma* FantasmaClasico::clone()
{
	return new FantasmaClasico(*this);
}
