#pragma once
#include <SDL.h>
#include <iostream>
#include "GameObject.h"

using namespace std;

enum GameMonedaType {
    MONEDA_CLASICO,
    MONEDA_GALACTICO
};

enum PODER_MONEDA {
    PODER_MONEDA_NINGUNO,
    PODER_SUPERMONEDA
};

class Moneda : public GameObject
{
protected:

    int valor;

    GameMonedaType tipoMoneda;

    PODER_MONEDA tipoPoderMoneda;

    int tiempoPoderMoneda;

public:
    Moneda(Tile* _tile, string _monedaTextura);
    Moneda(Tile* _tile, string _monedaTextura, PODER_MONEDA _poder);
    ~Moneda();

    int getValor() { return valor; }
    PODER_MONEDA getTipoPoderMoneda() { return tipoPoderMoneda; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
    GameMonedaType returnGameMonedaType() { return tipoMoneda; }
   
    void setValor(int _valor) { valor = _valor; }
    void setTipoPoderMoneda(PODER_MONEDA _tipoPoderMoneda) { tipoPoderMoneda = _tipoPoderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }
    void setTile(Tile* _tileNuevo);

    void updateFrames();
    void deleteGameObject() override;
};

