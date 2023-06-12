#ifndef BASELIBRARY_H
#define BASELIBRARY_H

#include"Library.h"
#include"Child1Factory.h"
#include"Child2Factory.h"

using namespace std;

class BaseLibrary: public Library{

public:
	BaseLibrary() {
		/*
		*  The error you're encountering is related to the assignment operator not being available for the std::shared_ptr<ObjectFactory> type when trying to assign a std::shared_ptr<Child1Factory> or std::shared_ptr<Child2Factory> to it.
		* To resolve this issue, you can use a std::shared_ptr<ObjectFactory> to hold the pointer to the derived factory class instances. However, to properly assign the derived factory instances to the base class pointer, you need to use 
		* std::static_pointer_cast to perform the conversion. Here's an updated version of your code:
		*/
		//inventory["child1"] = make_shared<Child1Factory>();
		//inventory["child2"] = make_shared<Child2Factory>();
		inventory["child1"] = static_pointer_cast<ObjectFactory>(make_shared<Child1Factory>());
		inventory["child2"] = static_pointer_cast<ObjectFactory>(make_shared<Child2Factory>());
	}
};

#endif