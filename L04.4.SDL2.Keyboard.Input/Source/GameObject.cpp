#include "GameObject.h"
#include "Texture.h"

GameObject::GameObject()
{
	renderer = NULL;
	texture = NULL;
	xPosition = 0.f;
	yPosition = 0.0f;
	angle = 0.0f;
	commandAngle = 0.0f;
	xVelocity = 0.0f;
	yVelocity = 0.0f;
}

GameObject::~GameObject()
{
	//Unhook renderer from object
	renderer = NULL;
	texture->free();
}

bool GameObject::Initialize(SDL_Renderer* renderer,std::string path)
{
	//Assign the renderer for  this object
	this->renderer = renderer;

	//Load the Art Asset
	texture = new Texture();
	texture->load(renderer,path);

	return(true);
}

// TODO 03. We'll update some of the properties of the object according to the event captured

void GameObject::HandleEvent(SDL_Event* event)
{
	switch(event->type)
	{
		// if it is a key down event
	case SDL_KEYDOWN:
		// We need to figure out the key that was pressed
		// We use "event->key" to get the corresponding SDL_KeyboardEvent
		// Then by accessing keysym be get the key that was pressed or released
		// Then by accessing symn we get the SDL code for the key in question
		switch(event->key.keysym.sym)
		{
		case SDLK_LEFT:
			// Rotation angle
			commandAngle = -360.0f/100.f;
			break;
		case SDLK_RIGHT:
			commandAngle = 360.0f/100.f;
			break;
		case SDLK_UP:
			// Velocity
			xVelocity = 1.0f;
			yVelocity = 1.0f;
			break;
		case SDLK_DOWN:
			xVelocity = 0.0f;
			yVelocity = 0.0f;
			break;
		}
		// Basically, here we calculate a new velocity and orientation for the object
		// Those values are then used whitin the update method to set the new state of the object
	}
}

// TODO 04. We update the state of the object 

void GameObject::Update()
{
	//Quasi-physics updates
	// We update the position using the new velocity value
	xPosition += xVelocity;
	yPosition += yVelocity;
	// We update the orientation using the new angle
	angle += commandAngle;

	//Set commandAngle to 0 to avoid frustrated steering.
	commandAngle = 0.0f;
}

void GameObject::Draw()
{
	texture->renderEx(renderer,(int)xPosition,(int)yPosition,angle,NULL);
}
