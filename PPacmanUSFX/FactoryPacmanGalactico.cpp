#include "FactoryPacmanGalactico.h"

GameActor* FactoryPacmanGalactico::createPacmanInstance(Tile* _tile, int _velocidad) {
    return new PacmanGalactico(_tile, "pacman_galactico", _velocidad);
}

GameActor* FactoryPacmanGalactico::createParedInstance(Tile* _tile) {
    return new ParedGalactico(_tile, FlyweightFactory::getTexture("pared_galactico", "Resources/Pared.png"));
}

GameActor* FactoryPacmanGalactico::createParedPoderInstance(Tile* _tile){
    return new DecoratorElectrico(new ParedGalactico(_tile, FlyweightFactory::getTexture("pared_galactico", "Resources/Pared.png")));
}

GameActor* FactoryPacmanGalactico::createMonedaInstance(Tile* _tile) {
    return new MonedaGalactico(_tile, FlyweightFactory::getTexture("moneda_galactico", "Resources/MonedasGalactico.png"));
}

GameActor* FactoryPacmanGalactico::createMonedaPoderInstance(Tile* _tile) {
    return new MonedaGalactico(_tile, FlyweightFactory::getTexture("moneda_galactico", "Resources/MonedasGalactico.png"), PODER_SUPERMONEDA);
}
