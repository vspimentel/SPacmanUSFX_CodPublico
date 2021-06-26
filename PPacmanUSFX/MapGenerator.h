#pragma once
#include<vector>
#include <fstream>

#include "GameObject.h"
#include "Tile.h"
#include "TileGraph.h"
#include "TextureManager.h"
#include "FactoryPacmanClasico.h"
#include "FactoryPacmanGalactico.h"
#include "Factory.h"
#include "FantasmasFactory.h"
#include "FrutaFactory.h"
#include "GamePanel.h"

using namespace std;

class MapGenerator
{
private:

	vector<GameObject*> vectorObjetosJuego;
	TileGraph* tileGraph;
	TextureManager* textureManager;
	Factory* factory;

	Tile* start;

	int contFruta = 0;
	const int frutaTime = 300;

	int contDelay = 100;
	const int delayTime = 100;

	MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, Factory* fabrica);
	static MapGenerator* instance;

public:

	static MapGenerator* createInstance(TileGraph* _tileGraph, TextureManager* _textureManager, Factory* fabrica);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	void newObjects();

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameObject*> &_vectorObjetosJuegoGM);
};

