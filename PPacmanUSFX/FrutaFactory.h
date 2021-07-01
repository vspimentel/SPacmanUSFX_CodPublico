#pragma once

#include "FrutaClasico.h"
#include "FrutaGalactico.h"
#include "FrutaAsesino.h"
#include "TextureManager.h"

class FrutaFactory
{
private:

	static Fruta* tipoFruta;

public:

	static void initializeClasico() {
		TextureManager* textures = TextureManager::createInstance();
		tipoFruta = new FrutaClasico(nullptr, "fruta_clasico");
	}

	static void initializeGalactico() {
		TextureManager* textures = TextureManager::createInstance();
		tipoFruta = new FrutaGalactico(nullptr, "fruta_galactico");
	}

	static void initializeAsesino() {
		TextureManager* textures = TextureManager::createInstance();
		tipoFruta = new FrutaAsesino(nullptr, "fruta_galactico");
	}

	static Fruta* getTipoFruta();
};

