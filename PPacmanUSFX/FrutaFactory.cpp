#include "FrutaFactory.h"

Fruta* FrutaFactory::tipoFrutaClasico = nullptr;
Fruta* FrutaFactory::tipoFrutaGalactico = nullptr;
Fruta* FrutaFactory::tipoFrutaAsesino = nullptr;

Fruta* FrutaFactory::getTipoFrutaClasico() {
	return tipoFrutaClasico->clone();
}

Fruta* FrutaFactory::getTipoFrutaGalactico() {
	return tipoFrutaGalactico->clone();
}

Fruta* FrutaFactory::getTipoFrutaAsesino() {
	return tipoFrutaAsesino->clone();
}