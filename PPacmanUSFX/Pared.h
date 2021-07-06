#pragma once
#include <string> 

#include "GameActor.h"


class Pared : public GameActor
{
protected:

    int tipoTexturaPared;
    int state;

public:

    Pared(Tile* _tile, string _paredTextura);
    Pared();
    ~Pared();

    void setTile(Tile* _tileNuevo);
    void setTexture(int tipoTextura);

    void deleteGameObject() override;
};

