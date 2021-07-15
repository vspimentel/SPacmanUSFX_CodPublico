#pragma once
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>

#include <SDL.h>

#include "MapGenerator.h"
#include "TileGraph.h"
#include "TextureManager.h"
#include "FactoryPacmanClasico.h"
#include "FactoryPacmanGalactico.h"
#include "FactoryPacmanAsesino.h"
#include "FantasmasFactory.h"
#include "FrutaFactory.h"

using namespace std;

class GameManager
{
private:

    bool juego_en_ejecucion;

    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;
    MapGenerator* gGenerator;
    TextureManager* textureManager;
    Factory* tipoFabrica;

    GameManager();
    static GameManager* instancia;

public:

    static GameManager* crearInstancia();

    int onExecute();
    bool onInit();
    void facade(string modo);
    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();
};

    