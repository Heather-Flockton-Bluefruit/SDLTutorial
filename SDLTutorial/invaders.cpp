#include "sdlcontrol.h"
#include "catship.h"
#include "invaders.h"

InvaderGrid gridOfInvaders;

void Invader::draw()
{
	if( m_onOff )
	{
		mysdlcontrol.drawSprite(m_whichSprite, m_positionX, m_positionY);
	}
}


void InvaderGrid::setupGrid()
{
	int newRow;
	int newColumn;

	int invader = 0;
	int sprite[] = {4, 2, 2, 3, 3};

	int invaderX = 175;
	int invaderY = 200;

	for( int rowCounter = 0; rowCounter < 5; rowCounter++ )
	{
		newRow = (rowCounter * 70);

		for( int columnCounter = 0; columnCounter < 10; columnCounter++ )
		{
			newColumn = (columnCounter * 70);

			m_invaders[invader].m_positionX = invaderX + newColumn;
			m_invaders[invader].m_positionY = invaderY + newRow;

			m_invaders[invader].m_onOff = true;

			m_invaders[invader].m_whichSprite = sprite[rowCounter];
			
			invader++;
		}
	}
}


void InvaderGrid::drawAll()
{
	for( int numberOfInvader = 0; numberOfInvader < 50; numberOfInvader++ )
	{
		m_invaders[numberOfInvader].draw();
	}
}

