#pragma once
#include <iostream>
#include <string>
#include "Texture.h"
#include "Tile.h"

using namespace std;

class TileGraph;
class GameObject
{
protected:
	bool eliminar;
protected:

	Texture* textura;

	Tile* tileActual;

	bool visible;
	bool enMovimiento;

	int posicionX;
	int posicionY;

	int ancho;
	int alto;

	int numeroFrame;
	int contadorFrames;
	int framesMovimiento;

	SDL_Rect* colisionador;
public:
	static TileGraph* tileGraph;

public:
	//Constructores y destructores
	GameObject();
	GameObject(Texture* _textura, int _posicionX, int _posicionY);
	~GameObject() {};

	//Metodos accesores
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	bool getVisible() { return visible; }
	bool getEliminar() { return eliminar; }
	bool getEnMovimiento() { return enMovimiento; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setVisible(bool _visible) { visible = _visible; }
	void setEliminar(bool _eliminar) { eliminar = _eliminar; }
	void setEnMovimiento(bool _enMovimiento) { enMovimiento = _enMovimiento; }
	virtual void setTile(Tile* _tileNuevo) {};


	// Metodos varios
	void setParametrosAnimacion(int _framesMovimiento) { framesMovimiento = _framesMovimiento; }
	virtual SDL_Rect* getColisionador() { return colisionador; }
	bool revisarColision(const SDL_Rect* _otroColisionador);
	bool revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2);


	// Renderizar imagen
	virtual void render();
	virtual void update();
	virtual void handleEvent(SDL_Event* event) {};
	virtual void deleteGameObject() { eliminar = true; }
	virtual void free(){};
	void Delete() { deleteGameObject(); }
	void Free() { free(); }
};

