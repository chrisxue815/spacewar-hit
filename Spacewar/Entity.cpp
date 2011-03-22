/*
* ============================================================================
*  Name        : Entity from Entity.cpp
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


#include "Entity.h"
using namespace SpaceWar;


Entity::Entity()
{
}

Entity::Entity(Vector & pos, double angle, Vector & speed)
	: pos(pos), angle(angle), speed(speed)
{
}

Vector Entity::getPos()
{
	return pos;
}

double Entity::getPosX()
{
	return pos.x;
}

double Entity::getPosY()
{
	return pos.y;
}

double Entity::getAngle()
{
	return angle;
}

Vector Entity::look()
{
	Vector look(cos(angle), sin(angle));
	return look;
}

double Entity::dist(Entity & e)
{
	return this->pos.dist(e.pos);
}

double Entity::dist(Vector & pos)
{
	return this->pos.dist(pos);
}

void Entity::spin(double radium)
{
	angle += radium;
	int quotient = (int)(angle/PI/2);
	angle -= quotient*PI*2;
}

int Entity::displace(int time)
{
	Vector tmp = speed;
	
	//v = v0 + a*t
	speed += acc * time;

	//s = (v0 + vt) * t / 2
	tmp += speed;
	tmp *= time;
	tmp /= 2;
	pos += tmp;

	return 0;
}
