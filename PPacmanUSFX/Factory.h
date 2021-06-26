#pragma once
#include "GameObject.h"
#include "Tile.h"
#include "TextureManager.h"

class Factory
{
public:
	virtual GameObject* createPacmanInstance(Tile* _tile, TextureManager* _texturaManager, int _velocidad) = 0;
	virtual GameObject* createParedInstance(Tile* _tile, TextureManager* _texturaManager) = 0;
	virtual GameObject* createParedPoderInstance(Tile* _tile, TextureManager* _textureManager) = 0;
	virtual GameObject* createMonedaInstance(Tile* _tile, TextureManager* _texturaManager) = 0;
};

