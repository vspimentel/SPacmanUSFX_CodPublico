#pragma once
#include "GameObject.h"
class GameActor : public GameObject
{
protected:
	Tile* tileActual;
	Tile* tileSiguiente;

	bool enMovimiento;

	bool alive = true;
	bool dead = false;

	int numeroFrame;
	int contadorFrames;
	int framesMovimiento;

	SDL_Rect* colisionador;

public:

	static const int anchoPantalla = 800;
	static const int altoPantalla = 600;

	GameActor();
	GameActor(string _textureID, Tile* _tile);

	bool getEnMovimiento() { return enMovimiento; }
	bool getAlive() { return alive; }
	bool getDead() { return dead; }
	int getFramesMovimiento() { return framesMovimiento; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }
	virtual SDL_Rect* getColisionador() { return colisionador; }

	void setAlive(bool _alive) { alive = _alive; }
	void setEnMovimiento(bool _enMovimiento) { enMovimiento = _enMovimiento; }
	void setTextura(Texture* _textura) { textura = _textura; }
	void setTileSiguiente(Tile* _tileSiguiente) { tileSiguiente = _tileSiguiente; }
	virtual void setTile(Tile* _tileNuevo) {};

	virtual void update() {};
	virtual void draw() { GameObject::draw(); };
	virtual void updateFrames() {};

	bool revisarColision(const SDL_Rect* _otroColisionador);
	bool revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2);
};

