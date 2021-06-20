#include "GameManager.h"

using namespace std;

int main(int argc, char* argv[]) {
    GameManager* theApp = GameManager::crearInstancia();
    return theApp->onExecute();
}