#include "ParedClasicoAdapter.h"

ParedClasicoAdapter::ParedClasicoAdapter(Tile* _tile, string _paredTexturaID, Texture* _paredTextura):
	Pared(_tile, _paredTexturaID), Wall(_tile, _paredTextura)
{
	Wall::CreateClips();
}
