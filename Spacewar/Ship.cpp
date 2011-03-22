/*
* ============================================================================
*  Name        : Ship from Ship.cpp
*  Part of     : SpaceWar
*  Created     : Sep/3/2010 by Chris, Cloud
*  Version     : 10.9
*  Description :
*  Copyright (c) 2010 Chris Xue, Cloud Xu.
*    Permission is granted to copy, distribute and/or modify this document
*    under the terms of the GNU Free Documentation License, Version 1.2
*    or any later version published by the Free Software Foundation;
*    with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
*    A copy of the license is included in the section entitled "GNU
*    Free Documentation License".
* ============================================================================
*/


#include "Ship.h"
using namespace SpaceWar;


int Ship::displace(int time)
{
	Vector tmp = speed;
	
	//v = v0 + a*t
	speed += acc * time;

	if (speed.len() > SHIP_MAX_SPEED)
	{
		speed.normalize(SHIP_MAX_SPEED);
	}

	//s = (v0 + vt) * t / 2
	tmp += speed;
	tmp *= time;
	tmp /= 2;
	pos += tmp;

	//go outside
	if (pos.x > SCREEN_W) {
		pos.x -= SCREEN_W;
	}
	if (pos.x < 0) {
		pos.x += SCREEN_W;
	}
	if (pos.y > SCREEN_H) {
		pos.y -= SCREEN_H;
	}
	if (pos.y < 0) {
		pos.y += SCREEN_H;
	}

	return 0;
}
