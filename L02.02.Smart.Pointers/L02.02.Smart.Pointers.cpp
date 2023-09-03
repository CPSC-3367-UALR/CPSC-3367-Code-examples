// L02.02.Smart.Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>

// TODO 01. You might want to define the std namespace here to avoid repeating the prefix

int main()
{
	//Different ways to create a shared pointer
	std::shared_ptr<int> i(new int);//Not the most efficient way to do it
	std::shared_ptr<int> j(std::make_shared<int>(7));

	*i = 5;

	i = j; // WHat does it happen here? 
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

