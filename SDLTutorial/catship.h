#ifndef CATSHIP_H
#define CATSHIP_H

#include <SDL.h>
#include <stdio.h>
#include <string>


class Catship
{
public:
	int m_catShipPosition;

	void reset();
	void controller();

private:

};

extern Catship p1catship;

#endif