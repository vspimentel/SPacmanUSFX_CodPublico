#include "TextureManager.h"

TextureManager* TextureManager::instance = nullptr;

TextureManager* TextureManager::createInstance() {
	if (instance == nullptr)
		instance = new TextureManager();
	return instance;
}

TextureManager::TextureManager()
{
}

void TextureManager::initialize() {
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

void TextureManager::initializeSDL() {
	load(pathPacmanClasico, "pacman_clasico");
	load(pathFantasmaClasico1, "fantasma_clasico1");
	load(pathFantasmaClasico2, "fantasma_clasico2");
	load(pathFantasmaClasico3, "fantasma_clasico3");
	load(pathFantasmaClasico4, "fantasma_clasico4");
	load(pathFrutaClasico, "fruta_clasico");
	load(pathMonedaClasico, "moneda_clasico");
	load(pathSuperMonedaClasico, "supermoneda_clasico");
	load(pathParedClasico, "pared_clasico");
	load(pathParedClasicoAdapter, "pared_clasico_adapter");

	load(pathPacmanGalactico, "pacman_galactico");
	load(pathFantasmaGalactico1, "fantasma_galactico1");
	load(pathFantasmaGalactico2, "fantasma_galactico2");
	load(pathFantasmaGalactico3, "fantasma_galactico3");
	load(pathFantasmaGalactico4, "fantasma_galactico4");
	load(pathFrutaGalactico, "fruta_galactico");
	load(pathMonedaGalactico, "moneda_galactico");
	load(pathSuperMonedaGalactico, "supermoneda_galactico");
	load(pathParedGalactico, "pared_galactico");

	load(pathPacmanAsesino, "pacman_asesino");
	load(pathFantasmaAsesino1, "fantasma_asesino1");
	load(pathFantasmaAsesino2, "fantasma_asesino2");
	load(pathFantasmaAsesino3, "fantasma_asesino3");
	load(pathFantasmaAsesino4, "fantasma_asesino4");
	load(pathFrutaAsesino, "fruta_asesino");
	load(pathMonedaAsesino, "moneda_asesino");
	load(pathSuperMonedaAsesino, "supermoneda_asesino");
	load(pathParedAsesino, "pared_asesino");
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


bool TextureManager::load(string fileName, string id)
{

	SDL_Surface* tempsurface = IMG_Load(fileName.c_str());
	//Checks
	if (tempsurface == 0)
	{
		cout << IMG_GetError();
		return false;
	}
	//Create a texture from temporary surface
	SDL_Texture* sdltexture = SDL_CreateTextureFromSurface(renderer, tempsurface);
	SDL_FreeSurface(tempsurface);

	if (sdltexture != NULL)
	{
		texturemap[id] = sdltexture;
		if (texturemap[id] == NULL)
			cout << "Error" << endl;
		return true;
	}

	return false;
}

void TextureManager::draw(string id, int x, int y,
	int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(renderer, texturemap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame, int anchoClip, int altoClip, double angle, int alpha, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = anchoClip * currentFrame;
	srcRect.y = altoClip * currentRow;
	destRect.w = width;
	destRect.h = height;
	srcRect.w = anchoClip;
	srcRect.h = altoClip;
	destRect.x = x;
	destRect.y = y;

	SDL_SetTextureAlphaMod(texturemap[id], alpha);
	SDL_RenderCopyEx(renderer, texturemap[id], &srcRect, &destRect, angle, 0, flip);
}

void TextureManager::drawTile(string id, int margin, int spacing, int x, int y,
	int width, int height, int currentRow, int currentFrame)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(renderer, texturemap[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}

void TextureManager::clearTextureMap()
{
	texturemap.clear();
}

void TextureManager::clearFromTextureMap(string _key)
{
	texturemap.erase(_key);
}
