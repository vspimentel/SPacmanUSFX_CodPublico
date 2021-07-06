#include "GameActor.h"

GameActor::GameActor() {
	alpha = 255;
}

GameActor::GameActor(string _textureID, Tile* _tile) : GameObject(_textureID, _tile) {
	textureID = _textureID;
	alpha = 255;
	textura = nullptr;
	tileActual = _tile;
	if (tileActual != nullptr) {
		tileSiguiente = tileActual;
		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	ancho = Tile::anchoTile;
	alto = Tile::altoTile;
	visible = true;
	eliminar = false;
	enMovimiento = false;
	numeroFrame = 0;
	contadorFrames = 0;
	colisionador = new SDL_Rect({ posicionX, posicionY, 0, 0 });
}


bool GameActor::revisarColision(const SDL_Rect* _otroColisionador)
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

bool GameActor::revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2)
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