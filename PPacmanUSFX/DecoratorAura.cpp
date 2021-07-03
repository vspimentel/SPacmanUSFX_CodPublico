#include "DecoratorAura.h"

DecoratorAura::DecoratorAura(GameObject* _widget) : Decorator(_widget)
{
	posicionX = _widget->getPosicionX();
	posicionY = _widget->getPosicionY();
	textureID = _widget->getTexturaID();
	ancho = _widget->getAncho();
	alto = _widget->getAlto();
	tileActual = _widget->getTile();
	tileActual->setSuperMoneda(this);
	altoClip = _widget->getAncho();
	anchoClip = _widget->getAlto();
	framesMovimiento = 9;
	tipoPoderMoneda = PODER_SUPERMONEDA;
}

void DecoratorAura::draw() {
	Decorator::draw();
	TextureManager::createInstance()->drawFrame("aura_clasico", posicionX, posicionY,
		ancho, alto, 0, 0, 556, 556, 0, alpha);
}

void DecoratorAura::updateFrames() {
	contadorFrames++;
	if (contadorFrames >= 10)
	{
		widget->setFrameX(widget->getFrameX() + 1);
		if (widget->getFrameX() == framesMovimiento)
		{
			widget->setFrameX(widget->getFrameX() - framesMovimiento);
		}
		contadorFrames = 0;
	}
}

void DecoratorAura::deleteGameObject() {
	GameObject::deleteGameObject();
	widget->deleteGameObject();
	tileActual->setMoneda(nullptr);
	visible = false;
}