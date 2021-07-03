#pragma once
#include "Decorator.h"
#include "TextureManager.h"
class DecoratorAura : public Decorator
{
public:
	DecoratorAura(GameObject* widget);
	void draw();
	void updateFrames();
	void deleteGameObject() override;
};

