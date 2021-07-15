#include "ProxyPathFinder.h"

vector<Tile*> ProxyPathFinder::getPath(Tile* tileStart, Tile* tileEnd)
{
	PathFinder astar(GameObject::tileGraph);
	astar.SetAvoidFunction(ProxyPathFinder::avoidInPathFinder);
	path = astar.CalculateRoute(tileStart, tileEnd);
	return path;
}

bool ProxyPathFinder::avoidInPathFinder(Tile* _tile)
{
	if (_tile->getPared() != nullptr)
		return true;
	return false;
}
