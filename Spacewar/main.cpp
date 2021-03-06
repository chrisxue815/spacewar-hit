/*
* ============================================================================
*  Name        : main from main.h
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


#include "MainEngine.h"
#include <allegro.h>
using namespace SpaceWar;


int main(int argc, char**argv)
{
	if (allegro_init() != 0) {
		return 1;
	}

	MainEngine engine;

	return engine.exec(argv[0]);
}
END_OF_MAIN()
