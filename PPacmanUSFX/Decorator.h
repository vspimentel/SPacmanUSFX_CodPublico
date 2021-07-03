#pragma once
#include "Pared.h"
class Decorator : public GameObject
{
protected:
    GameObject* widget;
public:
    Decorator(GameObject* _widget);
    void update();
    void draw();
};

