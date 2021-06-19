#include "MonedaClasico.h"

MonedaClasico::MonedaClasico(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY) :
	Moneda(_tile, _monedaTextura, _posicionX, _posicionY) {
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	tipoMoneda = MONEDA_CLASICO;
}
Moneda* MonedaClasico::clone() {
	return new MonedaClasico(*this);
}


