#include "FrutaAsesino.h"

FrutaAsesino::FrutaAsesino(Tile* _tile, Texture* _frutaTextura):
	Fruta(_tile, _frutaTextura){
	GameFrutaTipo = FRUTA_ASESINO;
}

Fruta* FrutaAsesino::clone() {
	return new FrutaAsesino(*this);
}
