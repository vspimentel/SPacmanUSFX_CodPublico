#pragma once
#include "Pared.h"
#include "Wall.h"

class ParedClasicoAdapter :
    public Pared, private Wall
{
public:
    ParedClasicoAdapter(Tile* _tile, string _paredTexturaID, Texture* _paredTextura);
    
    void render() override { Wall::Render(); }
};

