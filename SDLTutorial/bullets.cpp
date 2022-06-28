#include "sdlcontrol.h"
#include "bullets.h"
#include "catship.h"

#include <iostream>
#include <string>
using namespace std;

FriendlyBulletMagazine catshipBullets;

const int totalFriendlyBullets = 5;
const int centerOfCatship = 70;
const int bulletStartingY = 832;
const int bulletSpeed = 3;

int currentFiringPosition = 0;
int currentBullet = 0;
bool bulletOn = true;



void FriendlyBullet::draw()
{
	if( m_onOff )
	{
		mysdlcontrol.drawSprite(5, m_bulletPositionX, m_bulletPositionY);
	}
}


void FriendlyBulletMagazine::reset()
{
	for( int i = 0; i < totalFriendlyBullets; i++ )
	{
		m_catShipBullet[i].m_onOff = false;
		cout << "bullet " << i << " is " << m_catShipBullet[i].m_onOff << endl;
	}
}


void FriendlyBulletMagazine::drawAll()
{
	for( int i = 0; i < totalFriendlyBullets; i++ )
	{
		const int topOfPlayArea = 50;

		if( m_catShipBullet[i].m_bulletPositionY <= topOfPlayArea )
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
		
		for( int whichBullet = 0; whichBullet < totalFriendlyBullets; whichBullet++ )
		{
			if( m_catShipBullet[whichBullet].m_onOff == false )
			{
				currentBullet = whichBullet;
				m_catShipBullet[currentBullet].m_bulletPositionY = bulletStartingY;
				m_catShipBullet[currentBullet].m_bulletPositionX = currentFiringPosition + centerOfCatship;
				m_catShipBullet[currentBullet].m_onOff = true;
				whichBullet = totalFriendlyBullets;
			}
		}
	}

	//rapid fire
	/*if( mysdlcontrol.m_spaceHeld )
	{
		mysdlcontrol.drawSprite(6, 500, 500);

		currentFiringPosition = p1catship.m_catShipPosition;
		
		for( int whichBullet = 0; whichBullet < totalFriendlyBullets; whichBullet++ )
		{
			if( m_catShipBullet[whichBullet].m_onOff == false )
			{
				currentBullet = whichBullet;
				whichBullet = totalFriendlyBullets;
			}
			
			cout << "whichBullet " << whichBullet << endl;
			cout << "currentBullet " << currentBullet << endl;
		}

		m_catShipBullet[currentBullet].m_bulletPositionY = bulletStartingY;
		m_catShipBullet[currentBullet].m_bulletPositionX = currentFiringPosition + centerOfCatship;
		m_catShipBullet[currentBullet].m_onOff = true;
	}*/
}

