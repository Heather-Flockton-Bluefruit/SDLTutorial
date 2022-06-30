#ifndef SDLCONTROL_H
#define SDLCONTROL_H

#include <SDL.h>
#include <stdio.h>
#include <string>

const int ScreenWidth = 1024;
const int ScreenHeight = 1024;


class SDLControl
{
public:
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Texture* backgroundTexture;

	static const int BottomOfPlayArea = 923;
	static const int TopOfPlayArea = 50;
	static const int LeftOfPlayArea = 47;
	static const int RightOfPlayArea = 980;
	static const int CentreOfPlayArea = 513;
	
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
	bool m_spacePressed;
	bool m_spaceHeld;

private:
	SDL_Window* window;
	SDL_Event e;

	bool m_spaceStillPressed;
};

extern SDLControl mysdlcontrol;

struct graphicalElements
{
	enum elementNames
	{
		catship,
		catshipSquint,
		explodedShip1,
		explodedShip2,
		mediumCatInvader,
		mediumCatInvader2,
		meowthInvader,
		meowthInvader2,
		jellycatInvader,
		jellycatInvader2,
		explosion,
		friendlyBullet,
		held,
		jabbed,
	};
};

#endif