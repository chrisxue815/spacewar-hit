/*
* ============================================================================
*  Name        : MainEngine from MainEngine.h
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


#include <allegro.h>
#include "MenuEngine.h"
#include "GameEngine.h"
#include "Config.h"
using namespace SpaceWar;


namespace SpaceWar
{
	class MainEngine
	{
	public:
		int exec(char *parentPath);

	protected:
		int init();

	protected:
		MenuEngine menuEngine;
		GameEngine gameEngine;

		char *parentPath;
	};
}
