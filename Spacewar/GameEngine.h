/*
* ============================================================================
*  Name        : GameEngine from GameEngine.h
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


#include "Ship.h"
#include "Bullet.h"
#include <allegro.h>
#include <list>
#include <cmath>
#include <cstdlib>
using namespace std;
using namespace SpaceWar;


namespace SpaceWar
{
	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();
		int loadSrc(char *parentPath);
		int init();
		int exec();
		int restart();
		int pause();

	protected:
		int initData();

		void wndProc();
		void calc();
		void draw();

		int initBgStar();
		int drawBgStar();

		void addBullet(Vector & pos, Vector look);

	protected:
		Ship ship1;
		Ship ship2;
		Vector starPos;
		list<Bullet> bullet;

		// pointer to data file
		BITMAP * res[RES_SIZE];
		// pointer to a sprite buffer, where sprite will be drawn
		BITMAP *buffer;
		//TODO
		char *parentPath;
		//TODO
		bool run;
		bool lastDraw;
		//TODO
		bool paused;
		bool gameover;
		//TODO
		list<Vector> bgStarPos;
		void (*oldHandler)(int);

		MIDI *gameMusic;
	};
}
