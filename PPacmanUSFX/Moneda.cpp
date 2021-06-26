#include "Moneda.h"

Moneda::Moneda(Tile* _tile, Texture* _monedaTextura) :
	GameObject(_monedaTextura, _tile)
{
	if (tileActual != nullptr)
		tileActual->setMoneda(this);

	valor = 1;
	tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	tiempoPoderMoneda = 0;

	framesMovimiento = 4;
}

Moneda::~Moneda() {
	deleteGameObject();
}

void Moneda::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setMoneda(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
 	}
}

void Moneda::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setMoneda(nullptr);
}
