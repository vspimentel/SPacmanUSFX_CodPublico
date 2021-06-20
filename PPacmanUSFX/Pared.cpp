#include "Pared.h"

Pared::Pared(Tile* _tile, Texture* _paredTextura):
GameObject(_paredTextura, _tile){

	setTexture(tipoTexturaPared);

	if (tileActual != nullptr) 
		tileActual->setPared(this);

	altoClip = 140;
	anchoClip = 140;
};

Pared::~Pared() {
	deleteGameObject();
}

void Pared::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr)
		tileActual->setPared(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPared(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
};

void Pared::render()
{
	if (visible) {
		SDL_Rect rect = { posicionX, posicionY, ancho, alto };
		SDL_Rect clip = { 0 + frameX * anchoClip, 0 + frameY * altoClip, anchoClip, altoClip };
		textura->render(posicionX, posicionY, &clip, &rect);
	}
};

void Pared::setTexture(int tipoTextura)
{
	if (tipoTextura % 4 == 0)
		frameY = trunc(tipoTextura / 4) - 1;
	else
		frameY = trunc(tipoTextura / 4);
	frameX = (tipoTextura - frameY * 4) - 1;;
}


void Pared::deleteGameObject() {
	GameObject::deleteGameObject();
	tileActual->setPared(nullptr);
}


