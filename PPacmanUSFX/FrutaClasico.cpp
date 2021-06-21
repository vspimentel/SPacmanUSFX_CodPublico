#include "FrutaClasico.h"
FrutaClasico::FrutaClasico(Tile* _tile, Texture* _frutaTexture):
	Fruta(_tile, _frutaTexture){
	GameFrutaTipo = FRUTA_CLASICO;
	ancho = Tile::anchoTile + 5;
	alto = Tile::altoTile + 5;
}

Fruta* FrutaClasico::clone() {
	return new FrutaClasico(*this);
}



