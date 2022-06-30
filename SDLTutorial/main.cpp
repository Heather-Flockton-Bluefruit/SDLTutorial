#include <SDL.h>
#include <stdio.h>
#include <string>

#include "sdlcontrol.h"
#include "catship.h"
#include "invaders.h"
#include "bullets.h"



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

			gridOfInvaders.collisionDetection();

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







