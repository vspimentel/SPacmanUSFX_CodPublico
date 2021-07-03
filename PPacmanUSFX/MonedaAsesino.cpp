#include "MonedaAsesino.h"
MonedaAsesino::MonedaAsesino(Tile* _tile, string _monedaTextura) :
	Moneda(_tile, _monedaTextura) {

}

MonedaAsesino::MonedaAsesino(Tile* _tile, string _monedaTextura, PODER_MONEDA _poder):
	Moneda(_tile, _monedaTextura, _poder) {
}
