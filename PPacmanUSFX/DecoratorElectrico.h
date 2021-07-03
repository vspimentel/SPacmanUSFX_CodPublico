#pragma once
#include "Decorator.h"
#include "Pacman.h"
class DecoratorElectrico : public Decorator
{
private:
    int velocidadPacman;
    int state;
    int cont1 = 50;
    int cont2 = 100;
    const int electricTime = 50;
    const int notElectricTime = 100;
    int tipoTexturaPared;
public:
    DecoratorElectrico(Pared* _widget);
    void update();
};

