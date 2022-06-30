#include "sdlcontrol.h"
#include "catship.h"
#include "invaders.h"

Catship p1catship;

void Catship::reset()
{
	m_catShipPosition = SDLControl::CentreOfPlayArea - CatShipMiddle;
}


void Catship::controller()
{
	if( (mysdlcontrol.m_rightPressed) && (m_catShipPosition < (SDLControl::RightOfPlayArea - InvaderGrid::GapBetweenInvaders) - CatShipWidth) )
	{
		m_catShipPosition += catShipSpeed;
	}

	if( (mysdlcontrol.m_leftPressed) && (m_catShipPosition > (SDLControl::LeftOfPlayArea + InvaderGrid::GapBetweenInvaders)) )
	{
		m_catShipPosition -= catShipSpeed;
	}

	mysdlcontrol.drawSprite(graphicalElements::catship, m_catShipPosition, CatShipY);
}
