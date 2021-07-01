#pragma once
#include "FantasmaClasico.h"
#include "FantasmaGalactico.h"
#include "FantasmaAsesino.h"
#include "TextureManager.h" 

class FantasmasFactory
{
private:
	 
	static Fantasma* tipoBlinky;
	static Fantasma* tipoClyde;
	static Fantasma* tipoInkey;
	static Fantasma* tipoPinky;

public:

	static void  initializeClasico()
	{
		TextureManager* textures = TextureManager::createInstance();
		tipoBlinky = new FantasmaClasico(nullptr, "fantasma_clasico1", 0);
		tipoClyde = new FantasmaClasico(nullptr, "fantasma_clasico2", 0);
		tipoInkey = new FantasmaClasico(nullptr, "fantasma_clasico3", 0);
		tipoPinky = new FantasmaClasico(nullptr, "fantasma_clasico4", 0);
	}

	static void initializeGalactico(){
		TextureManager* textures = TextureManager::createInstance();
		tipoBlinky = new FantasmaGalactico(nullptr, "fantasma_galactico1", 0);
		tipoClyde = new FantasmaGalactico(nullptr, "fantasma_galactico2", 0);
		tipoInkey = new FantasmaGalactico(nullptr, "fantasma_galactico3", 0);
		tipoPinky = new FantasmaGalactico(nullptr, "fantasma_galactico4", 0);
	}

	static void initializaeAsesino() {
		TextureManager* textures = TextureManager::createInstance();
		tipoBlinky = new FantasmaAsesino(nullptr, "fantasma_galactico1", 0);
		tipoClyde = new FantasmaAsesino(nullptr, "fantasma_galactico2", 0);
		tipoInkey = new FantasmaAsesino(nullptr, "fantasma_galactico3", 0);
		tipoPinky = new FantasmaAsesino(nullptr, "fantasma_galactico4", 0);
	}

	static Fantasma* getTipoBlinky();
	static Fantasma* getTipoClyde();
	static Fantasma* getTipoInkey();
	static Fantasma* getTipoPinky();

};



