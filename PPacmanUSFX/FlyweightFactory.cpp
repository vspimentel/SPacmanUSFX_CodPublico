#include "FlyweightFactory.h"

vector<Texture*> FlyweightFactory::textures = {};
int FlyweightFactory::numTextures = -1;

Texture* FlyweightFactory::getTexture(string texture, string path)
{
	for (int i = 0; i < numTextures; i++) {
		if (textures[i] != nullptr && textures[i]->getName() == texture) {
			return textures[i];
		}
	}
	textures.push_back(new Texture(texture));
	numTextures++;
	textures[numTextures]->loadFromImage(path);
	reportTextures();
	if (textures[numTextures] != nullptr) {
		return textures[numTextures];
	}
}

void FlyweightFactory::reportTextures()
{
	cout << "Active Flyweights: ";
	for (int i = 0; i < numTextures; i++)
		cout << textures[i]->getName() << " ";
	cout << endl;
}
