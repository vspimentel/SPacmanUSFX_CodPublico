#include "FactoryPacmanAsesino.h"

GameActor* FactoryPacmanAsesino::createPacmanInstance(Tile* _tile, int _velocidad) {
    return new PacmanAsesino(_tile, "pacman_asesino", _velocidad);
}

GameActor* FactoryPacmanAsesino::createParedInstance(Tile* _tile) {
    return new ParedAsesino(_tile, FlyweightFactory::getTexture("pared_asesino", "Resources/Pared.png"));
}

GameActor* FactoryPacmanAsesino::createParedPoderInstance(Tile* _tile) {
    return new DecoratorElectrico(new ParedAsesino(_tile, FlyweightFactory::getTexture("pared_asesino", "Resources/Pared.png")));
}

GameActor* FactoryPacmanAsesino::createMonedaInstance(Tile* _tile) {
    return new MonedaAsesino(_tile, FlyweightFactory::getTexture("moneda_asesino", "Resources/MonedasGalactico.png"));
}

GameActor* FactoryPacmanAsesino::createMonedaPoderInstance(Tile* _tile) {
    return new MonedaAsesino(_tile, FlyweightFactory::getTexture("moneda_asesino", "Resources/MonedasGalactico.png"), PODER_SUPERMONEDA);
}

