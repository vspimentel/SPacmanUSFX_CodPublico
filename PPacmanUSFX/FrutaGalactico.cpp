#include "FrutaGalactico.h"

using namespace std;

FrutaGalactico::FrutaGalactico(Tile* _tile, string _frutaTextura):
	Fruta(_tile, _frutaTextura){
	GameFrutaTipo = FRUTA_GALACTICO;
}

Fruta* FrutaGalactico::clone() {
	return new FrutaGalactico(*this);
}