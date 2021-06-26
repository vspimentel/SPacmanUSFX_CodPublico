#include "DecoratorElectrico.h"

DecoratorElectrico::DecoratorElectrico(Pared* _widget):Decorator(_widget) {
	posicionX = _widget->getPosicionX();
	posicionY = _widget->getPosicionY();
	textura = _widget->getTextura();
	ancho = _widget->getAncho();
	alto = _widget->getAlto();
	tileActual = _widget->getTile();
	altoClip = 140;
	anchoClip = 140;
	setTexture(tipoTexturaPared);
}

void DecoratorElectrico::update() {
	Decorator::update();
	velocidadPacman = 5;
	if (cont2 <= notElectricTime) {
		cont2++;
		if (cont2 >= notElectricTime) {
			cont1 = 0;
			setTexture(11);
			state = 1;
		}
	}
	else {
		if (cont1 <= electricTime) {
			cont1++;
			if (cont1 >= electricTime) {
				cont2 = 0;
				setTexture(10);
				state = 0;
				for (auto tile : tileGraph->get4Vecinos(tileActual)) {
					if (tile != nullptr && tile->getPacman() != nullptr && tile->getPacman()->getState() == 2) {
						tile->getPacman()->setVelocidad(velocidadPacman);
						tile->getPacman()->setState(0);
					}
				}
			}
		}
	}
	if (state == 1) {
		for (auto tile : tileGraph->get4Vecinos(tileActual)) {
			if (tile != nullptr && tile->getPacman() != nullptr) {
				tile->getPacman()->setState(2);
				tile->getPacman()->setVelocidad(0);
			}
		}
	}
}