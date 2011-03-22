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


#include "Config.h"
using namespace SpaceWar;


const char Config::keySection[] = "keys";
Config::Config()
{
	
}

ConfigState Config::loadConfig()
{
	if ( exists(CONFIG_FILENAME) )
	{
		// save the current ini file, then set the program specific one
		push_config_state();
		set_config_file(CONFIG_FILENAME);

		for (int i = 0; i < CHGKEY_NUM; i++)
		{
			loadKeyValue(CONFIG_NAME[i], KEY[ CONFIG_INDEX[i] ]);
		}

		// restore the old config file
		pop_config_state();

		return SUCCESS;
	}
	else
	{
		return FILE_NOT_FOUND;
	}
}

void Config::saveConfig()
{
	// save the current ini file, then set the program specific one
	push_config_state();
	set_config_file(CONFIG_FILENAME);

	for (int i = 0; i < CHGKEY_NUM; i++)
	{
		set_config_int(keySection, CONFIG_NAME[i], KEY[ CONFIG_INDEX[i] ]);
	}

	// restore the old config file
	pop_config_state();
}

void Config::loadKeyValue(const char * name, int & keyvar)
{
	int scancode = get_config_int(keySection, name, keyvar);
	// TODO: Check whether the scancode is available
	if (scancode > 126)
	{
		allegro_message("Error:config error! program will use the default value!");
	}
	else {
		keyvar = scancode;
	}
}
