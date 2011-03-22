/*
* ============================================================================
*  Name        : MainEngine from MainEngine.cpp
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


#include "MainEngine.h"
using namespace SpaceWar;


int MainEngine::exec(char *parentPath)
{
	this->parentPath = parentPath;

	init();
	menuEngine.init();
	gameEngine.init();

	MenuState menuState;
	do
	{
		menuState = menuEngine.exec();

		if (menuState == EXIT_PROGRAM) {
			break;
		}
		else if (menuState == NEW_GAME) {
			gameEngine.restart();
		}
		gameEngine.exec();
	}
	while(1);

	return 0;
}

int MainEngine::init()
{
	initSettings();

	if (gameEngine.loadSrc(parentPath) != 0) {
		return 1;
	}

	if (Config::loadConfig() == FILE_NOT_FOUND) {
		Config::saveConfig();
	}

	/* set the color palette */
	set_palette(desktop_palette);

	/* set a graphics mode sized RES_HEIGTH * RES_WIDTH */
	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, RES_WIDTH, RES_HEIGHT, 0, 0) != 0) {
		if (set_gfx_mode(GFX_SAFE, RES_WIDTH, RES_HEIGHT, 0, 0) != 0) {
			set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
			allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
			return 1;
		}
	}

	/* set up the timer and keyboard handler */
	install_timer();
	install_keyboard();

	/* install a MIDI sound driver */
	if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
		allegro_message("Error initialising sound system\n%s\n", allegro_error);
		return 1;
	}
	return 0;
}
