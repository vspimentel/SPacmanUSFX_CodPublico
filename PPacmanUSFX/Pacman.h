#pragma once

#include <SDL.h>
#include <string>

#include "TileGraph.h"
#include "GameObject.h"
#include "MoveDirection.h"
#include "TextureAnimation.h" 
#include "Moneda.h"
#include "Fruta.h"
#include "DecoratorAura.h"

using namespace std;

class Pacman : public GameObject
{
protected:

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	int velocidad;

	TextureAnimation* texturaAnimacion;

	int state;

	const int timeState = 500;
	int contState = 500;

public:

	Pacman(Tile* _tile, string _texturaPacman, int _velocidad);
	~Pacman();

	int getVelocidad() { return velocidad; }
	int getState() { return state; }

	void setVelocidad(int _velocidad) { velocidad = _velocidad; }
	void setTile(Tile* _tileNuevo);
	void setState(int _state) { state = _state; }

	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event* event);
	// Mover pacman
	void update();

	//void render() override;
	void draw() override;
	void updateFrames() override; 

	void changeState();

	void deleteGameObject() override;

};