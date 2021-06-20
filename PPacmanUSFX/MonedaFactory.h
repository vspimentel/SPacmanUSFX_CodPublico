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
		TextureManager* textures = new TextureManager;
		tipoMonedaClasico = new MonedaClasico(nullptr, textures->getTexture("moneda_clasico"));
		tipoSuperMonedaClasico = new MonedaClasico(nullptr, textures->getTexture("supermoneda_clasico"));

		tipoMonedaGalactico = new MonedaGalactico(nullptr, textures->getTexture("moneda_galactico"));
		tipoSuperMonedaGalactico = new MonedaGalactico(nullptr, textures->getTexture("supermoneda_galactico"));
	}

	static Moneda* getTipoMonedaClasico();
	static Moneda* getTipoSuperMonedaClasico();

	static Moneda* getTipoMonedaGalactico();
	static Moneda* getTipoSuperMonedaGalactico();
};


