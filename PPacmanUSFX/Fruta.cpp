#include "Fruta.h"

Fruta::Fruta(Tile* _tile, string _frutaTexture) :
	GameActor(_frutaTexture, _tile)
{
	tipoObjeto = FRUTA;

	if (tileActual != nullptr)
		tileActual->setFruta(this);

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;

	velocidad = 2;
	framesMovimiento = 1;
}

Fruta::~Fruta() {
	deleteGameObject();
}

void Fruta::reconfigurar(Tile* _tileNuevo, TIPO_FRUTA _tipoFruta) {
	
	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);
		tileSiguiente = tileActual;

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

	}
	tileDestino = tileGraph->getTileEn(9 + rand() % (11 - 9), 14);
	colisionador = new SDL_Rect({ posicionX, posicionY, 0, 0 });
	velocidad = 2;
	switch(_tipoFruta)
	{
	case TIPO_FRUTA_GUINDA:
		frameY = 0; break;
	case TIPO_FRUTA_PLATANO:
		frameY = 1; break;
	case TIPO_FRUTA_NARANJA:
		frameY = 2; break;
	case TIPO_FRUTA_FRUTILLA:
		frameY = 3; break;
	}
}

void Fruta::setTile(Tile* _tileNuevo) {
	
	if (tileActual != nullptr) {
		tileActual->setFruta(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);{
			posicionX = tileActual->getPosicionX() * Tile::anchoTile;
			posicionY = tileActual->getPosicionY() * Tile::altoTile;
		}
	}
}

void Fruta::update()
{

	if (tileActual == tileSiguiente) {
		camino = proxy.getPath(tileActual, tileDestino);
	}
	if (camino.size() > 1) {
		tileSiguiente = camino[1];

		if (posicionX < tileSiguiente->getPosicionX() * Tile::anchoTile)
			direccionActual = MOVE_RIGHT;

		else if (posicionX > tileSiguiente->getPosicionX() * Tile::anchoTile)
			direccionActual = MOVE_LEFT;

		else if (posicionY > tileSiguiente->getPosicionY() * Tile::altoTile)
			direccionActual = MOVE_UP;

		else if (posicionY < tileSiguiente->getPosicionY() * Tile::altoTile)
			direccionActual = MOVE_DOWN;
	}

	switch (direccionActual)
	{
	case MOVE_UP:
		posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);  break;
	case MOVE_DOWN:
		posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionY() * Tile::altoTile); break;
	case MOVE_LEFT:
		posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile); break;
	case MOVE_RIGHT:
		posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile); break;
	}

	colisionador->x = posicionX;
	colisionador->y = posicionY;

	if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
		setTile(tileSiguiente);

	if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
		setTile(tileSiguiente);

	if (tileActual == tileDestino)
		deleteGameObject();
}

void Fruta::deleteGameObject() {
	GameObject::deleteGameObject();
	tileActual->setFruta(nullptr);
}
