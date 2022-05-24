#ifndef SDLCONTROL_H
#define SDLCONTROL_H

#include <SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;

class SDLControl
{
public:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Texture* backgroundTexture;
	
	bool init();
	void endOfFrame();
	void close();
	void drawSprite(int sprite, int spriteX, int spriteY);
	void drawBackground();
	
	void readInput();
	bool m_quitneeded;
	bool m_leftPressed;
	bool m_rightPressed;
	bool m_aPressed;

private:
	SDL_Window* window;
	SDL_Event e;
};

extern SDLControl mysdlcontrol;

#endif