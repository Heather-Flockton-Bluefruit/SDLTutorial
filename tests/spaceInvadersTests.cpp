#include <cassert>
#include "bullets.h"
#include <iostream>

using namespace ::std;

namespace friendly_bullet_tests 
{
	void reset_makes_all_bullets_invisible()
	{
		// Given
		FriendlyBulletMagazine magazine;
		for( size_t i = 0; i < FriendlyBulletMagazine::BulletCount; i++ ) 
		{
			magazine.m_catShipBullet[i].m_onOff = true;
		}

		// When
		magazine.reset();

		// Then
		for( size_t i = 0; i < FriendlyBulletMagazine::BulletCount; i++ ) 
		{
			assert(magazine.m_catShipBullet[i].m_onOff == false);
		}
	}
}

int main( int argc, char* args[] )
{
	friendly_bullet_tests::reset_makes_all_bullets_invisible();
	cout << "All tests passed!" << endl;
	string stuff;
	cin >> stuff;
	return 0;
}
