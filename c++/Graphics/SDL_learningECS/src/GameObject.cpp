#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char * textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture( textureSheet);

	if (objTexture == NULL)
	{
		std::cout << "Unable to load texture" << std::endl;
	}
			
	xpos = x;
	ypos = y;

}

void GameObject::Update()
{
	keystate = SDL_GetKeyboardState(NULL);
	
	if (keystate[SDL_SCANCODE_RIGHT])
		xpos ++;
	
	if (keystate[SDL_SCANCODE_LEFT])
		xpos --;

	if (keystate[SDL_SCANCODE_UP])
		ypos --;

	if (keystate[SDL_SCANCODE_DOWN])
		ypos ++;
 	
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

