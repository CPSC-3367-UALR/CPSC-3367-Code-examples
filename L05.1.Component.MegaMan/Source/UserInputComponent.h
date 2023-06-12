#pragma once
#include<string>
#include "Component.h"
#include "SDL.h"
class UserInput : public Component
{
public:
	UserInput(GameObject*);
	~UserInput();
	void Initialize();
	void HandleEvent(SDL_Event* event);

	void Start();
	void Update();
	void Finish();

	std::string getCommand() { return command; }

protected:
	float commandAngle;
	float xVelocity;
	float yVelocity;
	std::string command;
};
