/*
*;
*  Name        : Settings from Settings.h
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
*;
*/


#pragma once


#include <allegro.h>


namespace SpaceWar
{
	void initSettings();


	// main engine
	extern const int RES_WIDTH;
	extern const int RES_HEIGHT;

	extern const double PRECISION;
	extern const double PI;
	extern const double ANGLE_RATE;
	
	extern const char KEY_NAME[][12];
	extern const int KEY_NULL;

	// game engine

#define GAME_KEY_NUM 11

	extern int KEY[GAME_KEY_NUM];
	enum KeyIndex
	{
		SHIP1_LEFT   = 0,    SHIP1_RIGHT = 1,    SHIP1_FIRE = 2,    SHIP1_RUSH = 3,
		SHIP2_LEFT   = 4,    SHIP2_RIGHT = 5,    SHIP2_FIRE = 6,    SHIP2_RUSH = 7,
		GAME_RESTART = 8,    GAME_PAUSE  = 9,    GAME_ESC = 10
	};

	extern int SHIP1_INIT_POS_X;
	extern int SHIP2_INIT_POS_X;

	extern const int STAR_X;
	extern const int STAR_Y;

	extern int SHIP_CENTER_X;
	extern int SHIP_CENTER_Y;
	extern int BULLET_CENTER_X;
	extern int BULLET_CENTER_Y;

	extern const int INIT_HEALTH;
	extern const int HEALTH_TXT_X;
	extern const int HEALTH_TXT_Y;

	extern const double SPIN_LEFT_SPEED;
	extern const double SPIN_RIGHT_SPEED;
	extern const int DELTA_TIME;
	extern const int BULLET_CD;

	extern const double STAR_MASS;
	extern const double SHIP_ACC;
	extern const double SHIP_MAX_SPEED;
	extern const double BULLET_SPEED;

#define RES_SIZE 6

	extern const char RES_NAME[RES_SIZE][50];
	extern const int FRAME_SHIP1;
	extern const int FRAME_SHIP2;
	extern const int FRAME_BULLET;
	extern const int FRAME_STAR;
	extern const int FRAME_BGSTAR;
	extern const int FRAME_BGSTAR_SHINING;
	
	extern const double COLLISION_DIST;
	extern const double POS_DELTA;

	// menu engine

	extern const int MENU_KEY_UP;
	extern const int MENU_KEY_DOWN;
	extern const int MENU_KEY_LEFT;
	extern const int MENU_KEY_RIGHT;
	extern const int MENU_KEY_ENTER;
	extern const int MENU_KEY_ESC;

#define MENU_ITEM_NUM 5

	extern const int MENU_ITEM_X;
	extern const int MENU_RESUME_Y;
	extern const int MENU_NEWGAME_Y;
	extern const int MENU_OPTIONS_Y;
	extern const int MENU_DEVMODE_Y;
	extern const int MENU_EXIT_Y;

#define INFO_ITEM 4
#define MAX_CHAR 50
	extern const char INFORMATION[INFO_ITEM][MAX_CHAR];

	// change key

#define CHGKEY_MENU_ITEM_NUM 11
#define KEYTABLE_INDEX_NUM 10

	extern const int CHGKEY_MENU_KEYNAME_X;
	extern const int CHGKEY_MENU_KEY_X;
	extern const int CHGKEY_MENU_PLAYER_X;
	extern const int CHGKEY_MENU_Y [CHGKEY_MENU_ITEM_NUM];

#define CHGKEY_NUM 10
	extern const char CHGKEY_NAME [CHGKEY_NUM][16];
	extern const int CHGKEY_INDEX [CHGKEY_NUM];
	extern const char CONFIG_FILENAME[];

	// config

#define CONFIG_NUM 10
	extern const char CONFIG_NAME [CHGKEY_NUM][16];
	extern const int CONFIG_INDEX [CHGKEY_NUM];
}
