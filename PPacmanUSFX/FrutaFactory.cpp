#include "FrutaFactory.h"

Fruta* FrutaFactory::tipoFruta = nullptr;

Fruta* FrutaFactory::getTipoFruta() {
	return tipoFruta->clone();
}