#include "Moneda.h"

Moneda::Moneda(Tile* _tile, string _monedaTextura) :
	GameObject(_monedaTextura, _tile)
{
	if (tileActual != nullptr)
		tileActual->setMoneda(this);
	valor = 1;
	tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	tiempoPoderMoneda = 0;

	framesMovimiento = 4;
	tipoObjeto = MONEDA;
}

Moneda::Moneda(Tile* _tile, string _monedaTextura, PODER_MONEDA _poder):
	GameObject(_monedaTextura, _tile){
	if (tileActual != nullptr)
		tileActual->setMoneda(this);
	valor = 1;
	tipoPoderMoneda = _poder;
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

void Moneda::updateFrames() {
	contadorFrames++;
	if (contadorFrames >= 10)
	{
		frameX++;
		if (frameX == framesMovimiento)
		{
			frameX -= framesMovimiento;
		}
		contadorFrames = 0;
	}
}

void Moneda::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setMoneda(nullptr);
}
