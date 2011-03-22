/*
* ============================================================================
*  Name        : GameEngine from GameEngine.cpp
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


#include "GameEngine.h"
using namespace SpaceWar;

#define TRUE -1
#define FALSE 0
bool isKeyPressed[GAME_KEY_NUM];
void keypressHandler(int scancode);


GameEngine::GameEngine()
{
	/* allocate the memory buffer */
	buffer = create_bitmap(RES_WIDTH, RES_HEIGHT);
}

GameEngine::~GameEngine()
{
	for (int i=0; i<RES_SIZE; i++) {
		destroy_bitmap(res[i]);
	}
	destroy_bitmap(buffer);
	keyboard_lowlevel_callback = oldHandler;
	destroy_midi(gameMusic);
}

int GameEngine::loadSrc(char *parentPath)
{
	char resPath[256];

	/* loads bmps */
	for (int i=0; i<RES_SIZE; i++) 
	{
		replace_filename(resPath, parentPath, (const char *)RES_NAME[i],
			sizeof(resPath));
		res[i] = load_bitmap(resPath, desktop_palette);
		if (!res[i]) {
			set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
			allegro_message("Error loading %s!\n", resPath);
			return 1;
		}
	}

	return 0;
}

int GameEngine::exec()
{
	//play game music
	play_midi(gameMusic, TRUE);


	run = true;
	lastDraw = false;

	draw();

	do
	{
		wndProc();

		if (gameover == true) {
			if (lastDraw == false) {
				lastDraw = true;
				draw();
			}
		}
		else if (paused == false) {
			calc();
			draw();
		}
		rest(DELTA_TIME);
	}
	while (run);

	return 0;
}

int GameEngine::init()
{
	/**/
	LOCK_FUNCTION(keypressHandler);
	oldHandler = keyboard_lowlevel_callback;
	keyboard_lowlevel_callback = keypressHandler;

	/**/
	for (int i=0; i<GAME_KEY_NUM; isKeyPressed[i++]=false);

	/* init star position */
	starPos = Vector(SCREEN_W / 2, SCREEN_H / 2);

	/**/
	SHIP_CENTER_X = res[FRAME_SHIP1]->w / 2;
	SHIP_CENTER_Y = res[FRAME_SHIP1]->h / 2;
	BULLET_CENTER_X = res[FRAME_BULLET]->w / 2;
	BULLET_CENTER_Y = res[FRAME_BULLET]->h / 2;

	initData();

	// load game music
	gameMusic = load_midi("content\\sound\\game.mid");
    if (!gameMusic)
		allegro_message("Couldn't load game background music!");

	return 0;
}

int GameEngine::initData()
{
	// init ship
	ship1 = Ship(Vector(SHIP1_INIT_POS_X, SCREEN_H / 2), 
		0, Vector(0, 0));
	ship2 = Ship(Vector(SHIP2_INIT_POS_X, SCREEN_H / 2), 
		PI, Vector(0, 0));

	// init background star
	initBgStar();

	paused = false;
	gameover = false;
	lastDraw = false;

	return 0;
}

void GameEngine::wndProc()
{
	static bool keyPauseUp = true;

	if (paused == false && gameover == false)
	{
		// ship 1 turned left
		if (isKeyPressed[SHIP1_LEFT]) {
			ship1.spin(SPIN_LEFT_SPEED);
		}

		// ship 1 turned right
		if (isKeyPressed[SHIP1_RIGHT]) {
			ship1.spin(SPIN_RIGHT_SPEED);
		}

		// ship 1 fired
		if (isKeyPressed[SHIP1_FIRE]) {
			if (ship1.bulletCD == 0) {
				addBullet(ship1.getPos(), ship1.look());
				ship1.bulletCD = BULLET_CD;
			}
		}

		// ship 1 rushed
		if (isKeyPressed[SHIP1_RUSH]) {
			double accAmount = SHIP_ACC;
			ship1.acc = ship1.look();
			ship1.acc.normalize(accAmount);
		}

		// ship 2 turned left
		if (isKeyPressed[SHIP2_LEFT]) {
			ship2.spin(SPIN_LEFT_SPEED);
		}

		// ship 2 turned right
		if (isKeyPressed[SHIP2_RIGHT]) {
			ship2.spin(SPIN_RIGHT_SPEED);
		}

		// ship 2 fired
		if (isKeyPressed[SHIP2_FIRE]) {
			if (ship2.bulletCD == 0) {
				addBullet(ship2.getPos(), ship2.look());
				ship2.bulletCD = BULLET_CD;
			}
		}

		// ship 2 rushed
		if (isKeyPressed[SHIP2_RUSH]) {
			double accAmount = SHIP_ACC;
			ship2.acc = ship2.look();
			ship2.acc.normalize(accAmount);
		}
	}

	// restart
	if (isKeyPressed[GAME_RESTART]) {
		restart();
	}

	// pause
	if (isKeyPressed[GAME_PAUSE]) {
		if (keyPauseUp == true) {
			pause();
			keyPauseUp = false;
		}
	}
	else {
		keyPauseUp = true;
	}

	// exit
	if (isKeyPressed[GAME_ESC]) {
		run = false;
		return;
	}
}

void GameEngine::calc()
{
	/* to store distance */
	double dist;

	/* ship1 displacement */
	if ((dist = ship1.dist(starPos)) > COLLISION_DIST) {
		Vector displace = starPos - ship1.getPos();
		double accAmount = STAR_MASS / pow(dist, 2);
		displace.normalize(accAmount);
		ship1.acc += displace;
		ship1.displace(DELTA_TIME);
		ship1.acc = Vector(0, 0);
	}
	else {
		gameover = true;
	}

	/* ship2 displacement */
	if ((dist = ship2.dist(starPos)) > COLLISION_DIST) {
		Vector displace = starPos - ship2.getPos();
		double accAmount = STAR_MASS / pow(dist, 2);
		displace.normalize(accAmount);
		ship2.acc += displace;
		ship2.displace(DELTA_TIME);
		ship2.acc = Vector(0, 0);
	}
	else {
		gameover = true;
	}

	/* bullet */
	for (list<Bullet>::iterator it = bullet.begin(); it != bullet.end(); )
	{
		/* ship 1 damaged */
		if (ship1.dist((*it).pos) <= COLLISION_DIST)
		{
			if (ship1.health > 0)
			{
				ship1.health--;
				if (ship1.health == 0) {
					gameover = true;
				}
			}

			/* delete the bullet */
			list<Bullet>::iterator tmp = it;
			it++;
			bullet.erase(tmp);
			continue;
		}

		/* ship 2 damaged */
		if (ship2.dist((*it).pos) <= COLLISION_DIST)
		{
			if (ship2.health > 0)
			{
				ship2.health--;
				if (ship2.health == 0) {
					gameover = true;
				}
			}

			/* delete the bullet */
			list<Bullet>::iterator tmp = it;
			it++;
			bullet.erase(tmp);
			continue;
		}

		/* bullet displacement */
		if ((*it).displace(DELTA_TIME) == 1) {
			list<Bullet>::iterator tmp = it;
			it++;
			bullet.erase(tmp);
		}
		else {
			it++;
		}
	}

	/* cooldown decrement */
	if (ship1.bulletCD > 0)  ship1.bulletCD--;
	if (ship2.bulletCD > 0)  ship2.bulletCD--;
}

void GameEngine::draw()
{
	fixed angle1 = itofix((int)(ship1.getAngle() * ANGLE_RATE));
	fixed angle2 = itofix((int)(ship2.getAngle() * ANGLE_RATE));

	// draw the background
	clear_to_color(buffer, makecol(0,0,0));

	// draw background stars
	drawBgStar();

	// draw ships
	pivot_sprite(buffer, res[FRAME_SHIP1], ship1.getPosX(), ship1.getPosY(),
		SHIP_CENTER_X, SHIP_CENTER_Y, angle1);
	pivot_sprite(buffer, res[FRAME_SHIP2], ship2.getPosX(), ship2.getPosY(),
		SHIP_CENTER_X, SHIP_CENTER_Y, angle2);

	// draw bullets
	for (list<Bullet>::iterator it = bullet.begin(); it != bullet.end(); it++)
	{
		fixed bulletAngle = itofix((int)((*it).getAngle() * ANGLE_RATE));
		pivot_sprite(buffer, res[FRAME_BULLET], (*it).getPosX(), (*it).getPosY(),
			BULLET_CENTER_X, BULLET_CENTER_Y, bulletAngle);
	}

	// draw the star
	draw_sprite(buffer, res[FRAME_STAR], STAR_X, STAR_Y);

	// draw healths
	textprintf_centre_ex(buffer, font, HEALTH_TXT_X, HEALTH_TXT_Y,
		makecol(0,255,0), makecol(0,0,0), "Player1: %d", ship1.health);

	textprintf_centre_ex(buffer, font, RES_WIDTH - HEALTH_TXT_X, HEALTH_TXT_Y,
		makecol(255,0,0), makecol(0,0,0), "Player2: %d", ship2.health);

	// copy to screen
	acquire_screen();
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	release_screen();
}

int GameEngine::restart()
{
	bullet.clear();

	initData();

	return 0;
}

int GameEngine::pause()
{
	paused = !paused;

	return 0;
}

void GameEngine::addBullet(Vector & pos, Vector look)
{
	look.normalize(POS_DELTA);
	pos += look;
	look.normalize(BULLET_SPEED);
	Bullet newBullet(pos, look.angle(), look);
	this->bullet.push_back(newBullet);
}

int GameEngine::initBgStar()
{
	srand((unsigned int)time(NULL));
	int starNum = rand() % 10 + 10;  // random number from 10 to 19

	bgStarPos.clear();

	for (int i=0; i<starNum; i++)
	{
		int randX = rand() % RES_WIDTH;
		int randY = rand() % RES_HEIGHT;
		Vector pos(randX, randY);
		bgStarPos.push_back(pos);
	}

	return 0;
}

int GameEngine::drawBgStar()
{
	srand((unsigned int)time(NULL));
	for (list<Vector>::iterator it = bgStarPos.begin(); it != bgStarPos.end(); it++)
	{
		if( rand() % 4 == 0)
		{
			// 1/4 shining
			draw_sprite(buffer, res[FRAME_BGSTAR_SHINING], (*it).x, (*it).y);
		}
		else
		{
			draw_sprite(buffer, res[FRAME_BGSTAR], (*it).x, (*it).y);
		}
	}

	return 0;
}

void keypressHandler(int scancode)
{
	int key = scancode & 0x7f;

	for (int i = 0; i < GAME_KEY_NUM; i++)
	{
		if (key == KEY[i]) {
			isKeyPressed[i] = !(scancode & 0x80);
			break;
		}
	}
}
END_OF_FUNCTION(keypressHandler)
