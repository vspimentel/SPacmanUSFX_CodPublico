#include "FactoryPacmanAsesino.h"

GameObject* FactoryPacmanAsesino::createPacmanInstance(Tile* _tile, TextureManager* _textureManager, int _velocidad) {
    return new PacmanAsesino(_tile, "pacman_asesino", _velocidad);
}

GameObject* FactoryPacmanAsesino::createParedInstance(Tile* _tile, TextureManager* _textureManager) {
    return new ParedAsesino(_tile, "pared_asesino");
}

GameObject* FactoryPacmanAsesino::createParedPoderInstance(Tile* _tile, TextureManager* _textureManager) {
    return new DecoratorElectrico(new ParedAsesino(_tile, "pared_asesino"));
}

GameObject* FactoryPacmanAsesino::createMonedaInstance(Tile* _tile, TextureManager* _textureManager) {
    return new MonedaAsesino(_tile, "moneda_asesino");
}
