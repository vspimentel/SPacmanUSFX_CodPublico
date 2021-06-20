#include "FactoryPacmanGalactico.h"

GameObject* FactoryPacmanGalactico::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) {
    return new PacmanGalactico(_tile, _textureManager->getTexture("pacman_galactico"), _velocidad);
}

GameObject* FactoryPacmanGalactico::createFantasmaInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) {
    return new FantasmaGalactico(_tile, _textureManager->getTexture("fantasma_galactico1"), _velocidad);
}

GameObject* FactoryPacmanGalactico::createParedInstance(Tile* _tile, TextureManager* _textureManager, bool _isElectric) {
    return new ParedGalactico(_tile, _textureManager->getTexture("pared_galactico"), _isElectric);
}

GameObject* FactoryPacmanGalactico::createFrutaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new FrutaGalactico(_tile, _textureManager->getTexture("fruta_galactico"));
}

GameObject* FactoryPacmanGalactico::createMonedaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new MonedaGalactico(_tile, _textureManager->getTexture("moneda_galactico"));
}
