#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <random>

#include"Library.h"
#include"BaseLibrary.h"
#include"ModLibrary.h"

int main() {

	//Factory types
	std::unique_ptr<Library> baseLibrary{ std::make_unique<BaseLibrary>() }; //stores an inventory of base ObjectFactories
	std::unique_ptr<Library> modLibrary{ std::make_unique<ModLibrary>() };  //stores inventory of modifed ObjectFactories (if they exist)

	//Display utility of the object factory
	std::vector<std::unique_ptr<Object>> objects;

	//Imagine that the game is dynamically calling for types
	std::string objectType;

	std::random_device seed;
	std::default_random_engine engine(seed());
	std::uniform_int_distribution chooseType(1, 3);

	const int N{ 10 };

	/**
	 * We add three objects to our game.
	 * Those objects might be of different types(child1 - child3).
	 * The type to be used will
	 * */

	for (int i = 0; i < N; i++) {
		//Randomly demand one of three types of object
		switch (chooseType(engine)) {
		case 1:
			objectType = "child1";
			break;
		case 2:
			objectType = "child2";
			break;
		case 3:
			objectType = "child3";
			break;
		}

		std::cout << "TYPE: " << objectType << std::endl;

		//Search through the mod classes
		if (auto found{ modLibrary->inventory.find(objectType) }; found != modLibrary->inventory.end()) {
			objects.push_back(found->second->create());
		}
		//Search through the base classes
		else if (auto found{ baseLibrary->inventory.find(objectType) }; found != baseLibrary->inventory.end()) {
			objects.push_back(found->second->create());
		}
	}

	//Display the game space
	for (auto& object : objects) {
		std::cout << object->getNumber() << std::endl;
	}

	system("PAUSE");

	return 0;
}
