#include "sdlcontrol.h"
#include "catship.h"

Catship p1catship;

void Catship::reset()
{
	m_catShipPosition = 437;
}

void Catship::controller()
{
	if( (mysdlcontrol.m_rightPressed) && (m_catShipPosition < 824) )
	{
		m_catShipPosition += 5;
	}

	if( (mysdlcontrol.m_leftPressed) && (m_catShipPosition > 50) )
	{
		m_catShipPosition -= 5;
	}

	mysdlcontrol.drawSprite(1, m_catShipPosition, 848);
}
