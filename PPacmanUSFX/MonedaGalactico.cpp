#include "MonedaGalactico.h"


MonedaGalactico::MonedaGalactico(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY) :
	Moneda(_tile, _monedaTextura, _posicionX, _posicionY) {
	tipoMoneda = MONEDA_GALACTICO;
}

Moneda* MonedaGalactico::clone() {
	return new MonedaGalactico(*this);
}
