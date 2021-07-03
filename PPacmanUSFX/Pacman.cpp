#include "Pacman.h"

Pacman::Pacman(Tile* _tile, string _texturaPacman, int _velocidad) :
	GameObject(_texturaPacman, _tile)
{
	texturaAnimacion = new TextureAnimation();
	//texturaAnimacion->setTexture(_texturaPacman);
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
		if (revisarColision(colisionador, tileActual->getMoneda()->getColisionador())) {
			if (tileActual->getMoneda()->getTipoPoderMoneda() == PODER_SUPERMONEDA) {
				contState = 0;
				state = 1;
				cout << id << endl;
				tileActual->getSuperMoneda()->deleteGameObject();
			}
			else {
				tileActual->getMoneda()->deleteGameObject();
			}
		}
	}
	if (tileActual != nullptr && tileActual->getFruta() != nullptr) {
		if (revisarColision(colisionador, tileActual->getFruta()->getColisionador())) {
			tileActual->getFruta()->deleteGameObject();
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
		switch (direccionActual)
		{
		case MOVE_UP:
			posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_DOWN:
			posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_LEFT:
			posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_RIGHT:
			posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
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

//void Pacman::render()
//{
//	if (textura != nullptr) {
//		SDL_Rect* cuadroAnimacion = new SDL_Rect();
//
//		switch (direccionActual) {
//		case MOVE_UP:
//			cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("arriba")[numeroFrame];
//			break;
//		case MOVE_DOWN:
//			cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("abajo")[numeroFrame];
//			break;
//		case MOVE_LEFT:
//			cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("izquierda")[numeroFrame];
//			break;
//		case MOVE_RIGHT:
//			cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("derecha")[numeroFrame];
//			break;
//		}
//		SDL_Rect* rect = new SDL_Rect{ posicionX, posicionY, ancho, alto };
//		texturaAnimacion->getTexture()->render(cuadroAnimacion, rect);
//	}
//}

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
	if (cuadroAnimacion->x != 0) {
		frameX = cuadroAnimacion->x / anchoClip;
	}
	else
	{
		frameX = cuadroAnimacion->x;
	}

	if (cuadroAnimacion->y != 0) {
		frameY = cuadroAnimacion->y / anchoClip;
	}
	else
	{
		frameY = cuadroAnimacion->y;
	}
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
