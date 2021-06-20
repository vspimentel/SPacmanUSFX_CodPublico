#include "FrutaGalactico.h"

using namespace std;

FrutaGalactico::FrutaGalactico(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY):
	Fruta(_tile, _frutaTextura, _posicionX, _posicionY){
	GameFrutaTipo = FRUTA_GALACTICO;
}

Fruta* FrutaGalactico::clone() {
	return new FrutaGalactico(*this);
}
