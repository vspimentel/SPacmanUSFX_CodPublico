#pragma once
#include "GameObject.h"
#include "DecoratorAura.h"

class Factory
{
public:
	virtual GameObject* createPacmanInstance(Tile* _tile, int _velocidad) = 0;
	virtual GameObject* createParedInstance(Tile* _tile) = 0;
	virtual GameObject* createParedPoderInstance(Tile* _tile) = 0;
	virtual GameObject* createMonedaInstance(Tile* _tile) = 0;
	virtual GameObject* createMonedaPoderInstance(Tile* _tile) = 0;
};

