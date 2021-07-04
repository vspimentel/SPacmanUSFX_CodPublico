#pragma once
#include "Decorator.h"
#include "TextureManager.h"
#include "Pacman.h"
class DecoratorAura : public Decorator
{
private:
	const int timeState = 500;
	int contState = 500;
public:
	DecoratorAura(GameObject* widget);
	void draw();
	void update() override;
	void deleteGameObject() override;

	void setWidget(GameObject* _widget) { 
		widget = _widget;
		Decorator::widget = _widget;
		if (widget->getTipoObjeto() == PACMAN) {
			contState = 0;
		}
	}
};

