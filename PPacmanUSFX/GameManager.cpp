#include "GameManager.h"

using namespace std;

GameManager* GameManager::instancia = nullptr;

GameManager* GameManager::crearInstancia() {
	if (instancia == nullptr) 
		instancia = new GameManager();
	return instancia;
}

GameManager::GameManager() {

	gWindow = nullptr;
	gRenderer = nullptr;

	juego_en_ejecucion = true;
}

int GameManager::onExecute() {
    if (onInit() == false) {
        return -1;
    }
	srand(time(nullptr));
	TileGraph tileGraphGM(20, 15);
	textureManager = TextureManager::createInstance();
	textureManager->setRenderer(gRenderer);
	textureManager->initializeSDL();
	GameObject::tileGraph = &tileGraphGM;
	tipoFabrica = new FactoryPacmanClasico;
	//tipoFabrica = new FactoryPacmanGalactico;
	//tipoFabrica = new FactoryPacmanAsesino;
	generadorNivelJuego = MapGenerator::createInstance(&tileGraphGM, textureManager, tipoFabrica);
	generadorNivelJuego->load("Resources/mapa.txt");
	generadorNivelJuego->populate(actoresJuego);
    SDL_Event Event;

    while (juego_en_ejecucion) {

		for (int i = 0; i < actoresJuego.size(); i++) {
			if (actoresJuego[i]->getEliminar()) {
				actoresJuego.erase(remove(actoresJuego.begin(), actoresJuego.end(), actoresJuego[i]), actoresJuego.end());
			}
		}

		generadorNivelJuego->newObjects();
		generadorNivelJuego->populate(actoresJuego);

        while (SDL_PollEvent(&Event)) {
            onEvent(&Event);
			for (int i = 0; i < actoresJuego.size(); i++) {
				actoresJuego[i]->handleEvent(&Event);
			}
        }

		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);

        onLoop();
        onRender();
		SDL_RenderPresent(gRenderer);
    }
    onCleanup();
    return 0;
}

bool GameManager::onInit() { 
    //Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Pacman USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GameObject::anchoPantalla, GameObject::altoPantalla, SDL_WINDOW_SHOWN);
		if (gWindow == nullptr)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == nullptr)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				if (TTF_Init() == -1) {
					cout << "Error inicializacion SDL_ttf" << TTF_GetError() << endl;
					success = false;
				}
			}
			Texture::renderer = gRenderer;
		}
	}
	return success;
};

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};

void GameManager::onLoop() {};

void GameManager::onRender() {
	for (int i = 0; i < actoresJuego.size(); i++) {
		actoresJuego[i]->updateFrames();
		actoresJuego[i]->update();
		actoresJuego[i]->draw();
		//actoresJuego[i]->render();
	}
};

void GameManager::onCleanup() {
	SDL_Quit();
};