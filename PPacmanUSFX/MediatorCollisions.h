#pragma once
#include "Mediator.h"
#include "GameActor.h"
#include "GameObject.h"
#include "Moneda.h"
#include "DecoratorAura.h"
class MediatorCollisions : public Mediator
{
	void notify(GameActor* sender, GameActor* receptor, string evento) const override;
	bool getBool(GameActor* sender, GameActor* receptor, string evento) const override;
};

