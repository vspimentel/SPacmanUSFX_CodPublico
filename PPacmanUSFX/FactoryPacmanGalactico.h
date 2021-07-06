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
    GameActor* createPacmanInstance(Tile* _tile, int _velocidad) override;
    GameActor* createParedInstance(Tile* _tile) override;
    GameActor* createParedPoderInstance(Tile* _tile) override;
    GameActor* createMonedaInstance(Tile* _tile) override;
    GameActor* createMonedaPoderInstance(Tile* _tile) override;
};

