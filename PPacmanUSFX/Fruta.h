#pragma once
#include <SDL.h>

#include "GameObject.h"

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

class Fruta : public GameObject {
protected:

	TIPO_FRUTA tipoFruta;
	GameFrutaType GameFrutaTipo;

	const int timeFruit = 400;
	int cont = 0;

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

	void deleteGameObject() override;
};


