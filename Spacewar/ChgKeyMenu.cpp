/*
* ============================================================================
*  Name        : ChgKeyMenu from ChgKeyMenu.cpp
*  Part of     : SpaceWar
*  Created     : Dec/5/2010 by Chris, Cloud
*  Version     : 10.10
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


#include "ChgKeyMenu.h"
using namespace SpaceWar;


#define WHITE makecol(255,255,255)
#define BLACK makecol(0,0,0)
#define RED makecol(255,0,0)
#define SELECTED_COLOR RED
#define UNSELECTED_COLOR WHITE

int keyNameIndex[KEYTABLE_INDEX_NUM];

ChgKeyMenu::ChgKeyMenu()
{
	/* allocate the memory buffer */
	buffer = create_bitmap(RES_WIDTH, RES_HEIGHT);
}

ChgKeyMenu::~ChgKeyMenu()
{
	destroy_bitmap(buffer);
}

int ChgKeyMenu::exec()
{
	init();

	do
	{
		draw();
		readKey();
	}
	while(run);

	Config::saveConfig();

	return 0;
}

int ChgKeyMenu::init()
{
	// item colors
	selectedIndex = 0;
	itemColor[0] = SELECTED_COLOR;
	for (int i=1; i<CHGKEY_MENU_ITEM_NUM; itemColor[i++] = UNSELECTED_COLOR);

	run = true;

	return 0;
}

int ChgKeyMenu::draw()
{
	// draw the background
	clear_to_color(buffer, makecol(0,0,0));

	textprintf_ex(buffer, font, 150, 50,
		UNSELECTED_COLOR, makecol(0,0,0),
		"Help: UP and DOWN to choose, then ENTER to change the key!");

	textprintf_ex(buffer, font, CHGKEY_MENU_PLAYER_X, CHGKEY_MENU_Y[0],
		UNSELECTED_COLOR, makecol(0,0,0),
		"Player 1:");

	textprintf_ex(buffer, font, CHGKEY_MENU_PLAYER_X, CHGKEY_MENU_Y[4],
		UNSELECTED_COLOR, makecol(0,0,0),
		"Player 2:");

	for (int i = 0; i < CHGKEY_NUM; i++)
	{
		drawItem(i);
	}

	textprintf_ex(buffer, font, CHGKEY_MENU_KEYNAME_X, CHGKEY_MENU_Y[10],
		itemColor[10], makecol(0,0,0), "SAVE AND EXIT");

	acquire_screen();
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	release_screen();

	return 0;
}

void ChgKeyMenu::drawItem(int index)
{
	// key name
	textprintf_ex(buffer, font, CHGKEY_MENU_KEYNAME_X, CHGKEY_MENU_Y[index],
		itemColor[index], makecol(0,0,0), CHGKEY_NAME[index]);

	// key
	textprintf_ex(buffer, font, CHGKEY_MENU_KEY_X, CHGKEY_MENU_Y[index],
		itemColor[index], makecol(0,0,0), KEY_NAME[KEY[index]]);
}

void ChgKeyMenu::drawPressKey()
{
	rectfill(buffer, 330, 285, 470, 315, makecol(0,0,0));
	rect(buffer, 330, 285, 470, 315, makecol(255,255,255));
	textprintf_centre_ex(buffer, font, 400, 300,
		makecol(255,255,255), makecol(0,0,0), "Press key...");
	acquire_screen();
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	release_screen();
}

int ChgKeyMenu::readKey()
{
	int keyPressed = readkey() >> 8;

	// up
	if (keyPressed == MENU_KEY_UP) {
		switchItem(true);
	}

	// down
	else if (keyPressed == MENU_KEY_DOWN) {
		switchItem(false);
	}

	// enter
	else if (keyPressed == MENU_KEY_ENTER) {
		selectItem();
	}

	//left
	else if (keyPressed == MENU_KEY_LEFT
		|| keyPressed == MENU_KEY_ESC) {
		selectedIndex = 10;
		selectItem();
	}

	return 0;
}

int ChgKeyMenu::switchItem(bool up)
{
	int min = 0;

	itemColor[selectedIndex] = UNSELECTED_COLOR;

	if (up) {
		if (selectedIndex == min) {
			selectedIndex = CHGKEY_MENU_ITEM_NUM - 1;
		}
		else {
			selectedIndex--;
		}
	}
	else {
		if (selectedIndex == CHGKEY_MENU_ITEM_NUM - 1) {
			selectedIndex = min;
		}
		else {
			selectedIndex++;
		}
	}

	itemColor[selectedIndex] = SELECTED_COLOR;

	return 0;
}

int ChgKeyMenu::selectItem()
{
	if (selectedIndex >= 0 && selectedIndex <= 9)
	{
		// change key
		changeKey(selectedIndex);
	}
	else
	{
		// save & exit
		run = false;
	}

	return 0;
}

int ChgKeyMenu::changeKey(int keyindex)
{
	drawPressKey();

	int keyPressed;

	while (true)
	{
		keyPressed = readkey() >> 8;
		if (keyPressed == KEY_ESC || keyPressed == KEY_ENTER)
		{
			break;
		}
		else if ( checkKey(keyPressed, keyindex) )
		{
			KEY[keyindex] = keyPressed;
			break;
		}
		else
		{
			allegro_message("Error: Unavailable key! Please press another one.");
		}
	}

	return 0;
}

bool ChgKeyMenu::checkKey(int keyPressed, int keyindex)
{
	for (int i = 0; i < GAME_KEY_NUM; i++)
	{
		if (i != keyindex && keyPressed == KEY[i] )
		{
			return false;
		}
	}

	return true;
}
