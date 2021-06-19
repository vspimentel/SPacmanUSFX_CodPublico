#include "MonedaFactory.h"

Moneda* MonedaFactory::tipoMonedaClasico = nullptr;
Moneda* MonedaFactory::tipoSuperMonedaClasico = nullptr;

Moneda* MonedaFactory::tipoMonedaGalactico = nullptr;
Moneda* MonedaFactory::tipoSuperMonedaGalactico = nullptr;

Moneda* MonedaFactory::getTipoMonedaClasico() {
	return tipoMonedaClasico->clone();
}

Moneda* MonedaFactory::getTipoSuperMonedaClasico() {
	return tipoSuperMonedaClasico->clone();
}

Moneda* MonedaFactory::getTipoMonedaGalactico() {
	return tipoMonedaGalactico->clone();
}

Moneda* MonedaFactory::getTipoSuperMonedaGalactico() {
	return tipoSuperMonedaGalactico->clone();
}