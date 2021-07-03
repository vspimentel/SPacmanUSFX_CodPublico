#include "FactoryPacmanAsesino.h"

GameObject* FactoryPacmanAsesino::createPacmanInstance(Tile* _tile, int _velocidad) {
    return new PacmanAsesino(_tile, "pacman_asesino", _velocidad);
}

GameObject* FactoryPacmanAsesino::createParedInstance(Tile* _tile) {
    return new ParedAsesino(_tile, "pared_asesino");
}

GameObject* FactoryPacmanAsesino::createParedPoderInstance(Tile* _tile) {
    return new DecoratorElectrico(new ParedAsesino(_tile, "pared_asesino"));
}

GameObject* FactoryPacmanAsesino::createMonedaInstance(Tile* _tile) {
    return new MonedaAsesino(_tile, "moneda_asesino");
}

GameObject* FactoryPacmanAsesino::createMonedaPoderInstance(Tile* _tile) {
    return ((Moneda*)new DecoratorAura(new MonedaAsesino(_tile, "moneda_galactico", PODER_SUPERMONEDA)));
}

