/*
* ============================================================================
*  Name        : Settings from Settings.cpp
*  Part of     : SpaceWar
*  Created     : Nov/6/2010 by Chris, Cloud
*  Version     : 10.11
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


#include "Settings.h"
using namespace SpaceWar;


void SpaceWar::initSettings()
{
	SpaceWar:: KEY[SHIP1_LEFT] = KEY_Z;
	SpaceWar:: KEY[SHIP1_RIGHT] = KEY_X;
	SpaceWar:: KEY[SHIP1_FIRE] = KEY_C;
	SpaceWar:: KEY[SHIP1_RUSH] = KEY_V;

	SpaceWar:: KEY[SHIP2_LEFT] = KEY_N;
	SpaceWar:: KEY[SHIP2_RIGHT] = KEY_M;
	SpaceWar:: KEY[SHIP2_FIRE] = KEY_COMMA;
	SpaceWar:: KEY[SHIP2_RUSH] = KEY_STOP;

	SpaceWar:: KEY[GAME_RESTART] = KEY_F5;
	SpaceWar:: KEY[GAME_PAUSE] = KEY_SPACE;
	SpaceWar:: KEY[GAME_ESC] = KEY_ESC;
}

// main engine
const int SpaceWar:: RES_WIDTH = 800;
const int SpaceWar:: RES_HEIGHT = 600;

const double SpaceWar:: PRECISION = 0.000001;
const double SpaceWar:: PI = 3.14;
const double SpaceWar:: ANGLE_RATE = (double)255 / 2 / PI;

const char SpaceWar:: KEY_NAME[][12] =
{
   "___________",  "A",            "B",            "C",  // 0-3
   "D",            "E",            "F",            "G",
   "H",            "I",            "J",            "K",
   "L",            "M",            "N",            "O",
   "P",            "Q",            "R",            "S",
   "T",            "U",            "V",            "W",  // 20-23
   "X",            "Y",            "Z",            "0",
   "1",            "2",            "3",            "4",
   "5",            "6",            "7",            "8",
   "9",            "0_PAD",        "1_PAD",        "2_PAD",
   "3_PAD",        "4_PAD",        "5_PAD",        "6_PAD",  // 40-43
   "7_PAD",        "8_PAD",        "9_PAD",        "F1",
   "F2",           "F3",           "F4",           "F5",
   "F6",           "F7",           "F8",           "F9",
   "F10",          "F11",          "F12",          "ESC",
   "TILDE",        "MINUS",        "EQUALS",       "BACKSPACE",  // 60-63
   "TAB",          "OPENBRACE",    "CLOSEBRACE",   "ENTER",
   "COLON",        "QUOTE",        "BACKSLASH",    "BACKSLASH2",
   "COMMA",        "STOP",         "SLASH",        "SPACE",
   "INSERT",       "DEL",          "HOME",         "END",
   "PGUP",         "PGDN",         "LEFT",         "RIGHT",  // 80-83
   "UP",           "DOWN",         "SLASH_PAD",    "ASTERISK",
   "MINUS_PAD",    "PLUS_PAD",     "DEL_PAD",      "ENTER_PAD",
   "PRTSCR",       "PAUSE",        "ABNT_C1",      "YEN",
   "KANA",         "CONVERT",      "NOCONVERT",    "AT",
   "CIRCUMFLEX",   "COLON2",       "KANJI",        "EQUALS_PAD",
   "BACKQUOTE",    "SEMICOLON",    "COMMAND",      "UNKNOWN1",
   "UNKNOWN2",     "UNKNOWN3",     "UNKNOWN4",     "UNKNOWN5",
   "UNKNOWN6",     "UNKNOWN7",     "UNKNOWN8",     "LSHIFT",
   "RSHIFT",       "LCONTROL",     "RCONTROL",     "ALT",
   "ALTGR",        "LWIN",         "RWIN",         "MENU",
   "SCRLOCK",      "NUMLOCK",      "CAPSLOCK",     "MAX"
};

const int SpaceWar:: KEY_NULL = 0;

// game engine
int SpaceWar:: KEY[GAME_KEY_NUM];

int SpaceWar:: SHIP1_INIT_POS_X = 50;
int SpaceWar:: SHIP2_INIT_POS_X = RES_WIDTH - SHIP1_INIT_POS_X;

const int SpaceWar:: STAR_X = RES_WIDTH / 2 - 16;
const int SpaceWar:: STAR_Y = RES_HEIGHT / 2 - 16;

int SpaceWar:: SHIP_CENTER_X;
int SpaceWar:: SHIP_CENTER_Y;
int SpaceWar:: BULLET_CENTER_X;
int SpaceWar:: BULLET_CENTER_Y;

const int SpaceWar:: INIT_HEALTH = 3;
const int SpaceWar:: HEALTH_TXT_X = 60;
const int SpaceWar:: HEALTH_TXT_Y = 30;

const double SpaceWar:: SPIN_LEFT_SPEED = -0.01;
const double SpaceWar:: SPIN_RIGHT_SPEED = 0.01;
const int SpaceWar:: DELTA_TIME = 1;
const int SpaceWar:: BULLET_CD = 100;

const double SpaceWar:: STAR_MASS = 70;
const double SpaceWar:: SHIP_ACC = 0.1;
const double SpaceWar:: SHIP_MAX_SPEED = 1;
const double SpaceWar:: BULLET_SPEED = 3;

const char SpaceWar:: RES_NAME[RES_SIZE][50] = {
	"content\\texture\\ship1.bmp",
	"content\\texture\\ship2.bmp",
	"content\\texture\\bullet.bmp",
	"content\\texture\\star.bmp",
	"content\\texture\\bgStar.bmp",
	"content\\texture\\bgStarShining.bmp"
};
const int SpaceWar:: FRAME_SHIP1 = 0;
const int SpaceWar:: FRAME_SHIP2 = 1;
const int SpaceWar:: FRAME_BULLET = 2;
const int SpaceWar:: FRAME_STAR = 3;
const int SpaceWar:: FRAME_BGSTAR = 4;
const int SpaceWar:: FRAME_BGSTAR_SHINING = 5;

const double SpaceWar:: COLLISION_DIST = 10;
const double SpaceWar:: POS_DELTA = 20;

// menu
const int SpaceWar:: MENU_KEY_UP = KEY_UP;
const int SpaceWar:: MENU_KEY_DOWN = KEY_DOWN;
const int SpaceWar:: MENU_KEY_LEFT = KEY_LEFT;
const int SpaceWar:: MENU_KEY_RIGHT = KEY_RIGHT;
const int SpaceWar:: MENU_KEY_ENTER = KEY_ENTER;
const int SpaceWar:: MENU_KEY_ESC = KEY_ESC;

const int SpaceWar:: MENU_ITEM_X = RES_WIDTH / 2;
const int SpaceWar:: MENU_RESUME_Y = 250;
const int SpaceWar:: MENU_NEWGAME_Y = 300;
const int SpaceWar:: MENU_OPTIONS_Y = 350;
const int SpaceWar:: MENU_DEVMODE_Y = 400;
const int SpaceWar:: MENU_EXIT_Y = 480;

const char SpaceWar:: INFORMATION[INFO_ITEM][MAX_CHAR] = 
{	
	"Copyright (c) 2010 Chris Xue, Cloud Xu.",
	"Contact us:",
	"chrisxue815@gmail.com",
	"cloudxunuo@gmail.com"
};


// change key
const int SpaceWar:: CHGKEY_MENU_KEYNAME_X = 300;
const int SpaceWar:: CHGKEY_MENU_KEY_X = CHGKEY_MENU_KEYNAME_X + 150;
const int SpaceWar:: CHGKEY_MENU_PLAYER_X = 200;
const int SpaceWar:: CHGKEY_MENU_Y [CHGKEY_MENU_ITEM_NUM] =
{
	100, 130, 160, 190, 250, 280, 310, 330, 390, 420, 480
};

const char SpaceWar:: CHGKEY_NAME [CHGKEY_NUM][16] =
{
	"Left",      "Right",
	"Fire",      "Rush",
	"Left",      "Right",
	"Fire",      "Rush",
	"Game Restart",    "Game Pause"
};

const int SpaceWar:: CHGKEY_INDEX [CHGKEY_NUM] =
{
	SHIP1_LEFT,      SHIP1_RIGHT,
	SHIP1_FIRE,      SHIP1_RUSH,
	SHIP2_LEFT,      SHIP2_RIGHT,
	SHIP2_FIRE,      SHIP2_RUSH,
	GAME_RESTART,    GAME_PAUSE
};

const char SpaceWar:: CONFIG_FILENAME[] = "spacewar.ini";

// config

const char SpaceWar:: CONFIG_NAME [CHGKEY_NUM][16] =
{
	"PLAYER_1_LEFT",      "PLAYER_1_RIGHT",
	"PLAYER_1_FIRE",      "PLAYER_1_RUSH",
	"PLAYER_2_LEFT",      "PLAYER_2_RIGHT",
	"PLAYER_2_FIRE",      "PLAYER_2_RUSH",
	"GAME_RESTART",       "GAME_PAUSE"
};

const int SpaceWar:: CONFIG_INDEX [CHGKEY_NUM] =
{
	SHIP1_LEFT,      SHIP1_RIGHT,
	SHIP1_FIRE,      SHIP1_RUSH,
	SHIP2_LEFT,      SHIP2_RIGHT,
	SHIP2_FIRE,      SHIP2_RUSH,
	GAME_RESTART,    GAME_PAUSE
};
