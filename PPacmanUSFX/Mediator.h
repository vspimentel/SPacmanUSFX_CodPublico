#pragma once
#include <string>

using namespace std;

class GameActor;

class Mediator
{
public:
	virtual void notify(GameActor* sender, GameActor* receptor, string evento) const  = 0;
	virtual bool getBool(GameActor* sender, GameActor* receptor, string evento) const = 0;
};

