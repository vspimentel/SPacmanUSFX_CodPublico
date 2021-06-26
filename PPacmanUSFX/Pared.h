#pragma once
#include "GameObject.h"

class Pared : public GameObject
{
protected:

    //int frameX;
    //int frameY;

    //int altoClip;
    //int anchoClip;

    int tipoTexturaPared;

    int state;

public:

    Pared(Tile* _tile, Texture* _paredTextura);
    ~Pared();

    void setTile(Tile* _tileNuevo);
    void setTexture(int tipoTextura);

    void deleteGameObject() override;
};

