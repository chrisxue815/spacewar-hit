/*
* ============================================================================
*  Name        : MenuEngine from MenuEngine.h
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


#pragma once


#include "Settings.h"
#include "ChgKeyMenu.h"
#include <allegro.h>
using namespace SpaceWar;


namespace SpaceWar
{
	enum MenuState
	{
		EXIT_PROGRAM,
		NEW_GAME,
		RESUME_GAME
	};

	class MenuEngine
	{
	public:
		MenuEngine();
		~MenuEngine();
		int init();
		MenuState exec();

	protected:
		int draw();
		int readKey();
		int switchItem(bool up);
		int selectItem();
		int drawInfo();

	protected:
		ChgKeyMenu chgKey;

		BITMAP * buffer;
		int selectedIndex;
		int itemColor[MENU_ITEM_NUM];
		bool run;
		MenuState state;
		bool canResume;

		MIDI *menuMusic;
		RGB     pal[256];
	};
}
