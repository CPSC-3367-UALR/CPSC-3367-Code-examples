/*
* Author:	Keith Bush
*			UALR
* 
* Date:		February 1, 2015	
*
* File:		Source.cpp
*
* Purpose:	Demonstrate basic animation of sprites, frame timing, and
*           rotation capabilities of rendering.
*/

#include <iostream>

#include "SDL.h"
#include "GraphicsDevice.h"
#include "Timer.h"
#include "GameObject.h"

// TODO 1. We analyze the program
int main(int argc, char *argv[])
{
	//Construct Graphical Device
	GraphicsDevice* gDevice = new GraphicsDevice(800,600);
	if(!gDevice->Initialize(true))
	{
		printf( "Graphics Device could not initialize! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
	}

	//Construct Event
	// Here we are just allocating enough memory to later store information on a hypothetical captured event
	SDL_Event* event = new SDL_Event();
	if(!event){
		printf( "SDL Event could not initialize! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
	}

	//Construct Frame Timer
	Timer* fps = new Timer();
	if(!fps->Initialize(100)){
		printf( "Frame Timer could not initialize! SDL_Error: %s\n", SDL_GetError() );
		exit(1);
	}

	//Initialize Game Object
	GameObject* object = new GameObject();
	object->Initialize(gDevice->getRenderer(),"./Assets/Images/PlayerPaper.png");

	//Initialize Termination Criteria
	bool quit = false;

	//While the user hasn't quit
	while(!quit)
	{

		//Start the frame's time
		fps->start();

		//Check for an event. We check the last event that happened in the system
		if(SDL_PollEvent( event ))
		{
			//Translate Event to QUIT signal. You can easily see the types of events SDL provides you information about
			if(event->type == SDL_QUIT)
			{
				quit=true;
			}
		}

		//
		//Object handles relevant events
		//
		// TODO 02. We propagate the event to the different objects we have in the game so their state is updated accordingly
		object->HandleEvent(event); 

		// TODO 05. We first manage the input, we update the state of the object and then we refresh the visualization
		//
		//Conduct the update (i.e., physics/animation)
		//
		object->Update();

		//
		//Game state updates complete, let's draw
		//
		gDevice->Begin();

		//Draw a game object
		object->Draw();

		//End the frame and draw to window
		gDevice->Present();

		//Buffer the Frames per second (if necessary)
		fps->fpsRegulate();


	}

	return 0;

}