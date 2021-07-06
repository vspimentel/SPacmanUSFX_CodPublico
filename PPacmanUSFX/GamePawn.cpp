#include "GamePawn.h"

GamePawn::GamePawn(string _textureID, Tile* _tile) : GameActor(_textureID, _tile)
{
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
