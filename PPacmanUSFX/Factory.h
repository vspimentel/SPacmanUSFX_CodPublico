#pragma once
#include "GameObject.h"
#include "DecoratorAura.h"

class Factory
{
public:
	virtual GameActor* createPacmanInstance(Tile* _tile, int _velocidad) = 0;
	virtual GameActor* createParedInstance(Tile* _tile) = 0;
	virtual GameActor* createParedPoderInstance(Tile* _tile) = 0;
	virtual GameActor* createMonedaInstance(Tile* _tile) = 0;
	virtual GameActor* createMonedaPoderInstance(Tile* _tile) = 0;
};

