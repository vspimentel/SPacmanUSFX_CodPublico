#include "FactoryPacmanClasico.h"

GameActor* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, int _velocidad) {
    return new PacmanClasico(_tile, "pacman_clasico", _velocidad);
}


GameActor* FactoryPacmanClasico::createParedInstance(Tile* _tile) {
    return new ParedClasico(_tile, FlyweightFactory::getTexture("pared_clasico", "Resources/Pared.png"));
}

//GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile) {
 //   return ((Pared*)new ParedClasicoAdapter(_tile, "pared_clasico_adapter"));
//}

GameActor* FactoryPacmanClasico::createParedPoderInstance(Tile* _tile)
{
    return new ParedClasico(_tile, FlyweightFactory::getTexture("pared_clasico", "Resources/Pared.png"));
}


GameActor* FactoryPacmanClasico::createMonedaInstance(Tile* _tile) {
    return new MonedaClasico(_tile, FlyweightFactory::getTexture("moneda_clasico", "Resources/MonedasClasico.png"));
}


GameActor* FactoryPacmanClasico::createMonedaPoderInstance(Tile* _tile) {
    return new MonedaClasico(_tile, FlyweightFactory::getTexture("moneda_clasico", "Resources/MonedasClasico.png"), PODER_SUPERMONEDA);
}