#include "FrutaClasico.h"
using namespace std;
FrutaClasico::FrutaClasico(Tile* _tile, Texture* _frutaTexture, int _posicionX, int _posicionY):
	Fruta(_tile, _frutaTexture, _posicionX, _posicionY){
	GameFrutaTipo = FRUTA_CLASICO;
}

Fruta* FrutaClasico::clone() {
	return new FrutaClasico(*this);
}



