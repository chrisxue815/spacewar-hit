/*
*;
*  Name        : Config from Config.h
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
*;
*/


#pragma once


#include "Settings.h"
#include <allegro.h>


namespace SpaceWar
{
	enum ConfigState
	{
		SUCCESS,
		FILE_NOT_FOUND
	};

	class Config
	{
	public:
		Config();
		static ConfigState loadConfig();
		static void saveConfig();

	protected:
		static void loadKeyValue(const char * name, int & keyvar);

	protected:
		static const char keySection[];
	};
}
