#pragma once
#include "GameActor.h"
class Decorator : public GameActor
{
protected:
    GameObject* widget;
public:
    Decorator(GameObject* _widget);
    void update();
    void draw();
    void render();
};

