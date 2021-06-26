#pragma once
#include "Factory.h"
#include "PacmanGalactico.h"
#include "ParedGalactico.h"
#include "MonedaGalactico.h"
#include "DecoratorElectrico.h"

class FactoryPacmanGalactico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createParedPoderInstance(Tile* _tile, TextureManager* _textureManager) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _textureManager) override;
};

