#pragma once
#include <SDL.h>
#include "MoveDirection.h"
#include "PathFinder.h"
#include "GameActor.h"

using namespace std;

enum TIPO_FRUTA {
	TIPO_FRUTA_GUINDA,
	TIPO_FRUTA_PLATANO,
	TIPO_FRUTA_NARANJA,
	TIPO_FRUTA_FRUTILLA,
	MAX
};

enum GameFrutaType {
	FRUTA_CLASICO,
	FRUTA_GALACTICO,
	FRUTA_ASESINO
};

class Fruta : public GameActor {
protected:

	TIPO_FRUTA tipoFruta;
	GameFrutaType GameFrutaTipo;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	Tile* tileDestino;

	vector<Tile*> camino;

	const int timeFruit = 400;
	int cont = 0;

	int velocidad;

	Tile* tileActual;

public:

	Fruta(Tile* _tile, string _frutaTexture);
	~Fruta();
	
	void reconfigurar(Tile* _tileNuevo, TIPO_FRUTA tipoFruta);

	virtual Fruta* clone() = 0;

	//Metodos accesores
	TIPO_FRUTA getTipoFruta() { return tipoFruta; }
	GameFrutaType getTipo() { return GameFrutaTipo; }

	void setTile(Tile* _tileNuevo);

	void update();

	static bool avoidInPathFinder(Tile* _tile);

	void deleteGameObject() override;
};


