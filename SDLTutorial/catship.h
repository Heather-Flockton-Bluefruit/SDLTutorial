#ifndef CATSHIP_H
#define CATSHIP_H

#include <SDL.h>
#include <stdio.h>
#include <string>


class Catship
{
public:
	static const int CatShipWidth = 150;
	static const int CatShipMiddle = 75;
	static const int CatShipY = 832;

	int m_catShipPosition;

	void reset();
	void controller();

private:
	static const int catShipSpeed = 5;
};

extern Catship p1catship;

#endif