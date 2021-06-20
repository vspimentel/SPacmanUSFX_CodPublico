#pragma once
#include<map>
#include "Texture.h"
using namespace std;

class TextureManager
{
private:
	map<string, Texture*> mapTexturas;

	const string pathPacmanClasico = "Resources/PacmanClasico.bmp";
	const string pathFantasmaClasico1 = "Resources/BlinkyClasico.bmp";
	const string pathFantasmaClasico2 = "Resources/ClydeClasico.bmp";
	const string pathFantasmaClasico3 = "Resources/InkeyClasico.bmp";
	const string pathFantasmaClasico4 = "Resources/PinkyClasico.bmp";
	const string pathFrutaClasico = "Resources/FrutasClasico.png";
	const string pathMonedaClasico = "Resources/MonedasClasico.jpg";
	const string pathSuperMonedaClasico = "Resources/SupermonedasClasico.jpg";
	const string pathParedClasico = "Resources/Pared.png";
	const string pathParedClasicoAdapter = "Resources/ParedClasico.bmp";

	const string pathPacmanGalactico = "Resources/PacmanGalactico.bmp";
	const string pathFantasmaGalactico1 = "Resources/BlinkyGalactico.bmp";
	const string pathFantasmaGalactico2 = "Resources/ClydeGalactico.bmp";
	const string pathFantasmaGalactico3 = "Resources/InkeyGalactico.png";
	const string pathFantasmaGalactico4 = "Resources/PinkyGalactico.bmp";
	const string pathFrutaGalactico = "Resources/FrutasGalactico.png";
	const string pathMonedaGalactico = "Resources/MonedasGalactico.png";
	const string pathSuperMonedaGalactico = "Resources/SupermonedasGalactico.png";
	const string pathParedGalactico = "Resources/Pared.png";


	Texture* pacmanClasicoTexture;
	Texture* fantasmaClasico1Texture;
	Texture* fantasmaClasico2Texture;
	Texture* fantasmaClasico3Texture;
	Texture* fantasmaClasico4Texture;
	Texture* frutaClasicoTexture;
	Texture* monedaClasicoTexture;
	Texture* superMonedaClasicoTexture;
	Texture* paredClasicoTexture;
	Texture* paredClasicoAdapterTexture;

	Texture* pacmanGalacticoTexture;
	Texture* fantasmaGalactico1Texture;
	Texture* fantasmaGalactico2Texture;
	Texture* fantasmaGalactico3Texture;
	Texture* fantasmaGalactico4Texture;
	Texture* frutaGalacticoTexture;
	Texture* monedaGalacticoTexture;
	Texture* superMonedaGalacticoTexture;
	Texture* paredGalacticoTexture;
	
public:

	TextureManager();
	~TextureManager();

	Texture* getTexture(string _key) { return mapTexturas[_key]; }
	void addTexture(string _key, Texture* _texture);
	void free();


};

