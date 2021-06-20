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

	int cont = 0;

public:

	MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, Factory* fabrica);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	void newObjects();

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameObject*> &_vectorObjetosJuegoGM);
};

