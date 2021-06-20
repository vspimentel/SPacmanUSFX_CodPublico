#include "MonedaClasico.h"

MonedaClasico::MonedaClasico(Tile* _tile, Texture* _monedaTextura) :
	Moneda(_tile, _monedaTextura) {
	tipoMoneda = MONEDA_CLASICO;
}

Moneda* MonedaClasico::clone() {
	return new MonedaClasico(*this);
}


