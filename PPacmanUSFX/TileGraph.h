#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <array>
#include "Tile.h"

using namespace std;

class TileGraph
{
private:

	vector<Tile*> vectorTilesGraph;
	int getIndice(int _x, int _y);

public:

	static int anchoTileGraph;
	static int altoTileGraph;
		
public:
	TileGraph(int _anchoTileGraph, int _altoTileGraph);
	~TileGraph();

	void reconfigurar(int _anchoTileGraph, int _altoTileGraph);
	Tile* getTileEn(int _x, int _y);

	array<Tile*, 4> get4Vecinos(Tile* _tile);
	array<Tile*, 8> get8Vecinos(Tile* _tile);
	int getAnchoTile() { return anchoTileGraph; }
	int getAltoTile() { return altoTileGraph; }

	array<Tile*, 4> GetNeighbours(Tile* _tile);
	Pacman* getPacman();
};




