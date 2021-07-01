#pragma once

#include "Pared.h"

class ParedClasico :public Pared
{
private:

	const int timeColor = 50;
	int cont;

public:

	ParedClasico(Tile* _tile, string _paredTextura);
	void update();

};

