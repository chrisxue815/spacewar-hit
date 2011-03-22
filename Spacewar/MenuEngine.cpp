/*
* ============================================================================
*  Name        : MenuEngine from MenuEngine.cpp
*  Part of     : SpaceWar
*  Created     : Oct/24/2010 by Chris, Cloud
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


#include "MenuEngine.h"
using namespace SpaceWar;

#define TRUE -1
#define FALSE 0
#define SELECTED_COLOR makecol(255,0,0)
#define UNSELECTED_COLOR makecol(255,255,255)


MenuEngine::MenuEngine()
{
	/* allocate the memory buffer */
	buffer = create_bitmap(RES_WIDTH, RES_HEIGHT);
}

MenuEngine::~MenuEngine()
{
	destroy_bitmap(buffer);
	destroy_midi(menuMusic);
}

MenuState MenuEngine::exec()
{
	//play menu music
	play_midi(menuMusic, TRUE);

	run = true;

	do
	{
		draw();
		readKey();
	}
	while(run);

	canResume = true;

	return state;
}

int MenuEngine::init()
{
	buffer = create_bitmap(RES_WIDTH, RES_HEIGHT);

	selectedIndex = 1;
	itemColor[0] = UNSELECTED_COLOR;
	itemColor[1] = SELECTED_COLOR;
	for (int i=2; i<MENU_ITEM_NUM; itemColor[i++] = UNSELECTED_COLOR);

	state = EXIT_PROGRAM;
	canResume = false;

	// load menu music
	menuMusic = load_midi("content\\sound\\menu.mid");
    if (!menuMusic)
		allegro_message("Unable to load menu background music!");

	return 0;
}

int MenuEngine::draw()
{

	/* load the image */
	buffer = load_bitmap("content\\texture\\bg.bmp", NULL);
	if (buffer == NULL) {
		allegro_message("Unable to load the backgroud image!");
	}

	if (canResume == true) {
		textprintf_centre_ex(buffer, font, MENU_ITEM_X, MENU_RESUME_Y,
			itemColor[0], makecol(0,0,0), "Resume Game");
	}
	textprintf_centre_ex(buffer, font, MENU_ITEM_X, MENU_NEWGAME_Y,
		itemColor[1], makecol(0,0,0), "New Game");
	textprintf_centre_ex(buffer, font, MENU_ITEM_X, MENU_OPTIONS_Y,
		itemColor[2], makecol(0,0,0), "Keyboard Settings");
	textprintf_centre_ex(buffer, font, MENU_ITEM_X, MENU_DEVMODE_Y,
		itemColor[3], makecol(0,0,0), "About Us");
	textprintf_centre_ex(buffer, font, MENU_ITEM_X, MENU_EXIT_Y,
		itemColor[4], makecol(0,0,0), "Exit");

	// copy to screen
	acquire_screen();
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	release_screen();

	return 0;
}

int MenuEngine::readKey()
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

	// enter or right
	else if ((keyPressed == MENU_KEY_ENTER) ||
		(keyPressed == MENU_KEY_RIGHT)) {
		selectItem();
	}

	return 0;
}

int MenuEngine::switchItem(bool up)
{
	int min = (canResume ? 0 : 1);

	itemColor[selectedIndex] = UNSELECTED_COLOR;

	if (up) {
		if (selectedIndex == min) {
			selectedIndex = MENU_ITEM_NUM - 1;
		}
		else {
			selectedIndex--;
		}
	}
	else {
		if (selectedIndex == MENU_ITEM_NUM - 1) {
			selectedIndex = min;
		}
		else {
			selectedIndex++;
		}
	}

	itemColor[selectedIndex] = SELECTED_COLOR;

	return 0;
}

int MenuEngine::selectItem()
{
	switch(selectedIndex)
	{
	// Resume Game
	case 0:
		run = false;
		state = RESUME_GAME;
		break;

	// New Game
	case 1:
		run = false;
		state = NEW_GAME;
		break;

	// Keyboard Settings
	case 2:
		chgKey.exec();
		break;

	// About Us
	case 3:
		drawInfo();
		break;

	// Exit
	case 4:
		run = false;
		state = EXIT_PROGRAM;
		break;
	}

	return 0;
}

int MenuEngine::drawInfo()
{
	clear_to_color(buffer,makecol(0,0,0));
	for (int i=0; i< INFO_ITEM ; i++)
	{
		textprintf_centre_ex(buffer, font, MENU_ITEM_X, MENU_RESUME_Y+i*40,
			makecol(255,255,255), makecol(0,0,0), INFORMATION[i]);
	}

	// copy to screen
	acquire_screen();
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	release_screen();

	readkey();
	clear_to_color(buffer,makecol(0,0,0));

	return 0;
}