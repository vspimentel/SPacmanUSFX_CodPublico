#include "FrutaClasico.h"
FrutaClasico::FrutaClasico(Tile* _tile, Texture* _frutaTexture):
	Fruta(_tile, _frutaTexture){
	GameFrutaTipo = FRUTA_CLASICO;
	ancho = Tile::anchoTile;
	alto = Tile::altoTile;
}

Fruta* FrutaClasico::clone() {
	return new FrutaClasico(*this);
}



