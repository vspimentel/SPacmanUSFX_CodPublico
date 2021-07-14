#include "Pacman.h"

Pacman::Pacman(Tile* _tile, string _texturaPacman, int _velocidad) :GamePawn(_texturaPacman, _tile)
{

	mediator = new MediatorCollisions;

	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));

	if (tileActual != nullptr)
		tileActual->setPacman(this);

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;

	velocidad = _velocidad;
	enMovimiento = true;
	framesMovimiento = 2;
	tipoObjeto = PACMAN;
}

Pacman::~Pacman() {
	deleteGameObject();
}

void Pacman::setTile(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setPacman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
}

void Pacman::handleEvent(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN && event->key.repeat == 0) {
		switch (event->key.keysym.sym)
		{
			// Move up
		case SDLK_UP:
			direccionSiguiente = MOVE_UP; break;

			// Move down
		case SDLK_DOWN:
			direccionSiguiente = MOVE_DOWN; break;

			// Move left
		case SDLK_LEFT:
			direccionSiguiente = MOVE_LEFT; break;

			// Move right
		case SDLK_RIGHT:
			direccionSiguiente = MOVE_RIGHT; break;
		}
	}
}

bool Pacman::tratarDeMover(MoveDirection _direccionNueva)
{
	Tile* tileDestino = nullptr;

	switch (_direccionNueva)
	{
	case MOVE_UP:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - 1);
		break;
	case MOVE_DOWN:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + 1);
		break;
	case MOVE_LEFT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - 1, tileActual->getPosicionY());
		break;
	case MOVE_RIGHT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() + 1, tileActual->getPosicionY());
		break;
	}

	// Si el tile destino es nullptr, no se puede avanzar ahi
	if (tileDestino == nullptr) {
		switch (_direccionNueva)
		{
		case MOVE_UP:
			tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + tileGraph->getAltoTile() - 1);
			break;
		case MOVE_DOWN:
			tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - (tileGraph->getAltoTile() - 1));
			break;
		case MOVE_LEFT:
			tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() + tileGraph->getAnchoTile() - 1, tileActual->getPosicionY());
			break;
		case MOVE_RIGHT:
			tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - (tileGraph->getAnchoTile() - 1), tileActual->getPosicionY());
			break;
		}
	}

	// Si el tile destino es una pared, no se puede avanzar ahi
	if (tileDestino->getPared() != nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	setTileSiguiente(tileDestino);

	return true;
}

void Pacman::update()
{
	colisionador = new SDL_Rect({ posicionX, posicionY, ancho, alto });
	if (tileActual != nullptr && tileActual->getMoneda() != nullptr) {
		if (mediator->getBool(this, tileActual->getMoneda(), "colision")) {
			if (mediator->getBool(this, tileActual->getMoneda(), "isSupermoneda")) {
				contState = 0;
				state = 1;
				mediator->notify(this, tileActual->getSupermoneda(), "setDecorator");
			}
			mediator->notify(this, tileActual->getMoneda(), "eliminar");
		}
	}
	if (tileActual != nullptr && tileActual->getFruta() != nullptr) {
		if (mediator->getBool(this, tileActual->getFruta(), "colision")) {
			mediator->notify(this, tileActual->getFruta(), "eliminar");
		}
	}

	changeState();

	if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
		if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
			direccionActual = direccionSiguiente;
		else
			tratarDeMover(direccionActual);
	}
	else {

		if (estrategiaMov != nullptr) {
			estrategiaMov->move(this, direccionActual);
		}

		colisionador->x = posicionX;
		colisionador->y = posicionY;

		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);
	}
}

void Pacman::draw()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();

	switch (direccionActual) {
	case MOVE_UP:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("arriba")[numeroFrame];
		break;
	case MOVE_DOWN:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("abajo")[numeroFrame];
		break;
	case MOVE_LEFT:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("izquierda")[numeroFrame];
		break;
	case MOVE_RIGHT:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("derecha")[numeroFrame];
		break;
	}
	frameX = cuadroAnimacion->x / anchoClip;
	frameY = cuadroAnimacion->y / anchoClip;
	TextureManager::createInstance()->drawFrame(textureID, (Uint32)posicionX, (Uint32)posicionY,
		ancho, alto, frameY, frameX, altoClip, anchoClip, 0, 255);
}

void Pacman::updateFrames() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}

void Pacman::deleteGameObject()
{
	GameObject::deleteGameObject();
	tileActual->setPacman(nullptr);
}

void Pacman::changeState() {

	if (contState <= timeState) {
		contState++;
	}
	else if (state == 1) {
		state = 0;
		contState = 0;
	}
}
