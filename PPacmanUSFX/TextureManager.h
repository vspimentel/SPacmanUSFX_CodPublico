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

	const string pathPacmanAsesino = "Resources/PacmanGalactico.bmp";
	const string pathFantasmaAsesino1 = "Resources/BlinkyGalactico.bmp";
	const string pathFantasmaAsesino2 = "Resources/ClydeGalactico.bmp";
	const string pathFantasmaAsesino3 = "Resources/InkeyGalactico.png";
	const string pathFantasmaAsesino4 = "Resources/PinkyGalactico.bmp";
	const string pathFrutaAsesino = "Resources/FrutasGalactico.png";
	const string pathMonedaAsesino = "Resources/MonedasGalactico.png";
	const string pathSuperMonedaAsesino = "Resources/SupermonedasGalactico.png";
	const string pathParedAsesino = "Resources/Pared.png";

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

	Texture* pacmanAsesinoTexture;
	Texture* fantasmaAsesino1Texture;
	Texture* fantasmaAsesino2Texture;
	Texture* fantasmaAsesino3Texture;
	Texture* fantasmaAsesino4Texture;
	Texture* frutaAsesinoTexture;
	Texture* monedaAsesinoTexture;
	Texture* superMonedaAsesinoTexture;
	Texture* paredAsesinoTexture;

	TextureManager();
	static TextureManager* instance;
	
public:

	static TextureManager* createInstance();

	~TextureManager();

	Texture* getTexture(string _key) { return mapTexturas[_key]; }
	void addTexture(string _key, Texture* _texture);
	void free();


};

