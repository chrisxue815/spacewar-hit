/*
* ============================================================================
*  Name        : Vector from Vector.h
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


#include "Settings.h"
#include <cmath>
using namespace std;
using namespace SpaceWar;


namespace SpaceWar
{
	class Vector
	{
	public:
		Vector();
		Vector(double x, double y);

		Vector operator +(Vector & v);
		Vector operator -(Vector & v);
		Vector operator *(double p);
		Vector operator /(double p);
		Vector & operator +=(Vector & v);
		Vector & operator -=(Vector & v);
		Vector & operator *=(double p);
		Vector & operator /=(double p);
		bool operator ==(Vector & v);

		Vector & normalize(double len = 1);

		double len();
		double dot(Vector & v);
		double angleBetween(Vector & v);  //radium
		double angleBetween(double x, double y);  //radium
		double angle();  //angle between x-axis
		double dist(Vector & v);  //the length of (v1-v2)

	public:
		double x, y;
	};
}
