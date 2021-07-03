#include "MonedaClasico.h"

MonedaClasico::MonedaClasico(Tile* _tile, string _monedaTextura) :
	Moneda(_tile, _monedaTextura) {
	tipoMoneda = MONEDA_CLASICO;
}

MonedaClasico::MonedaClasico(Tile* _tile, string _monedaTextura, PODER_MONEDA _poder): 
	Moneda(_tile, _monedaTextura, _poder) {
	tipoMoneda = MONEDA_CLASICO;
}



