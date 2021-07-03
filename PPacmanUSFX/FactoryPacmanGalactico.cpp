#include "FactoryPacmanGalactico.h"

GameObject* FactoryPacmanGalactico::createPacmanInstance(Tile* _tile, int _velocidad) {
    return new PacmanGalactico(_tile, "pacman_galactico", _velocidad);
}

GameObject* FactoryPacmanGalactico::createParedInstance(Tile* _tile) {
    return new ParedGalactico(_tile, "pared_galactico");
}

GameObject* FactoryPacmanGalactico::createParedPoderInstance(Tile* _tile){
    return new DecoratorElectrico(new ParedGalactico(_tile, "pared_galactico"));
}

GameObject* FactoryPacmanGalactico::createMonedaInstance(Tile* _tile) {
    return new MonedaGalactico(_tile, "moneda_galactico");
}

GameObject* FactoryPacmanGalactico::createMonedaPoderInstance(Tile* _tile) {
    return ((Moneda*)new DecoratorAura(new MonedaGalactico(_tile, "moneda_galactico", PODER_SUPERMONEDA)));
}
