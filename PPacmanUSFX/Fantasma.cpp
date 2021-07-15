#include "Fantasma.h"

Fantasma::Fantasma(Tile* _tile, string _fantasmaTexture, int _velocidad) :
	GameActor(_fantasmaTexture, _tile)
{
	tipoObjeto = FANTASMA;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);
		start = tileActual;
	}

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
		start = tileActual;

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
		tileSiguiente = tileActual;
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
}

void Fantasma::update()
{
	if (dead) {
		contDead++;
		if (contDead >= deadTime) {
			dead = false;
			contDead = 0;
		}
	}

	if (alive) {
		Pacman* pacman = tileGraph->getPacman();

		if (pacman != nullptr) {

			if (tileActual == tileSiguiente) {
				camino = proxy.getPath(tileActual, pacman->getTile());
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
						break;
					}
				}
			}
			if (alive) {
				switch (direccionActual)
				{
				case MOVE_UP:
					posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
					if (pacman->getState() != 1)
						frameY = 1;
					else
						frameY = 2;
					break;
				case MOVE_DOWN:
					posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
					if (pacman->getState() != 1)
						frameY = 1;
					else
						frameY = 2;
					break;
				case MOVE_LEFT:
					posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
					if (pacman->getState() != 1)
						frameY = 0;
					else
						frameY = 2;
					break;
				case MOVE_RIGHT:
					posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
					if (pacman->getState() != 1)
						frameY = 0;
					else
						frameY = 2;
					break;
				}

				colisionador->x = posicionX;
				colisionador->y = posicionY;

				if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
					setTile(tileSiguiente);

				if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
					setTile(tileSiguiente);

			}
		}
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

void Fantasma::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setFantasma(nullptr);
}

