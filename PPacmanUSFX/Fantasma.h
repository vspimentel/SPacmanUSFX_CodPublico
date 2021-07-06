#pragma once

#include <SDL.h>

#include "MoveDirection.h"
#include "TextureAnimation.h"
#include "GameActor.h"
#include "PathFinder.h"
#include "Pacman.h"

using namespace std;

enum GameFantasmaType {
	FANTASMA_CLASICO,
	FANTASMA_GALACTICO,
	FANTASMA_ASESINO
};

class Fantasma : public GameActor {

protected:

	GameFantasmaType tipoFantasma;

	int velocidad;

	vector<Tile*> camino;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	TextureAnimation* texturaAnimacion;

public:
	//Constructores y destructores
	Fantasma(Tile* _tile, string _fantasmaTexture, int _velocidad);
	~Fantasma();

	void reconfigurar(Tile* _tile, int _velocidad);

	//Metodos accesores
	int getVelocidad() { return velocidad; }

	void setVelocidad(int _velocidad) { velocidad = _velocidad; }
	void setTile(Tile* _tileNuevo);

	virtual Fantasma* clone() = 0;
	GameFantasmaType returnGameFantasmaType() { return tipoFantasma; }

	virtual void update();
	void updateFrames();
	static bool avoidInPathFinder(Tile* _tile);

	void deleteGameObject() override;
};