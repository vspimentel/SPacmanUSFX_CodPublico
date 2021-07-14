#pragma once
#include <vector>
#include <string>
#include <iostream>

#include "GameActor.h"
#include "Texture.h"

using namespace std;

class FlyweightFactory
{
private:
	static int numTextures;
	static vector<Texture*> textures;
public:

	//static void initialize() {
	//	numTextures = -1;
	//	textures = {};
	//}

	static Texture* getTexture(string texture, string path);
	static void reportTextures();
};

