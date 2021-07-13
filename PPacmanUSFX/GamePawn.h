#pragma once
#include "GameActor.h"
class GamePawn : public GameActor
{
protected:
	int velocidad;

public:
	GamePawn(string _textureID, Tile* _tile);

	int getVelocidad() { return velocidad; }
};

