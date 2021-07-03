#include "FactoryPacmanClasico.h"

GameObject* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, int _velocidad) {
    return new PacmanClasico(_tile, "pacman_clasico", _velocidad);
}


GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile) {
    return new ParedClasico(_tile, "pared_clasico");
}

//GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile) {
 //   return ((Pared*)new ParedClasicoAdapter(_tile, "pared_clasico_adapter"));
//}

GameObject* FactoryPacmanClasico::createParedPoderInstance(Tile* _tile)
{
    return new ParedClasico(_tile, "pared_clasico");
}


GameObject* FactoryPacmanClasico::createMonedaInstance(Tile* _tile) {
    return new MonedaClasico(_tile, "moneda_clasico");
}


GameObject* FactoryPacmanClasico::createMonedaPoderInstance(Tile* _tile) {
    return ((Moneda*)new DecoratorAura(new MonedaClasico(_tile, "moneda_clasico", PODER_SUPERMONEDA)));
}