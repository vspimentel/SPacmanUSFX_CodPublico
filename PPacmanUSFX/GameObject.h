#pragma once
#include <string>

#include "Texture.h"
#include "TextureManager.h"
#include "Tile.h"

using namespace std;

enum TIPO_OBJETO {
	FANTASMA,
	PARED,
	PACMAN,
	FRUTA,
	MONEDA
};

class TileGraph; class GameObject
{
protected:

	TIPO_OBJETO tipoObjeto;

	Texture* textura;

	Tile* tileActual;
	Tile* tileSiguiente;

	bool visible = true;
	bool enMovimiento;
	bool eliminar = false;
	bool alive = true;
	bool dead = false;

	int posicionX;
	int posicionY;

	int ancho;
	int alto;

	int frameX;
	int frameY;

	int anchoClip = Tile::anchoTile;
	int altoClip = Tile::altoTile;

	string textureID;

	int numeroFrame;
	int contadorFrames;
	int framesMovimiento;

	SDL_Rect* colisionador;

public:

	static TileGraph* tileGraph;

	static const int anchoPantalla = 800;
	static const int altoPantalla = 600;

public:
	//Constructores y destructores
	GameObject();
	GameObject(Texture* _textura, Tile* _tile);
	GameObject(string _textureID, Tile* _tile);
	~GameObject();

	//Metodos accesores
	TIPO_OBJETO getTipoObjeto() { return tipoObjeto; }
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	bool getVisible() { return visible; }
	bool getEliminar() { return eliminar; }
	bool getEnMovimiento() { return enMovimiento; }
	bool getAlive() { return alive; }
	bool getDead() { return dead; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }
	Texture* getTextura() { return textura; }
	string getTexturaID() { return textureID; }
	virtual SDL_Rect* getColisionador() { return colisionador; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setVisible(bool _visible) { visible = _visible; }
	void setEliminar(bool _eliminar) { eliminar = _eliminar; }
	void setAlive(bool _alive) { alive = _alive; }
	void setEnMovimiento(bool _enMovimiento) { enMovimiento = _enMovimiento; }
	virtual void setTile(Tile* _tileNuevo) {};
	void setTextura(Texture* _textura) { textura = _textura; }
	void setTileSiguiente(Tile* _tileSiguiente) { tileSiguiente = _tileSiguiente; }

	
	bool revisarColision(const SDL_Rect* _otroColisionador);
	bool revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2);

	virtual void render();
	virtual void update() {};
	virtual void draw();
	virtual void updateFrames() {};

	virtual void handleEvent(SDL_Event* event) {};

	virtual void deleteGameObject() { eliminar = true; }
	virtual void free() {};
	void Delete() { deleteGameObject(); }
	void Free() { free(); }
};

