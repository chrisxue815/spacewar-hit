/*
* ============================================================================
*  Name        : Ship from Ship.h
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


#pragma once


#include "Entity.h"
using namespace std;


namespace SpaceWar
{
	class Ship : public Entity
	{
	public:
		Ship() : Entity()
		{
		}
		Ship(Vector & pos, double angle, Vector & speed) : Entity(pos, angle, speed)
		{
			health = INIT_HEALTH;
			bulletCD = 0;
		}

		int displace(int time);

		int health;
		int bulletCD;
	};
}
