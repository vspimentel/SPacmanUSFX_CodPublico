#include "MonedaClasico.h"

MonedaClasico::MonedaClasico(Tile* _tile, string _monedaTextura) :
	Moneda(_tile, _monedaTextura) {
	tipoMoneda = MONEDA_CLASICO;
}



