#pragma once

#include <SDL.h>

#include "TileGraph.h"
#include "GameObject.h"
#include "MoveDirection.h"
#include "TextureAnimation.h" 
#include "Moneda.h"
#include "Fruta.h"

using namespace std;

class Pacman : public GameObject
{
protected:

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	int velocidad;

	TextureAnimation* texturaAnimacion;

	int energia;
	int state;

public:

	Pacman(Tile* _tile, Texture* _texturaPacman, int _velocidad);
	~Pacman();

	int getVelocidad() { return velocidad; }
	int getEnergia() { return energia; }
	int getState() { return state; }

	void setVelocidad(int _velocidad) { velocidad = _velocidad; }
	void setTile(Tile* _tileNuevo);
	void setEnergia(int _energia) { energia = _energia; }
	void setState(int _state) { state = _state; }

	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);
	void restarEnergia();

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event* event) override;
	// Mover pacman
	void update() override;
	// Renderizar imagen pacman
	void render() override;
	//void update();
	void deleteGameObject() override;

};