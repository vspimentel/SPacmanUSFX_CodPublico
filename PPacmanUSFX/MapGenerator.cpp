#include "MapGenerator.h"

MapGenerator* MapGenerator::instance = nullptr;

MapGenerator* MapGenerator::createInstance(TileGraph* _tileGraph, Factory* _fabrica) {
	if (instance == nullptr)
		instance = new MapGenerator(_tileGraph, _fabrica);
	return instance;
}

MapGenerator::MapGenerator(TileGraph* _tileGraph, Factory* _factory)
{
	factory = _factory;
	tileGraph = _tileGraph;

	FantasmasFactory::initializeClasico();
	//FantasmasFactory::initializeGalactico();
	//FantasmasFactory::initializaeAsesino();
	FrutaFactory::initializeClasico();
	//FrutaFactory::initializeGalactico();
	//FrutaFactory::initializeAsesino();
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
			GameActor* newObject = nullptr;
			Decorator* newDecorator = nullptr;
			Tile* newTile = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				newObject = factory->createParedInstance(newTile);
				break;
			case '/':
				newObject = factory->createParedPoderInstance(newTile);
				break;
			case '.':
				newObject = factory->createMonedaInstance(newTile);
				break;
			case '+':
				newObject = factory->createMonedaPoderInstance(newTile);
				newDecorator = new DecoratorAura(newObject);
				vectorObjetosJuego.push_back(newDecorator);
				break;
			case 'p':
				newObject = factory->createPacmanInstance(newTile, 5);
				break;
			case 'a':
				newObject = FantasmasFactory::getTipoBlinky();
				((Fantasma*)newObject)->reconfigurar(newTile, 2);
				break;
			case 'b':
				newObject = FantasmasFactory::getTipoClyde();
				((Fantasma*)newObject)->reconfigurar(newTile, 3);
				break;
			case 'c':
				newObject = FantasmasFactory::getTipoInkey();
				((Fantasma*)newObject)->reconfigurar(newTile, 2);
				break;
			case 'd':
				newObject = FantasmasFactory::getTipoPinky();
				((Fantasma*)newObject)->reconfigurar(newTile, 3);
				break;
			}
			if (newObject != nullptr) {
				vectorObjetosJuego.push_back(newObject);
			}
		}
		y++;
	}

	// Close the file
	file.close();
	
	GameObject* objetoPanel = new GamePanel(new Texture(), 20, 450);
	
	vectorObjetosJuego.push_back(((GameActor*)objetoPanel));

	return true;
}

void MapGenerator::newObjects() {
	Tile* newTile;
	if (contFruta < frutaTime) {
		contFruta++;
	}
	else {
		do {
			newTile = tileGraph->getTileEn(rand() % tileGraph->getAnchoTile(), rand() % tileGraph->getAltoTile());
		} while (newTile->getPared() != nullptr || newTile->getSupermoneda() != nullptr);
		TIPO_FRUTA t = ((TIPO_FRUTA)(rand()% MAX));
		if (newTile->getMoneda() != nullptr)
			newTile->getMoneda()->deleteGameObject();
		GameActor* newObject = FrutaFactory::getTipoFruta();
		((Fruta*)newObject)->reconfigurar(newTile, t);
		if (newObject != nullptr)
			vectorObjetosJuego.push_back(newObject);
		contFruta = 0;
	}
}

void MapGenerator::populate(std::vector<GameActor*> &_vectorObjetosJuegoGM)
{
	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}
	vectorObjetosJuego.clear();
}