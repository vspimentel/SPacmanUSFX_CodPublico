#pragma once
#include "Factory.h"
#include "PacmanClasico.h"
#include "ParedClasico.h"
#include "ParedClasicoAdapter.h"
#include "MonedaClasico.h"

class FactoryPacmanClasico :
    public Factory
{
public:
    GameActor* createPacmanInstance(Tile* _tile, int _velocidad) override;
    GameActor* createParedInstance(Tile* _tile) override;
    GameActor* createParedPoderInstance(Tile* _tile) override;
    GameActor* createMonedaInstance(Tile* _tile) override;
    GameActor* createMonedaPoderInstance(Tile* _tile) override;
};

