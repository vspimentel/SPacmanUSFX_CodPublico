#pragma once

#include <SDL.h>
#include <string>

#include "TileGraph.h"
#include "GamePawn.h"
#include "MoveDirection.h"
#include "TextureAnimation.h" 
#include "Moneda.h"
#include "Fruta.h"
#include "DecoratorAura.h"
#include "MovePacman.h"

using namespace std;

class Pacman : public GamePawn
{
protected:

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	MovePacman* estrategiaMov;

	TextureAnimation* texturaAnimacion;

	int state;

	const int timeState = 500;
	int contState = 500;

public:

	Pacman(Tile* _tile, string _texturaPacman, int _velocidad/*, UpdatePacman* strategy*/);
	~Pacman();

	int getVelocidad() { return velocidad; }
	int getState() { return state; }

	void setVelocidad(int _velocidad) { velocidad = _velocidad; }
	void setTile(Tile* _tileNuevo);
	void setState(int _state) { state = _state; }
	void setStrategy(MovePacman* _strategy) { estrategiaMov = _strategy; }

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