/*
 _____ ____ _____   ____ _____ ____
| ____/ ___| ____| |___ \___  | ___|
|  _|| |   |  _|     __) | / /|___ \
| |__| |___| |___   / __/ / /  ___) |
|_____\____|_____| |_____/_/  |____/
 _   _                                         _      _
| | | | ___  _ __ ___   _____      _____  _ __| | __ / |
| |_| |/ _ \| '_ ` _ \ / _ \ \ /\ / / _ \| '__| |/ / | |
|  _  | (_) | | | | | |  __/\ V  V / (_) | |  |   <  | |
|_| |_|\___/|_| |_| |_|\___| \_/\_/ \___/|_|  |_|\_\ |_|

Aww Geez Man: Interdimensional Mortys.

One of Morty C137's favorite phrases is "Aww Geez Man". But, in dimension Z286, there exists a Morty who says everything backwards.

SUBMITTED BY: NGUYEN, THUY

*/

#include <iostream>
#include <string>
#include <string.h>
#include "Morty.hpp"


int main(int ac, char** av)
{
    interdimensional::args saveArgs;
 
    // Parse the command line arguments. The program is executed as
    // AwwGeezMan {start} {stop} {dimension} 
    // AwwGeezMan {start} {stop} {step} {dimension}

    saveArgs = interdimensional::parseArgs(ac, av);

    // Parse the command line arguments
    // Depending on the dimension of the arguments, call the appropriate Morty
    // function

    switch (saveArgs.dim)
    {
        case 0: 
            C137::Morty(saveArgs.start, saveArgs.stop, saveArgs.step);
        case 1: 
            Z286::Morty(saveArgs.start, saveArgs.stop, saveArgs.step);
        case -1:
        {
            std::cout << "ERROR: unknown dimension" << std::endl;
        }
    }

    return 0;
}
