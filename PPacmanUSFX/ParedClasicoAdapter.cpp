#include "ParedClasicoAdapter.h"

ParedClasicoAdapter::ParedClasicoAdapter(Tile* _tile, Texture* _paredTextura):
	Pared(_tile, _paredTextura), Wall(_tile, _paredTextura)
{
	Wall::CreateClips();
}
