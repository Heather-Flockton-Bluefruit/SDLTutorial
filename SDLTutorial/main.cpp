#include <SDL.h>
#include <stdio.h>
#include <string>

#include "sdlcontrol.h"
#include "catship.h"
#include "invaders.h"
#include "bullets.h"

const int BOTTOM_OF_PLAY_AREA = 923;
const int TOP_OF_PLAY_AREA = 50;
const int LEFT_OF_PLAY_AREA = 47;
const int RIGHT_OF_PLAY_AREA = 980;

int main( int argc, char* args[] )
{
	//reset game attributes
	p1catship.reset();
	gridOfInvaders.setupGrid();
	catshipBullets.reset();

	//Start up SDL and create window
	if( !mysdlcontrol.init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		while(!mysdlcontrol.m_quitneeded)
		{
			mysdlcontrol.readInput();
			mysdlcontrol.drawBackground();

			p1catship.controller();
			catshipBullets.drawAll();

			gridOfInvaders.moveAllInvaders();
			gridOfInvaders.drawAll();

			catshipBullets.fire();

			mysdlcontrol.endOfFrame();
		}
	}

	//Free resources and close SDL
	mysdlcontrol.close();

	return 0;
}







