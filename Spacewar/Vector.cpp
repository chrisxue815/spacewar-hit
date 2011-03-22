/*
* ============================================================================
*  Name        : Vector from Vector.cpp
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


#include "Vector.h"
using namespace SpaceWar;


Vector::Vector(double x, double y) : x(x), y(y)
{
}

Vector::Vector() : x(0), y(0)
{
}

Vector Vector::operator +(Vector & v)
{
	Vector sumV(x + v.x, y + v.y);
	return sumV;
}

Vector Vector::operator -(Vector & v)
{
	Vector sumV(x - v.x, y - v.y);
	return sumV;
}

Vector Vector::operator *(double p)
{
	Vector v(x * p, y * p);
	return v;
}

Vector Vector::operator /(double p)
{
	Vector v(x / p, y / p);
	return v;
}

Vector & Vector::operator +=(Vector & v)
{
	x += v.x;
	y += v.y;

	return *this;
}

Vector & Vector::operator -=(Vector & v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

Vector & Vector::operator *=(double p)
{
	x *= p;
	y *= p;

	return *this;
}

Vector & Vector::operator /=(double p)
{
	x /= p;
	y /= p;

	return *this;
}

bool Vector::operator ==(Vector & v)
{
	if ( abs(x - v.x) < PRECISION && abs(y - v.y) < PRECISION ) {
		return true;
	}
	else {
		return false;
	}
}

Vector & Vector::normalize(double len)
{
	double lenOrg = this->len();

	if (lenOrg != 0) {
		double rate = len / lenOrg;
		x = x * rate;
		y = y * rate;
	}

	return *this;
}

double Vector::len()
{
	return sqrt(x * x + y * y);
}

double Vector::dot(Vector & v)
{
	return (x * v.x + y * v.y);
}

double Vector::angleBetween(Vector & v)
{
	double len1 = len();
	double len2 = v.len();

	if (len1 != 0 && len2 != 0) {
		return acos( dot(v) / (len1 * len2) );
	}
	else {
		return 0;
	}
}

double Vector::angleBetween(double x, double y)
{
	double len1 = len();
	double len2 = sqrt(x * x + y * y);

	if (len1 != 0 && len2 != 0) {
		return acos( (this->x * x + this->y * y) / (len1 * len2) );
	}
	else {
		return 0;
	}
}

double Vector::angle()
{
	//angle between x-axis
	double len1 = len();

	if (len1 == 0) {
		return 0;
	}

	double angle = acos( x / len1 );
	if (y < 0) {
		angle = -angle;
	}
	return angle;
}

double Vector::dist(Vector & v)
{
	Vector v2 = *this - v;
	return v2.len();
}
