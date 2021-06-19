#pragma once
#include "Moneda.h"
#include "MonedaClasico.h"
#include "MonedaGalactico.h"
#include "TextureManager.h"
class MonedaFactory
{
private:


	static Moneda* tipoMonedaClasico;
	static Moneda* tipoSuperMonedaClasico;

	static Moneda* tipoMonedaGalactico;
	static Moneda* tipoSuperMonedaGalactico;

public:
	static void initialize() {
		tipoMonedaClasico = new MonedaClasico(nullptr, (new TextureManager())->getTexture("moneda_clasico"), 0, 0);
		tipoSuperMonedaClasico = new MonedaClasico(nullptr, (new TextureManager())->getTexture("supermoneda_clasico"), 0, 0);

		tipoMonedaGalactico = new MonedaGalactico(nullptr, (new TextureManager())->getTexture("moneda_galactico"), 0, 0);
		tipoSuperMonedaGalactico = new MonedaGalactico(nullptr, (new TextureManager())->getTexture("supermoneda_galactico"), 0, 0);
	}

	static Moneda* getTipoMonedaClasico();
	static Moneda* getTipoSuperMonedaClasico();

	static Moneda* getTipoMonedaGalactico();
	static Moneda* getTipoSuperMonedaGalactico();
};


