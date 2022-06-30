#include "sdlcontrol.h"

SDLControl mysdlcontrol;

bool SDLControl::init()
{
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return false;
	}
		
	window = SDL_CreateWindow("spase imvaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
		return false;
	}

	SDL_Surface* backgroundSurface = SDL_LoadBMP( "background.bmp" );
	if( backgroundSurface == NULL )
	{
		printf( "Unable to load image! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	SDL_Surface* imageSurface = SDL_LoadBMP( "sprites.bmp" );
	if( imageSurface == NULL )
	{
		printf( "Unable to load image! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
	if( texture == NULL )
	{
		printf( "Unable to load image! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
	if( backgroundTexture == NULL )
	{
		printf( "Unable to load image! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(backgroundSurface);

	return true;
}


void SDLControl::endOfFrame()
{
	//flip
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);
}


void SDLControl::close()
{
	//Free loaded image
	SDL_DestroyTexture( texture );
	texture = NULL;

	//Free loaded backgroung image
	SDL_DestroyTexture( backgroundTexture );
	backgroundTexture = NULL;


	//Destroy window	
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


void SDLControl::drawBackground()
{
	SDL_Rect sr = {0, 0, ScreenWidth, ScreenHeight};
	SDL_Rect dr = {0, 0, ScreenWidth, ScreenHeight};
	SDL_RenderCopy(mysdlcontrol.renderer, mysdlcontrol.backgroundTexture, &sr, &dr);
}


void SDLControl::readInput()
{
	m_spacePressed = false;

	while( SDL_PollEvent( &e ) != 0 )
	{
		//User requests quit
		if( e.type == SDL_QUIT )
		{
			m_quitneeded = true;
		}
		else if( (e.type == SDL_KEYDOWN) && (e.key.keysym.sym == SDLK_ESCAPE) )
		{
			m_quitneeded = true;
		}
		//Keypress Held
		else if(( e.type == SDL_KEYDOWN ) && ( m_spaceStillPressed ))
		{
			switch( e.key.keysym.sym )
			{
				case SDLK_SPACE:
					m_spaceHeld = true;
					break;
			}
		}
		//Keypress down
		else if( e.type == SDL_KEYDOWN )
		{
			switch( e.key.keysym.sym )
			{
				case SDLK_LEFT:
					m_leftPressed = true;
					break;

				case SDLK_RIGHT:
					m_rightPressed = true;
					break;

				case SDLK_a:
					m_aPressed = true;
					break;

				case SDLK_SPACE:
					m_spacePressed = true;
					m_spaceStillPressed = true;
					break;
			}
		}
		//Keypress up
		else if( e.type == SDL_KEYUP )
		{
			switch( e.key.keysym.sym )
			{
				case SDLK_LEFT:
					m_leftPressed = false;
					break;

				case SDLK_RIGHT:
					m_rightPressed = false;
					break;

				case SDLK_a:
					m_aPressed = false;
					break;

				case SDLK_SPACE:
					m_spacePressed = false;
					m_spaceStillPressed = false;
					m_spaceHeld = false;
					break;
			}
		}
	}
}


void SDLControl::drawSprite(int sprite, int spriteX, int spriteY)
{
	int srX, srY = 0;
	int W, H = 0;

	int drX = spriteX;
	int drY = spriteY;

	
	switch(sprite)
	{
	case graphicalElements::catship:
			srX = 0;
			srY = 0;
			W = 150;
			H = 75;
			break;

		case graphicalElements::catshipSquint:
			srX = 0;
			srY = 275;
			W = 150;
			H = 75;
			break;

		case graphicalElements::explodedShip1:
			srX = 0;
			srY = 125;
			W = 150;
			H = 75;
			break;

		case graphicalElements::explodedShip2:
			srX = 0;
			srY = 200;
			W = 150;
			H = 75;
			break;

		case graphicalElements::mediumCatInvader:
			srX = 150;
			srY = 0;
			W = 50;
			H = 50;
			break;

		case graphicalElements::mediumCatInvader2:
			srX = 150;
			srY = 50;
			W = 50;
			H = 50;
			break;

		case graphicalElements::meowthInvader:
			srX = 200;
			srY = 0;
			W = 50;
			H = 50;
			break;

		case graphicalElements::meowthInvader2:
			srX = 200;
			srY = 50;
			W = 50;
			H = 50;
			break;

		case graphicalElements::jellycatInvader:
			srX = 250;
			srY = 0;
			W = 50;
			H = 50;
			break;

		case graphicalElements::jellycatInvader2:
			srX = 250;
			srY = 50;
			W = 50;
			H = 50;
			break;

		case graphicalElements::explosion:
			srX = 300;
			srY = 0;
			W = 50;
			H = 50;
			break;

		case graphicalElements::friendlyBullet:
			srX = 2;
			srY = 100;
			W = 8;
			H = 25;
			break;

		case graphicalElements::held:
			srX = 350;
			srY = 0;
			W = 50;
			H = 50;
			break;

		case graphicalElements::jabbed:
			srX = 400;
			srY = 0;
			W = 50;
			H = 50;
			break;

	}

	SDL_Rect sr = {srX, srY, W, H};
	SDL_Rect dr = {drX, drY, W, H};
	SDL_RenderCopy(mysdlcontrol.renderer, mysdlcontrol.texture, &sr, &dr);
}

