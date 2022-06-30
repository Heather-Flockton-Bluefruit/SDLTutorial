#include "sdlcontrol.h"
#include "bullets.h"
#include "catship.h"

#include <iostream>
#include <string>
using namespace std;

FriendlyBulletMagazine catshipBullets;

int currentFiringPosition = 0;
int currentBullet = 0;


void FriendlyBullet::draw()
{
	if( m_onOff )
	{
		mysdlcontrol.drawSprite(graphicalElements::friendlyBullet, m_bulletPositionX, m_bulletPositionY);
	}
}


void FriendlyBulletMagazine::reset()
{
	for( int i = 0; i < BulletCount; i++ )
	{
		m_catShipBullet[i].m_onOff = false;
		cout << "bullet " << i << " is " << m_catShipBullet[i].m_onOff << endl;
	}
}


void FriendlyBulletMagazine::drawAll()
{
	for( int i = 0; i < BulletCount; i++ )
	{
		if( m_catShipBullet[i].m_bulletPositionY <= SDLControl::TopOfPlayArea )
		{
			m_catShipBullet[i].m_onOff = false;
		}

		m_catShipBullet[i].draw();
		m_catShipBullet[i].m_bulletPositionY -= bulletSpeed;
	}
}


void FriendlyBulletMagazine::fire()
{
	//one bullet at a time
	if( mysdlcontrol.m_spacePressed )
	{
		currentFiringPosition = p1catship.m_catShipPosition;
		
		for( int whichBullet = 0; whichBullet < BulletCount; whichBullet++ )
		{
			if( m_catShipBullet[whichBullet].m_onOff == false )
			{
				currentBullet = whichBullet;
				m_catShipBullet[currentBullet].m_bulletPositionY = Catship::CatShipY - FriendlyBullet::bulletHeight;
				m_catShipBullet[currentBullet].m_bulletPositionX = currentFiringPosition + (Catship::CatShipMiddle - FriendlyBullet::bulletWidth);
				m_catShipBullet[currentBullet].m_onOff = true;
				whichBullet = BulletCount;
			}
		}
	}

	//rapid fire
	/*if( mysdlcontrol.m_spaceHeld )
	{
		mysdlcontrol.drawSprite(6, 500, 500);

		currentFiringPosition = p1catship.m_catShipPosition;
		
		for( int whichBullet = 0; whichBullet < BulletCount; whichBullet++ )
		{
			if( m_catShipBullet[whichBullet].m_onOff == false )
			{
				currentBullet = whichBullet;
				whichBullet = BulletCount;
			}
			
			cout << "whichBullet " << whichBullet << endl;
			cout << "currentBullet " << currentBullet << endl;
		}

		m_catShipBullet[currentBullet].m_bulletPositionY = bulletStartingY;
		m_catShipBullet[currentBullet].m_bulletPositionX = currentFiringPosition + centerOfCatship;
		m_catShipBullet[currentBullet].m_onOff = true;
	}*/
}

