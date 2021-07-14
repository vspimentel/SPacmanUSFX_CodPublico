#include "GameObject.h"

TileGraph* GameObject::tileGraph = nullptr;

GameObject::GameObject() {
	alpha = 255;
	textureID = "";
	ancho = Tile::anchoTile;
	alto = Tile::altoTile;
	visible = true;
	eliminar = false;
	enMovimiento = false;
	numeroFrame = 0;
	contadorFrames = 0;
	colisionador = new SDL_Rect({ posicionX, posicionY, 0, 0 });
}

GameObject::GameObject(Tile* _tile) {
	alpha = 255;
	visible = true;
	eliminar = false;
	enMovimiento = false;
}

GameObject::GameObject(string _textureID, Tile* _tile) {
	textureID = _textureID;
	alpha = 255;
	ancho = Tile::anchoTile;
	alto = Tile::altoTile;
	visible = true;
	eliminar = false;
	enMovimiento = false;
	numeroFrame = 0;
	contadorFrames = 0;
	colisionador = new SDL_Rect({ posicionX, posicionY, 0, 0 });
}

GameObject::~GameObject() {
	deleteGameObject();
}


void GameObject::render()
{
	if (textura != nullptr) {
		if (visible) {
			SDL_Rect rect = { posicionX, posicionY, ancho, alto };
			SDL_Rect clip = { 0 + frameX * anchoClip, 0 + frameY * altoClip, anchoClip, altoClip };
			textura->render(&clip, &rect);
		}
	}
}

void GameObject::draw() {
	if (visible) {
		TextureManager::createInstance()->drawFrame(textureID, posicionX, posicionY,
			ancho, alto, frameY, frameX, altoClip, anchoClip, 0, alpha);
	}
}

bool GameObject::revisarColision(const SDL_Rect* _otroColisionador)
{
	if (_otroColisionador->x > colisionador->x + colisionador->w) {
		return false;
	}

	if (_otroColisionador->y > colisionador->y + colisionador->h) {
		return false;
	}

	if (_otroColisionador->x + _otroColisionador->w < colisionador->x) {
		return false;
	}

	if (_otroColisionador->y + _otroColisionador->h < colisionador->y) {
		return false;
	}

	return true;
}

bool GameObject::revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2)
{
	if (_colisionador1->x > _colisionador2->x + _colisionador2->w) {
		return false;
	}

	if (_colisionador1->y > _colisionador2->y + _colisionador2->h) {
		return false;
	}

	if (_colisionador1->x + _colisionador1->w < _colisionador2->x) {
		return false;
	}

	if (_colisionador1->y + _colisionador1->h < _colisionador2->y) {
		return false;
	}

	return true;
}