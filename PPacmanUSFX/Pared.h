#pragma once
#include "GameObject.h"

class Pared : public GameObject
{
protected:

    int tipoTexturaPared;
    int state;

public:

    Pared(Tile* _tile, Texture* _paredTextura);
    Pared();
    ~Pared();

    void setTile(Tile* _tileNuevo);
    void setTexture(int tipoTextura);

    void deleteGameObject() override;
};

