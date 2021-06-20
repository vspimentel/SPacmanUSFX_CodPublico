#pragma once

#include "FrutaClasico.h"
#include "FrutaGalactico.h"
#include "FrutaAsesino.h"
#include "TextureManager.h"

class FrutaFactory
{
private:
	static Fruta* tipoFrutaClasico;
	static Fruta* tipoFrutaGalactico;
	static Fruta* tipoFrutaAsesino;

public:
	static void initialize() {
		TextureManager* textures = new TextureManager;
		tipoFrutaClasico = new FrutaClasico(nullptr, textures->getTexture("fruta_clasico"));
		tipoFrutaGalactico = new FrutaGalactico(nullptr, textures->getTexture("fruta_galactico"));
		tipoFrutaAsesino = new FrutaAsesino(nullptr, textures->getTexture("fruta_galactico"));
	}

	static Fruta* getTipoFrutaClasico();
	static Fruta* getTipoFrutaGalactico();
	static Fruta* getTipoFrutaAsesino();
};

