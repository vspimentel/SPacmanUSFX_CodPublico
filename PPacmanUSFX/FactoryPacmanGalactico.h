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
    GameObject* createPacmanInstance(Tile* _tile, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile) override;
    GameObject* createParedPoderInstance(Tile* _tile) override;
    GameObject* createMonedaInstance(Tile* _tile) override;
    GameObject* createMonedaPoderInstance(Tile* _tile) override;
};

