#include "FactoryPacmanGalactico.h"

GameObject* FactoryPacmanGalactico::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) {
    return new PacmanGalactico(_tile, "pacman_galactico", _velocidad);
}

GameObject* FactoryPacmanGalactico::createParedInstance(Tile* _tile, TextureManager* _textureManager) {
    return new ParedGalactico(_tile, "pared_galactico");
}

GameObject* FactoryPacmanGalactico::createParedPoderInstance(Tile* _tile, TextureManager* _textureManager){
    return new DecoratorElectrico(new ParedGalactico(_tile, "pared_galactico"));
}

GameObject* FactoryPacmanGalactico::createMonedaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new MonedaGalactico(_tile, "moneda_galactico");
}
