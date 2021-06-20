#pragma once
#include <SDL.h>
#include "GameObject.h"

using namespace std;

enum GameMonedaType {
    MONEDA_CLASICO,
    MONEDA_GALACTICO
};

enum PODER_MONEDA {
    PODER_MONEDA_NINGUNO,
    PODER_MONEDA_CRECIMIENTO,
    PODER_MONEDA_COMER,
    PODER_MONEDA_VELOCIDAD,
    PODER_MONEDA_SALTO
};

class Moneda : public GameObject
{
protected:

    int valor;

    PODER_MONEDA tipoPoderMoneda;

    GameMonedaType tipoMoneda;

    int tiempoPoderMoneda;

public:
    Moneda(Tile* _tile, Texture* _monedaTextura);
    ~Moneda();

    void reconfigurar(Tile* _tile);

    int getValor() { return valor; }
    PODER_MONEDA getTipoPoderMoneda() { return tipoPoderMoneda; }
    int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
    GameMonedaType returnGameMonedaType() { return tipoMoneda; }
   
    void setValor(int _valor) { valor = _valor; }
    void setTipoPoderMoneda(PODER_MONEDA _tipoPoderMoneda) { tipoPoderMoneda = _tipoPoderMoneda; }
    void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }
    void setTile(Tile* _tileNuevo);

    void deleteGameObject() override;
};

