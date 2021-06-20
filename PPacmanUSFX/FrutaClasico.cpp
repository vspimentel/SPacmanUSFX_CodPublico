#include "FrutaClasico.h"
FrutaClasico::FrutaClasico(Tile* _tile, Texture* _frutaTexture):
	Fruta(_tile, _frutaTexture){
	GameFrutaTipo = FRUTA_CLASICO;
}

Fruta* FrutaClasico::clone() {
	return new FrutaClasico(*this);
}



