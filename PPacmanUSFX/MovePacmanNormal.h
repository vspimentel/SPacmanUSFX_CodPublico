#pragma once
#include "MovePacman.h"
class MovePacmanNormal :
    public MovePacman
{
public:
    void move(GamePawn* pacman, MoveDirection direccion);
};

