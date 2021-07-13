#pragma once
#include "MovePacman.h"

class MovePacmanSlow : public MovePacman
{
public:
	void move(GamePawn* pacman, MoveDirection direccion);
};

