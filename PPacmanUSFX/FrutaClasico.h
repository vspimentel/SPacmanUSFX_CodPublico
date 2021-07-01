#pragma once
#include "Fruta.h"
class FrutaClasico : public Fruta
{
public:
	FrutaClasico(Tile* _tile, string _frutaTexture);
	Fruta* clone();
};
 