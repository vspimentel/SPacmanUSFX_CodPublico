#include "FactoryPacmanAsesino.h"

GameActor* FactoryPacmanAsesino::createPacmanInstance(Tile* _tile, int _velocidad) {
    return new PacmanAsesino(_tile, "pacman_asesino", _velocidad);
}

GameActor* FactoryPacmanAsesino::createParedInstance(Tile* _tile) {
    return new ParedAsesino(_tile, "pared_asesino");
}

GameActor* FactoryPacmanAsesino::createParedPoderInstance(Tile* _tile) {
    return new DecoratorElectrico(new ParedAsesino(_tile, "pared_asesino"));
}

GameActor* FactoryPacmanAsesino::createMonedaInstance(Tile* _tile) {
    return new MonedaAsesino(_tile, "moneda_asesino");
}

GameActor* FactoryPacmanAsesino::createMonedaPoderInstance(Tile* _tile) {
    return new MonedaAsesino(_tile, "moneda_galactico", PODER_SUPERMONEDA);
}

