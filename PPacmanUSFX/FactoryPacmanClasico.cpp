#include "FactoryPacmanClasico.h"

GameActor* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, int _velocidad) {
    return new PacmanClasico(_tile, "pacman_clasico", _velocidad);
}


GameActor* FactoryPacmanClasico::createParedInstance(Tile* _tile) {
    return new ParedClasico(_tile, "pared_clasico");
}

//GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile) {
 //   return ((Pared*)new ParedClasicoAdapter(_tile, "pared_clasico_adapter"));
//}

GameActor* FactoryPacmanClasico::createParedPoderInstance(Tile* _tile)
{
    return new ParedClasico(_tile, "pared_clasico");
}


GameActor* FactoryPacmanClasico::createMonedaInstance(Tile* _tile) {
    return new MonedaClasico(_tile, "moneda_clasico");
}


GameActor* FactoryPacmanClasico::createMonedaPoderInstance(Tile* _tile) {
    return new MonedaClasico(_tile, "moneda_clasico", PODER_SUPERMONEDA);
}