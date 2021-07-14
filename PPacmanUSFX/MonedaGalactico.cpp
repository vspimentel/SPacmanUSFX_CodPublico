#include "MonedaGalactico.h"

MonedaGalactico::MonedaGalactico(Tile* _tile, Texture* _monedaTextura) :
	Moneda(_tile, _monedaTextura) {
	tipoMoneda = MONEDA_GALACTICO;
	framesMovimiento = 9;
}

MonedaGalactico::MonedaGalactico(Tile* _tile, Texture* _monedaTextura, PODER_MONEDA _poder) :
	Moneda(_tile, _monedaTextura, _poder) {
	tipoMoneda = MONEDA_GALACTICO;
	framesMovimiento = 9;
}
