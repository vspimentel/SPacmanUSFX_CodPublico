#pragma once
#include "FantasmaClasico.h"
#include "FantasmaGalactico.h"
#include "TextureManager.h" 

class FantasmasFactory
{
private:
	static Fantasma* tipoClasicoBlinky;
	static Fantasma* tipoClasicoClyde;
	static Fantasma* tipoClasicoInkey;
	static Fantasma* tipoClasicoPinky;

	static Fantasma* tipoGalacticoBlinky;
	static Fantasma* tipoGalacticoClyde;
	static Fantasma* tipoGalacticoInkey;
	static Fantasma* tipoGalacticoPinky;

public:
	static void  initialize()
	{
		TextureManager* textures = new TextureManager;
		tipoClasicoBlinky = new FantasmaClasico(nullptr, textures->getTexture("fantasma_clasico1"), 0);
		tipoClasicoClyde = new FantasmaClasico(nullptr, textures->getTexture("fantasma_clasico2"), 0);
		tipoClasicoInkey = new FantasmaClasico(nullptr, textures->getTexture("fantasma_clasico3"), 0);
		tipoClasicoPinky = new FantasmaClasico(nullptr, textures->getTexture("fantasma_clasico4"), 0);
		
		tipoGalacticoBlinky = new FantasmaGalactico(nullptr, textures->getTexture("fantasma_galactico1"), 0);
		tipoGalacticoClyde = new FantasmaGalactico(nullptr, textures->getTexture("fantasma_galactico2"), 0);
		tipoGalacticoInkey = new FantasmaGalactico(nullptr, textures->getTexture("fantasma_galactico3"), 0);
		tipoGalacticoPinky = new FantasmaGalactico(nullptr, textures->getTexture("fantasma_galactico4"), 0);
	}

	static Fantasma* getTipoClasicoBlinky();
	static Fantasma* getTipoClasicoClyde();
	static Fantasma* getTipoClasicoInkey();
	static Fantasma* getTipoClasicoPinky();
	
	static Fantasma* getTipoGalacticoBlinky();
	static Fantasma* getTipoGalacticoClyde();
	static Fantasma* getTipoGalacticoInkey();
	static Fantasma* getTipoGalacticoPinky();

};



