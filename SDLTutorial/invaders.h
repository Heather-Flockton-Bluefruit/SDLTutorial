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
	Invader m_invaders[50];
	void setupGrid();
	//void moveAllInvaders();
	//void addInvaderToList();
	//void checkCollisions();
	void drawAll();
private:

};

extern InvaderGrid gridOfInvaders;

#endif