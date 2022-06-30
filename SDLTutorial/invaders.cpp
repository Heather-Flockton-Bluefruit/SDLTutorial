#include "sdlcontrol.h"
#include "catship.h"
#include "bullets.h"
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
	int invaderStartPositionX = 175;
	int invaderStartPositionY = 200;

	int sprite[] = {graphicalElements::jellycatInvader,
					graphicalElements::mediumCatInvader, 
					graphicalElements::mediumCatInvader, 
					graphicalElements::meowthInvader, 
					graphicalElements::meowthInvader,
				   };

	for( int rowCounter = 0; rowCounter < NumberOfInvaderRows; rowCounter++ )
	{
		newRow = (rowCounter * (InvaderWidthHeight + GapBetweenInvaders));

		for( int columnCounter = 0; columnCounter < NumberOfInvaderColumns; columnCounter++ )
		{
			newColumn = (columnCounter * (InvaderWidthHeight + GapBetweenInvaders));

			m_invaders[invader].m_positionX = invaderStartPositionX + newColumn;
			m_invaders[invader].m_positionY = invaderStartPositionY + newRow;

			m_invaders[invader].m_onOff = true;

			m_invaders[invader].m_whichSprite = sprite[rowCounter];
			
			invader++;
		}
	}
}


void InvaderGrid::drawAll()
{
	for( int whichInvader = 0; whichInvader < totalNumberOfInvaders; whichInvader++ )
	{
		m_invaders[whichInvader].draw();
	}
}


int stepIncrement = 1;

void InvaderGrid::moveAllInvaders()
{
	if( m_invaders[9].m_positionX > (SDLControl::RightOfPlayArea - InvaderWidthHeight) - 20 )
	{
		stepIncrement = -stepIncrement;
	}

	if( m_invaders[0].m_positionX < SDLControl::LeftOfPlayArea + 20 )
	{
		stepIncrement = -stepIncrement;
	}

	for( int invader = 0; invader < totalNumberOfInvaders; invader++ )
	{
		m_invaders[invader].m_positionX += stepIncrement;
	}

}


void InvaderGrid::collisionDetection()
{
	for( int numberOfInvader = 0; numberOfInvader < totalNumberOfInvaders; numberOfInvader++ )
	{
		for( int numberOfBullet = 0; numberOfBullet < FriendlyBulletMagazine::BulletCount; numberOfBullet++ )
		{
			bool collision = isInCollisionArea(catshipBullets.m_catShipBullet[numberOfBullet].m_bulletPositionX,
											   catshipBullets.m_catShipBullet[numberOfBullet].m_bulletPositionY,
											   m_invaders[numberOfInvader].m_positionX,
											   m_invaders[numberOfInvader].m_positionY,
											   catshipBullets.m_catShipBullet[numberOfBullet].m_onOff,
											   m_invaders[numberOfInvader].m_onOff);
			
			if( collision )
			{

				catshipBullets.m_catShipBullet[numberOfBullet].m_onOff = false;
				m_invaders[numberOfInvader].m_onOff = false;
			}
		}
		
	}
}


bool InvaderGrid::isInCollisionArea(int bulletX, int bulletY, int invaderX, int invaderY, bool bulletOn, bool invaderOn)
{
	if( invaderOn && bulletOn &&
		((bulletX > invaderX ) && (bulletX < invaderX + InvaderWidthHeight)) && 
		((bulletY > invaderY ) && (bulletY < invaderY + InvaderWidthHeight))
		)
		{
			return true;
		}

	return false;
}