#include "MonedaClasico.h"

MonedaClasico::MonedaClasico(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY) :
	Moneda(_tile, _monedaTextura, _posicionX, _posicionY) {
}

Moneda* MonedaClasico::clone() {
	return new MonedaClasico(*this);
}

