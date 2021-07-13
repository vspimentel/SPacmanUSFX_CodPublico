#pragma once
#include "MovePacman.h"
class MovePacmanFast : public MovePacman
{
public:
	void move(GamePawn* pacman, MoveDirection direccion);
};

