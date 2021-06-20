#include "FactoryPacmanClasico.h"

GameObject* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) {
    return new PacmanClasico(_tile, _textureManager->getTexture("pacman_clasico"), _velocidad);
}

GameObject* FactoryPacmanClasico::createFantasmaInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) {
    return new FantasmaClasico(_tile, _textureManager->getTexture("fantasma_clasico1"), _velocidad);
}

GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, TextureManager* _textureManager, bool _isElectric) {
    return new ParedClasico(_tile, _textureManager->getTexture("pared_clasico"));
}

//GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, TextureManager* _textureManager, bool _isElectric) {
 //   return ((Pared*)new ParedClasicoAdapter(_tile, _textureManager->getTexture("pared_clasico_adapter")));
//}

GameObject* FactoryPacmanClasico::createFrutaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new FrutaClasico(_tile, _textureManager->getTexture("fruta_clasico"));
}

GameObject* FactoryPacmanClasico::createMonedaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new MonedaClasico(_tile, _textureManager->getTexture("moneda_clasico"));
}
