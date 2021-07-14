#include "DecoratorAura.h"

DecoratorAura::DecoratorAura(GameActor* _widget) : Decorator(_widget)
{
	tileActual = _widget->getTile();
	if (tileActual != nullptr)
		tileActual->setSupermoneda(this);
}

void DecoratorAura::draw() {
	if (widget != nullptr) {
		TextureManager::createInstance()->drawFrame("aura_clasico", widget->getPosicionX(), widget->getPosicionY(),
			widget->getAncho(), widget->getAlto(), 0, 0, 556, 556, 0, alpha);
	}
	else {
		deleteGameObject();
	}
}

void DecoratorAura::update() {
	if (widget->getTipoObjeto() == PACMAN) {
		if (contState <= timeState) {
			contState++;
		}
		else {
			contState = 0;
			deleteGameObject();
		}
	}
}

void DecoratorAura::deleteGameObject() {
	GameObject::deleteGameObject();
}