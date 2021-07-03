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
    GameObject* createPacmanInstance(Tile* _tile, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile) override;
    GameObject* createParedPoderInstance(Tile* _tile) override;
    GameObject* createMonedaInstance(Tile* _tile) override;
    GameObject* createMonedaPoderInstance(Tile* _tile) override;
};

