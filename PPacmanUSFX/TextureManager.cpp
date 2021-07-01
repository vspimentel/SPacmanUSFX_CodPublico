#include "TextureManager.h"

TextureManager* TextureManager::instance = nullptr;

TextureManager* TextureManager::createInstance() {
	if (instance == nullptr)
		instance = new TextureManager();
	return instance;
}

TextureManager::TextureManager()
{
	pacmanClasicoTexture = new Texture();
	pacmanClasicoTexture->loadFromImage(pathPacmanClasico);
	addTexture("pacman_clasico", pacmanClasicoTexture);
	
	fantasmaClasico1Texture = new Texture();
	fantasmaClasico1Texture->loadFromImage(pathFantasmaClasico1);
	addTexture("fantasma_clasico1", fantasmaClasico1Texture);
	fantasmaClasico2Texture = new Texture();
	fantasmaClasico2Texture->loadFromImage(pathFantasmaClasico2);
	addTexture("fantasma_clasico2", fantasmaClasico2Texture);
	fantasmaClasico3Texture = new Texture();
	fantasmaClasico3Texture->loadFromImage(pathFantasmaClasico3);
	addTexture("fantasma_clasico3", fantasmaClasico3Texture);
	fantasmaClasico4Texture = new Texture();
	fantasmaClasico4Texture->loadFromImage(pathFantasmaClasico4);
	addTexture("fantasma_clasico4", fantasmaClasico4Texture);

	frutaClasicoTexture = new Texture();
	frutaClasicoTexture->loadFromImage(pathFrutaClasico);
	addTexture("fruta_clasico", frutaClasicoTexture);

	monedaClasicoTexture = new Texture();
	monedaClasicoTexture->loadFromImage(pathMonedaClasico);
	addTexture("moneda_clasico", monedaClasicoTexture);

	superMonedaClasicoTexture = new Texture();
	superMonedaClasicoTexture->loadFromImage(pathSuperMonedaClasico);
	addTexture("supermoneda_clasico", superMonedaClasicoTexture);

	paredClasicoTexture = new Texture();
	paredClasicoTexture->loadFromImage(pathParedClasico);
	addTexture("pared_clasico", paredClasicoTexture);

	paredClasicoAdapterTexture = new Texture();
	paredClasicoAdapterTexture->loadFromImage(pathParedClasicoAdapter);
	addTexture("pared_clasico_adapter", paredClasicoAdapterTexture);

	pacmanGalacticoTexture = new Texture();
	pacmanGalacticoTexture->loadFromImage(pathPacmanGalactico);
	addTexture("pacman_galactico", pacmanGalacticoTexture);

	fantasmaGalactico1Texture = new Texture();
	fantasmaGalactico1Texture->loadFromImage(pathFantasmaGalactico1);
	addTexture("fantasma_galactico1", fantasmaGalactico1Texture);
	fantasmaGalactico2Texture = new Texture();
	fantasmaGalactico2Texture->loadFromImage(pathFantasmaGalactico2);
	addTexture("fantasma_galactico2", fantasmaGalactico2Texture);
	fantasmaGalactico3Texture = new Texture();
	fantasmaGalactico3Texture->loadFromImage(pathFantasmaGalactico3);
	addTexture("fantasma_galactico3", fantasmaGalactico3Texture);
	fantasmaGalactico4Texture = new Texture();
	fantasmaGalactico4Texture->loadFromImage(pathFantasmaGalactico4);
	addTexture("fantasma_galactico4", fantasmaGalactico4Texture);

	frutaGalacticoTexture = new Texture();
	frutaGalacticoTexture->loadFromImage(pathFrutaGalactico);
	addTexture("fruta_galactico", frutaGalacticoTexture);

	monedaGalacticoTexture = new Texture();
	monedaGalacticoTexture->loadFromImage(pathMonedaGalactico);
	addTexture("moneda_galactico", monedaGalacticoTexture);

	superMonedaGalacticoTexture = new Texture();
	superMonedaGalacticoTexture->loadFromImage(pathSuperMonedaGalactico);
	addTexture("supermoneda_galactico", superMonedaGalacticoTexture);

	paredGalacticoTexture = new Texture();
	paredGalacticoTexture->loadFromImage(pathParedGalactico);
	addTexture("pared_galactico", paredGalacticoTexture);

	pacmanAsesinoTexture = new Texture();
	pacmanAsesinoTexture->loadFromImage(pathPacmanAsesino);
	addTexture("pacman_asesino", pacmanAsesinoTexture);

	fantasmaAsesino1Texture = new Texture();
	fantasmaAsesino1Texture->loadFromImage(pathFantasmaAsesino1);
	addTexture("fantasma_asesino1", fantasmaAsesino1Texture);
	fantasmaAsesino2Texture = new Texture();
	fantasmaAsesino2Texture->loadFromImage(pathFantasmaAsesino2);
	addTexture("fantasma_asesino2", fantasmaAsesino2Texture);
	fantasmaAsesino3Texture = new Texture();
	fantasmaAsesino3Texture->loadFromImage(pathFantasmaAsesino3);
	addTexture("fantasma_asesino3", fantasmaAsesino3Texture);
	fantasmaAsesino4Texture = new Texture();
	fantasmaAsesino4Texture->loadFromImage(pathFantasmaAsesino4);
	addTexture("fantasma_asesino4", fantasmaAsesino4Texture);

	frutaAsesinoTexture = new Texture();
	frutaAsesinoTexture->loadFromImage(pathFrutaAsesino);
	addTexture("fruta_asesino", frutaAsesinoTexture);

	monedaAsesinoTexture = new Texture();
	monedaAsesinoTexture->loadFromImage(pathMonedaAsesino);
	addTexture("moneda_asesino", monedaAsesinoTexture);

	superMonedaAsesinoTexture = new Texture();
	superMonedaAsesinoTexture->loadFromImage(pathSuperMonedaAsesino);
	addTexture("supermoneda_asesino", superMonedaAsesinoTexture);

	paredAsesinoTexture = new Texture();
	paredAsesinoTexture->loadFromImage(pathParedAsesino);
	addTexture("pared_asesino", paredAsesinoTexture);
}

void TextureManager::initializeSDL(SDL_Renderer* _renderer) {
	load("Resources/PacmanClasico.bmp", "pacman_clasico", _renderer);
	load("Resources/BlinkyClasico.bmp", "fantasma_clasico1", _renderer);
	load("Resources/ClydeClasico.bmp", "fantasma_clasico2", _renderer);
	load("Resources/InkeyClasico.bmp", "fantasma_clasico3", _renderer);
	load("Resources/PinkyClasico.bmp", "fantasma_clasico4", _renderer);
	load("Resources/FrutasClasico.png", "fruta_clasico", _renderer);
	load("Resources/MonedasClasico.jpg", "moneda_clasico", _renderer);
	load("Resources/SupermonedasClasico.jpg", "supermoneda_clasico", _renderer);
	load("Resources/Pared.png", "pared_clasico", _renderer);
	load("Resources/ParedClasico.bmp", "pared_clasico_adapter", _renderer);
}

TextureManager::~TextureManager() {
	free();
}

void TextureManager::addTexture(string _key, Texture* _texture)
{
	mapTexturas[_key] = _texture;
}

void TextureManager::free()
{
	for (pair<string, Texture*> elementoMapTexturas : mapTexturas) {
		mapTexturas.erase(elementoMapTexturas.first);
	}
}


bool TextureManager::load(string fileName, string id, SDL_Renderer* pRenderer)
{

	SDL_Surface* tempsurface = IMG_Load(fileName.c_str());
	//Checks
	if (tempsurface == 0)
	{
		cout << IMG_GetError();
		return false;
	}
	//Create a texture from temporary surface
	SDL_Texture* sdltexture = SDL_CreateTextureFromSurface(pRenderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	if (sdltexture != 0)
	{
		texturemap[id] = sdltexture;
		return true;
	}

	return false;
}

void TextureManager::draw(std::string id, int x, int y,
	int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, texturemap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, double angle, int alpha, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_SetTextureAlphaMod(texturemap[id], alpha);
	SDL_RenderCopyEx(pRenderer, texturemap[id], &srcRect, &destRect, angle, 0, flip);
}

void TextureManager::drawTile(std::string id, int margin, int spacing, int x, int y,
	int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, texturemap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}

void TextureManager::clearTextureMap()
{
	texturemap.clear();
}

void TextureManager::clearFromTextureMap(string _key)
{
	texturemap.erase(_key);
}
