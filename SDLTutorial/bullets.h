#ifndef BULLETS_H
#define BULLETS_H

#include <SDL.h>
#include <stdio.h>
#include <string>


class FriendlyBullet
{
public:
	static const int bulletWidth = 5;
	static const int bulletHeight = 25;

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
	static const size_t BulletCount = 5;
	static const int bulletStartingY = 832;
	static const int bulletSpeed = 3;


	FriendlyBullet m_catShipBullet[BulletCount];

	void reset();
	void drawAll();
	void fire();

private:

};


extern FriendlyBulletMagazine catshipBullets;

#endif