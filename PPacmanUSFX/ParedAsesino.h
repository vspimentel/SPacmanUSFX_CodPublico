#pragma once
#include "Tile.h"
#include "Pared.h"
#include "Pacman.h"

class ParedAsesino : public Pared
{
private:

    int velocidadPacman;
    bool isElectrica;
    int cont1 = 50;
    int cont2 = 100;
    const int electricTime = 50;
    const int notElectricTime = 100;

public:

    ParedAsesino(Tile* _tile, Texture* _paredTextura);

};
