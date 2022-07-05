#ifndef INVADERS_H
#define INVADERS_H

#include <SDL.h>
#include <stdio.h>
#include <string>


class Invader
{
public:
	int m_positionX;
	int m_positionY;
	bool m_onOff;
	void draw();
	int m_whichSprite;

private:

};



class InvaderGrid
{
public:
	static const size_t InvaderWidthHeight = 50;
	static const size_t totalNumberOfInvaders = 50;
	static const size_t GapBetweenInvaders = 20;
	static const size_t NumberOfInvaderRows = 5;
	static const size_t NumberOfInvaderColumns = 10;

	Invader m_invaders[totalNumberOfInvaders];

	void setupGrid();
	void drawAll();
	void moveAllInvaders();
	void collisionDetection();
	
private:
	bool isInCollisionArea( int bulletX, int bulletY, int invaderX, int invaderY, bool bulletOn, bool invaderOn );
	int edgeOfGridFinder( char direction );
};

extern InvaderGrid gridOfInvaders;

#endif