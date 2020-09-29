/*
 __  __            _               _
|  \/  | ___  _ __| |_ _   _      | |__  _ __  _ __
| |\/| |/ _ \| '__| __| | | |     | '_ \| '_ \| '_ \
| |  | | (_) | |  | |_| |_| |  _  | | | | |_) | |_) |
|_|  |_|\___/|_|   \__|\__, | (_) |_| |_| .__/| .__/
					   |___/            |_|   |_|
*/

#include <string> 
#include <iostream>
#pragma once

namespace interdimensional 
{
	// Declare enumeration to hold the dimensions each Morty is from
	enum dimension {UNKNOWN = -1, C137, Z286};
	// Declare a structure to hold the arguments passed to the function
	struct args 
	{
		int start;
		int stop;
		int step;
		dimension dim;
	};

	// Declare a function to parse the args and return the above declared structure
	args parseArgs (int c, char** v);
}

namespace C137
{
	void Morty(int start, int stop, int step);
	void Morty(int start, int stop);
}

namespace Z286
{
	void Morty(int start, int stop, int step);
	void Morty(int start, int stop);
}
