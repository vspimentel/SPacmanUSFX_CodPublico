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

	srand(time(NULL));

	TileGraph tileGraphGM(20, 15);
	GameObject::tileGraph = &tileGraphGM;
	facade("Clasico");
	gGenerator = MapGenerator::createInstance(&tileGraphGM, tipoFabrica);
	gGenerator->load("Resources/mapa.txt");

    SDL_Event Event;

    while (juego_en_ejecucion) {
		gGenerator->newObjects();

		for (int i = 0; i < gGenerator->actors.size(); i++) {
			if (((GameObject*)gGenerator->actors[i])->getEliminar()) {
				gGenerator->actors.erase(remove(gGenerator->actors.begin(), gGenerator->actors.end(), gGenerator->actors[i]), gGenerator->actors.end());
			}
		}

        while (SDL_PollEvent(&Event)) {
            onEvent(&Event);
			for (int i = 0; i < gGenerator->actors.size(); i++) {
				gGenerator->actors[i]->handleEvent(&Event);
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
}
void GameManager::facade(string modo)
{
	TextureManager::createInstance()->setRenderer(gRenderer);
	TextureManager::createInstance()->initializeSDL();
	if (modo == "Clasico"){
		tipoFabrica = new FactoryPacmanClasico;
		FantasmasFactory::initializeClasico();
		FrutaFactory::initializeClasico();
	}
	else if (modo == "Galactico") {
		tipoFabrica = new FactoryPacmanGalactico;
		FantasmasFactory::initializeGalactico();
		FrutaFactory::initializeGalactico();
	}
	else if (modo == "Asesino") {
		tipoFabrica = new FactoryPacmanAsesino;
		FantasmasFactory::initializaeAsesino();
		FrutaFactory::initializeAsesino();
	}
};

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};

void GameManager::onLoop() {};

void GameManager::onRender() {
	for (int i = 0; i < gGenerator->actors.size(); i++) {
		gGenerator->actors[i]->updateFrames();
		gGenerator->actors[i]->update();
		gGenerator->actors[i]->draw();
		gGenerator->actors[i]->render();
	}
};

void GameManager::onCleanup() {
	SDL_Quit();
};