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
