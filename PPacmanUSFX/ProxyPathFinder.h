#pragma once
#include "PathFinder.h"
#include "GameObject.h"
#include "TileGraph.h"
class ProxyPathFinder
{
private:
	vector<Tile*> path;
public:
	vector<Tile*> getPath(Tile* tileStart, Tile* tileEnd);
	static bool avoidInPathFinder(Tile* _tile);
};

