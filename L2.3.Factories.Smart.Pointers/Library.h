#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include<string>
#include<map>
#include <memory>
#include"ObjectFactory.h"


using namespace std;

class Library {

public:
	//map that represents the inventory of objects that will be part of the game
	std::map<std::string, std::unique_ptr<ObjectFactory>> inventory;
};

#endif