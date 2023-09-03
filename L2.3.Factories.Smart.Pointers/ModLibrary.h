#ifndef MODGAMEFACTORY_H
#define MODGAMEFACTORY_H

#include "Library.h"
#include"Child3Factory.h"


class ModLibrary : public Library {

public:

	ModLibrary() {
		inventory["child3"] = std::make_unique<Child3Factory>();
	}
};

#endif