#ifndef BULLETS_H
#define BULLETS_H

#include <SDL.h>
#include <stdio.h>
#include <string>


class FriendlyBullet
{
public:
	bool m_onOff;
	int m_bulletPositionY;
	int m_bulletPositionX;

	void draw();
	void controller();

private:

};




class FriendlyBulletMagazine
{
public:
	FriendlyBullet m_catShipBullet[5];

	void reset();
	void drawAll();
	void fire();

	
private:

};


extern FriendlyBulletMagazine catshipBullets;

#endif