#pragma once
#include "Factory.h"
#include "PacmanGalactico.h"
#include "ParedGalactico.h"
#include "MonedaGalactico.h"

class FactoryPacmanGalactico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _textureManager, bool _isElectric) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _textureManager) override;
};

