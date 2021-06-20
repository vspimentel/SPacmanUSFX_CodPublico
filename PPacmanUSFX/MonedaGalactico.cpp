#include "MonedaGalactico.h"


MonedaGalactico::MonedaGalactico(Tile* _tile, Texture* _monedaTextura) :
	Moneda(_tile, _monedaTextura) {
	tipoMoneda = MONEDA_GALACTICO;
}

