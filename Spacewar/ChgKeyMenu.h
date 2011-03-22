/*
* ============================================================================
*  Name        : ChgKeyMenu from ChgKeyMenu.h
*  Part of     : SpaceWar
*  Created     : DEC/5/2010 by Chris, Cloud
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
#include "Config.h"
#include <allegro.h>
using namespace SpaceWar;


namespace SpaceWar
{
	class ChgKeyMenu
	{
	public:
		ChgKeyMenu();
		~ChgKeyMenu();
		int init();
		int exec();

	protected:
		int draw();
		void drawItem(int index);
		void drawPressKey();
		int readKey();
		int switchItem(bool up);
		int selectItem();
		int changeKey(int);
		bool checkKey(int, int);

	protected:
		BITMAP * buffer;
		int selectedIndex;
		int itemColor[CHGKEY_MENU_ITEM_NUM];

		bool run;
	};
}
