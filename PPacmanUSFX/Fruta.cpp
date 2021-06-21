#include "Fruta.h"

Fruta::Fruta(Tile* _tile, Texture* _frutaTexture) :
	GameObject(_frutaTexture, _tile)
{
	tileActual = _tile;

	if (tileActual != nullptr) 
		tileActual->setFruta(this);

	tipoFruta = TIPO_FRUTA_FRUTILLA;
	
	visible = false;

}

Fruta::~Fruta() {
	deleteGameObject();
}

void Fruta::reconfigurar(Tile* _tileNuevo, TIPO_FRUTA _tipoFruta) {
	if (tileActual != nullptr) {
		tileActual->setFruta(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFruta(this); {
			posicionX = tileActual->getPosicionX() * Tile::anchoTile;
			posicionY = tileActual->getPosicionY() * Tile::altoTile;
			ancho = Tile::anchoTile;
			alto = Tile::altoTile;
		}
		colisionador = new SDL_Rect({ posicionX, posicionY, 0, 0 });
	}
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
			ancho = Tile::anchoTile;
			alto = Tile::altoTile;
		}
		colisionador = new SDL_Rect({ posicionX, posicionY, 0, 0 });
	}
}

void Fruta::update()
{
	if (cont >= timeFruit) {
		cont = 0;
		deleteGameObject();
	}
	else
		cont++;
}

void Fruta::deleteGameObject() {
	GameObject::deleteGameObject();
	tileActual->setFruta(nullptr);
}

void Fruta::render()
{
	SDL_Rect rect = { posicionX, posicionY, ancho, alto };
	SDL_Rect clip = { 0 + frameX * anchoClip, 0 + frameY * altoClip, anchoClip, altoClip };
	textura->render(posicionX, posicionY, &clip, &rect);
};
