#include "MapGenerator.h"

MapGenerator* MapGenerator::instance = nullptr;

MapGenerator* MapGenerator::createInstance(TileGraph* _tileGraph, TextureManager* _textureManager, Factory* _fabrica) {
	if (instance == nullptr)
		instance = new MapGenerator(_tileGraph, _textureManager, _fabrica);
	return instance;
}

MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, Factory* _factory)
{
	factory = _factory;
	tileGraph = _tileGraph;
	textureManager = _textureManager;

	FantasmasFactory::initialize();
	FrutaFactory::initialize();
}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());
		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;
			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				objetoNuevo = factory->createParedInstance(tileNuevo, textureManager, false);
				break;
			case '.':
				objetoNuevo = factory->createMonedaInstance(tileNuevo, textureManager);
				break;
			case 'p':
				objetoNuevo = factory->createPacmanInstance(tileNuevo, textureManager, 5);
				break;
			case 'a':
				objetoNuevo = FantasmasFactory::getTipoClasicoBlinky();
				//objetoNuevo = FantasmasFactory::getTipoGalacticoBlinky();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, 2);
				break;
			case 'b':
				objetoNuevo = FantasmasFactory::getTipoClasicoClyde();
				//objetoNuevo = FantasmasFactory::getTipoGalacticoClyde();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, 3);
				break;
			case 'c':
				objetoNuevo = FantasmasFactory::getTipoClasicoInkey();
				//objetoNuevo = FantasmasFactory::getTipoGalacticoInkey();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, 2);
				break;
			case 'd':
				objetoNuevo = FantasmasFactory::getTipoClasicoPinky();
				//objetoNuevo = FantasmasFactory::getTipoGalacticoPinky();
				((Fantasma*)objetoNuevo)->reconfigurar(tileNuevo, 3);
				break;
			}
			if (objetoNuevo != nullptr) {
				vectorObjetosJuego.push_back(objetoNuevo);
			}
		}
		y++;
	}

	// Close the file
	file.close();
	
	GameObject* objetoPanel = new GamePanel(new Texture(), 20, 450);
	
	vectorObjetosJuego.push_back(objetoPanel);

	return true;
}

void MapGenerator::newObjects() {
	int time = 300;
	Tile* newTile;
	if (cont < time) {
		cont++;
	}
	else {
		do {
			newTile = tileGraph->getTileEn(rand() % tileGraph->getAnchoTile(), rand() % tileGraph->getAltoTile());
		} while (newTile->getPared() != nullptr);
		TIPO_FRUTA t = static_cast<TIPO_FRUTA> (rand()% MAX);
		if (newTile->getMoneda() != nullptr)
			newTile->getMoneda()->deleteGameObject();
		GameObject* newObject = FrutaFactory::getTipoFrutaClasico();
		//GameObject* newObject = FrutaFactory::getTipoFrutaGalactico();
		((Fruta*)newObject)->reconfigurar(newTile, t);
		if (newObject != nullptr)
			vectorObjetosJuego.push_back(newObject);
		cont = 0;
	}
}

void MapGenerator::populate(std::vector<GameObject*> &_vectorObjetosJuegoGM)
{
	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}
	vectorObjetosJuego.clear();
}