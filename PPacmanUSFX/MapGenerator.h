#pragma once
#include<vector>
#include <fstream>

#include "GameObject.h"
#include "Tile.h"
#include "TileGraph.h"
#include "TextureManager.h"
#include "Factory.h"
#include "FantasmasFactory.h"
#include "FrutaFactory.h"
#include "Decorator.h"
#include "DecoratorElectrico.h"
#include "DecoratorAura.h"
#include "GamePanel.h"

using namespace std;

class MapGenerator
{
private:
	TileGraph* tileGraph;
	Factory* factory;

	Tile* start;
	string textura;
	int velocidad;

	int contFruta = 0;
	const int frutaTime = 300;

	int contDelay = 100;
	const int delayTime = 100;

	int contDelayP = 10;
	const int delayPTime = 10;

	MapGenerator(TileGraph* _tileGraph, Factory* fabrica);
	static MapGenerator* instance;

public:

	Tile* getStart() { return start; }

	vector<GameActor*> actors;

	static MapGenerator* createInstance(TileGraph* _tileGraph, Factory* fabrica);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	void newObjects();

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameActor*> &_vectorObjetosJuegoGM);
};

