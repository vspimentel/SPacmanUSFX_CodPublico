#include "FrutaAsesino.h"

FrutaAsesino::FrutaAsesino(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY):
	Fruta(_tile, _frutaTextura, _posicionX, _posicionY){
	GameFrutaTipo = FRUTA_ASESINO;
}

Fruta* FrutaAsesino::clone() {
	return new FrutaAsesino(*this);
}
