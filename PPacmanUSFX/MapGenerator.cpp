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

	//FantasmasFactory::initializeClasico();
	////FantasmasFactory::initializeGalactico();
	////FantasmasFactory::initializaeAsesino();
	//FrutaFactory::initializeClasico();
	////FrutaFactory::initializeGalactico();
	////FrutaFactory::initializeAsesino();
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
				actors.push_back(newDecorator);
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
				actors.push_back(newObject);
			}
		}
		y++;
	}

	// Close the file
	file.close();
	
	GameObject* objetoPanel = new GamePanel(new Texture("Panel1"), 20, 450);
	
	actors.push_back(((GameActor*)objetoPanel));

	return true;
}

void MapGenerator::newObjects() {
	Tile* newTile;
	if (contFruta < frutaTime) {
		contFruta++;
	}
	else {
		newTile = tileGraph->getTileEn(9 + rand() % (11 - 9), 0);
		TIPO_FRUTA t = ((TIPO_FRUTA)(rand() % MAX));
		GameActor* newObject = FrutaFactory::getTipoFruta();
		((Fruta*)newObject)->reconfigurar(newTile, t);
		if (newObject != nullptr)
			actors.push_back(newObject);
		contFruta = 0;
	}

	vector<GameActor*> fantasmas;
	for (int i = 0; i < actors.size(); i++) {
		if (actors[i]->getTipoObjeto() == FANTASMA) {
			fantasmas.push_back(actors[i]);
		}
	}
	for (int i = 0; i < fantasmas.size(); i++) {
		if (fantasmas[i]->getEliminar()) {
			textura = fantasmas[i]->getTexturaID();
			start = ((Fantasma*)fantasmas[i])->getStart();
			velocidad = ((Fantasma*)fantasmas[i])->getVelocidad();

		}

		if (contDelay >= delayTime) {
			if (!fantasmas[i]->getAlive() && !fantasmas[i]->getDead()) {
				fantasmas[i]->setTile(((Fantasma*)fantasmas[i])->getStart());
				fantasmas[i]->setAlive(true);
				fantasmas[i]->setVisible(true);
				contDelay = 0;
			}
		}
		else
			contDelay++;

		if (textura == "fantasma_galactico1" || textura == "fantasma_clasico1") {
			GameActor* newActor = FantasmasFactory::getTipoBlinky();
			newActor->setDead(true);
			newActor->setAlive(false);
			newActor->setVisible(false);
			((Fantasma*)newActor)->setStart(start);
			((Fantasma*)newActor)->setVelocidad(velocidad);
			actors.push_back(newActor);
			textura = "";
		}
		else if (textura == "fantasma_galactico2" || textura == "fantasma_clasico2") {
			GameActor* newActor = FantasmasFactory::getTipoClyde();
			newActor->setDead(true);
			newActor->setAlive(false);
			newActor->setVisible(false);
			((Fantasma*)newActor)->setStart(start);
			((Fantasma*)newActor)->setVelocidad(velocidad);
			actors.push_back(newActor);
			textura = "";
		}
		else if (textura == "fantasma_galactico3" || textura == "fantasma_clasico3") {
			GameActor* newActor = FantasmasFactory::getTipoInkey();
			newActor->setDead(true);
			newActor->setAlive(false);
			newActor->setVisible(false);
			((Fantasma*)newActor)->setStart(start);
			((Fantasma*)newActor)->setVelocidad(velocidad);
			actors.push_back(newActor);
			textura = "";
		}
		else if (textura == "fantasma_galactico4" || textura == "fantasma_clasico4") {
			GameActor* newActor = FantasmasFactory::getTipoPinky();
			newActor->setDead(true);
			newActor->setAlive(false);
			newActor->setVisible(false);
			((Fantasma*)newActor)->setStart(start);
			((Fantasma*)newActor)->setVelocidad(velocidad);
			actors.push_back(newActor);
			textura = "";
		}
	}
}

void MapGenerator::populate(std::vector<GameActor*> &_vectorObjetosJuegoGM)
{
	for (auto ivoj = actors.begin(); ivoj != actors.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}
	actors.clear();
}