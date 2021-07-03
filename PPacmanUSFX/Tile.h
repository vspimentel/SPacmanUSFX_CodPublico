#pragma once
#include <SDL.h>

class Pacman;
class PacmanGalactico;
class Fantasma;
class Fruta;
class Moneda;
class Pared;
class Wall;
class DecoratorAura;

class Tile
{
private:

	Pacman* pacman;
	PacmanGalactico* pacmanGalactico;
	Fantasma* fantasma;
	Fruta* fruta;
	Moneda* moneda;
	Pared* pared;
	Wall* wall;
	DecoratorAura* supermoneda;

	int posicionX;
	int posicionY;

public:
	static const int anchoTile = 25;
	static const int altoTile = 25;

public:

	Tile(int _x, int _y);

	Pacman* getPacman() { return pacman; }

	Fantasma* getFantasma() { return fantasma; }
	Fruta* getFruta() { return fruta; }
	Moneda* getMoneda() { return moneda; }
	Pared* getPared() { return pared; }
	Wall* GetWall() { return ((Wall*)pared); }
	DecoratorAura* getSuperMoneda() { return supermoneda; }

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }

	SDL_Point GetPosition() {
		return SDL_Point() = { posicionX, posicionY };
	}

	void setPacman(Pacman* _pacman) { pacman = _pacman; }
	void setFantasma(Fantasma* _fantasma) { fantasma = _fantasma; }
	void setFruta(Fruta* _fruta){ fruta = _fruta; }
	void setMoneda(Moneda* _moneda) { moneda = _moneda; }
	void setSuperMoneda(DecoratorAura* _supermoneda) { supermoneda = _supermoneda; }
	void setPared(Pared* _pared) { pared = _pared; }
	void SetWall(Wall* _wall) { pared = ((Pared*)_wall); }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }

};

