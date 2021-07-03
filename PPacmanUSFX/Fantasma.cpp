#include "Fantasma.h"

Fantasma::Fantasma(Tile* _tile, string _fantasmaTexture, int _velocidad) :
	GameObject(_fantasmaTexture, _tile)
{
	tipoObjeto = FANTASMA;

	if (tileActual != nullptr)
		tileActual->setFantasma(this);

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;

	velocidad = _velocidad;
	framesMovimiento = 4;
}


Fantasma::~Fantasma() {
	deleteGameObject();
}

void Fantasma::reconfigurar(Tile* _tile, int _velocidad) 
{
	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);
		tileSiguiente = tileActual;

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

	}
	colisionador = new SDL_Rect({ posicionX, posicionY, 0, 0 });
	velocidad = _velocidad;
}

void Fantasma::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setFantasma(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
}

void Fantasma::update()
{
	Pacman* pacman = tileGraph->getPacman();

	if (pacman != nullptr) {

		if (tileActual == tileSiguiente) {
			PathFinder astar(tileGraph);
			astar.SetAvoidFunction(Fantasma::avoidInPathFinder);
			camino = astar.CalculateRoute(tileActual, pacman->getTile());
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

		for (auto tile : tileGraph->get4Vecinos(tileActual)) {
			if (tile->getPacman() != nullptr && revisarColision(tile->getPacman()->getColisionador())) {
				if (tile->getPacman()->getState() == 0)
					tile->getPacman()->deleteGameObject();
				else if (tile->getPacman()->getState() == 1) {
					eliminar = true;
				}
			}
		}
		switch (direccionActual)
		{
		case MOVE_UP:
			posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			frameY = 0; break;
		case MOVE_DOWN:
			posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			frameY = 0; break;
		case MOVE_LEFT:
			posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			frameY = 1; break;
		case MOVE_RIGHT:
			posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			frameY = 1; break;
		}

		colisionador->x = posicionX;
		colisionador->y = posicionY;

		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);
	}
}

void Fantasma::updateFrames() {
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

bool Fantasma::avoidInPathFinder(Tile* _tile)
{
	if (_tile->getPared() != nullptr)
		return true;
	return false;
}

void Fantasma::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setFantasma(nullptr);
}

