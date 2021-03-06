#pragma once
#include <string>

#include "Texture.h"
#include "TextureManager.h"
#include "Tile.h"

using namespace std;


enum TIPO_OBJETO {
	PARED,
	FANTASMA,
	PACMAN,
	FRUTA,
	MONEDA
};

class TileGraph; class GameObject
{
protected:

	TIPO_OBJETO tipoObjeto;

	Texture* textura;

	bool visible = true;
	bool enMovimiento;
	bool eliminar = false;


	int posicionX;
	int posicionY;

	int ancho;
	int alto;

	int frameX;
	int frameY;

	int alpha;

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
	GameObject(Tile* _tile);
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
	Texture* getTextura() { return textura; }
	string getTexturaID() { return textureID; }
	int getFrameX() { return frameX; }
	int getFrameY() { return frameY; }
	int getFramesMovimiento() { return framesMovimiento; }
	virtual SDL_Rect* getColisionador() { return colisionador; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setVisible(bool _visible) { visible = _visible; }
	void setEliminar(bool _eliminar) { eliminar = _eliminar; }
	void setEnMovimiento(bool _enMovimiento) { enMovimiento = _enMovimiento; }
	void setFrameX(int _frameX) { frameX = _frameX; }
	void setFrameY(int _frameY) { frameY = _frameY; }

	void setTextura(Texture* _textura) { textura = _textura; }


	
	bool revisarColision(const SDL_Rect* _otroColisionador);
	bool revisarColision(const SDL_Rect* _colisionador1, const SDL_Rect* _colisionador2);

	virtual void update() {};
	virtual void draw();
	virtual void render();
	virtual void updateFrames() {};

	virtual void handleEvent(SDL_Event* event) {};

	virtual void deleteGameObject() { eliminar = true; }
	virtual void free() {};
	void Delete() { deleteGameObject(); }
	void Free() { free(); }
};

