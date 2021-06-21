#pragma once
#include "GameObject.h"
#include "Tile.h"
#include "TextureManager.h"

class Factory
{
public:
	virtual GameObject* createPacmanInstance(Tile* _tile, TextureManager* _texturaManager, int _velocidad) = 0;
	virtual GameObject* createParedInstance(Tile* _tile, TextureManager* _texturaManager, bool _isElectric) = 0;
	virtual GameObject* createMonedaInstance(Tile* _tile, TextureManager* _texturaManager) = 0;
};

