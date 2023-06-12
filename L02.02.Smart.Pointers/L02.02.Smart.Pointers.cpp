// L02.02.Smart.Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

int main()
{
	//creating a shared pointer
	std::shared_ptr<int> i(new int);//bad
	std::shared_ptr<int> j(std::make_shared<int>(0));

	*i = 5;
	*j = 7;

	i = j; //the memory holding '7' is deleted here!
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

