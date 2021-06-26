#pragma once
#include "Pared.h"
class Decorator : public Pared
{
protected:
    Pared* widget;
public:
    Decorator(Pared* _widget);
    void update();
};

