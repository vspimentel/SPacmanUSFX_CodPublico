#pragma once
#include "GamePawn.h"
#include "MoveDirection.h"

class MovePacman
{
public:
	virtual void move(GamePawn* pacman, MoveDirection direccion) = 0;
};