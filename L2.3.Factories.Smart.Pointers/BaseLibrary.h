#ifndef BASELIBRARY_H
#define BASELIBRARY_H

#include"Library.h"
#include"Child1Factory.h"
#include"Child2Factory.h"

using namespace std;

class BaseLibrary: public Library{

public:
	BaseLibrary() {
		inventory["child1"] = std::make_unique<Child1Factory>();
		inventory["child2"] = std::make_unique<Child2Factory>();
	}
};

#endif