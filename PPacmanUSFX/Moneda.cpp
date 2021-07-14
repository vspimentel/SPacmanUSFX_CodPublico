#include "Moneda.h"

Moneda::Moneda(Tile* _tile, Texture* _texture) :
	GameActor(_tile)
{
	textura = _texture;
	if (tileActual != nullptr)
		tileActual->setMoneda(this);
	valor = 1;
	tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	tiempoPoderMoneda = 0;

	framesMovimiento = 4;
	tipoObjeto = MONEDA;
}

Moneda::Moneda(Tile* _tile, Texture* _monedaTextura, PODER_MONEDA _poder):
	GameActor(_tile){
	textura = _monedaTextura;
	if (tileActual != nullptr)
		tileActual->setMoneda(this);
	valor = 1;
	tipoPoderMoneda = _poder;
	tiempoPoderMoneda = 0;
	tipoObjeto = MONEDA;
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
