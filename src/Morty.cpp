/*
 __  __            _
|  \/  | ___  _ __| |_ _   _        ___ _ __  _ __
| |\/| |/ _ \| '__| __| | | |      / __| '_ \| '_ \
| |  | | (_) | |  | |_| |_| |  _  | (__| |_) | |_) |
|_|  |_|\___/|_|   \__|\__, | (_)  \___| .__/| .__/
                       |___/           |_|   |_|
*/

// Include the Morty header file
#include "Morty.hpp"
#include <iostream>
#include <string>
#include <string.h>

// =========================================================================== // 
//          Define functions enclosed in Namespace C137 here 
// =========================================================================== // 

namespace C137      // overloaded c137 functions
{
    void Morty(int Start, int Stop, int Step)       // overloaded function for when there is a step
    {
        int i;

        std::cout << "Morty C137 says:" << std::endl;

        for (i = Start; i <= Stop; i = i + Step)    // loop to go through the steps
        {
            std::cout << i << ": ";
            if (i % 15 == 0)                        // if it is a multiple of 15 output Aww Geez Man 
            {
                std::cout << "Aww Geez Man";
            }
            else if (i % 5 == 0)                    // if it is a multiple of 5 output Geez 
                std::cout << "Geez";
            else if (i % 3 == 0)                    // if it is a multiple of 3 output Aww
                std::cout << "Aww";

            std::cout << std::endl;
        }
    }

/*
    void Morty(int Start, int Stop)                 // overloaded function for when there is no step
    {
        int i;

        std::cout << "Morty C137 says:" << std::endl;

        for (i = Start; i <= Stop; i++)             // go through the steps
        {
            std::cout << i << ": ";
            if (i % 15 == 0)                        // if it is a multiple of 15 output Aww Geez Man
            {
                std::cout << "Aww Geez Man";
            }
            else if (i % 5 == 0)                    // if it is a multiple of 5 output Geez 
                std::cout << "Geez";
            else if (i % 3 == 0)                    // if it is a multiple of 3 output Aww
                std::cout << "Aww";

            std::cout << std::endl;
        }
    }

*/

}

// =========================================================================== // 
//          Define functions enclosed in Namespace Z286 here 
// =========================================================================== // 

namespace Z286      // overloaded z286 functions - reverse the Aww Geez Man (naM zeeG wwA)
{
    void Morty(int Start, int Stop, int Step)       // overloaded Z286 function for when there is a step
    {
        int i;

        std::cout << "Morty Z286 says:" << std::endl;

        for (i = Start; i <= Stop; i = i + Step)    // go through the steps
        {
            std::cout << i << ": ";
            if (i % 15 == 0)                        // if it is a multiple of 15 output naM zeeG wwA 
            {
                std::cout << "naM zeeG wwA";
            }
            else if (i % 5 == 0)                    // if it is a multiple of 5 output zeeG 
                std::cout << "zeeG";
            else if (i % 3 == 0)                    // if it is a multiple of 3 output wwA 
                std::cout << "wwA";

            std::cout << std::endl;
        }
    }
 
/*
    void Morty(int Start, int Stop)                 // overloaded Z286 function for no steps
    {
        int i;

        std::cout << "Morty Z286 says:" << std::endl;

        for (i = Start; i <= Stop; i++)
        {
            std::cout << i << ": ";
            if (i % 15 == 0)                        // if it is a multiple of 15 output naM zeeG wwA 
            {
                std::cout << "naM zeeG wwA";
            }
            else if (i % 5 == 0)                    // if it is a multiple of 5 output zeeG 
                std::cout << "zeeG";
            else if (i % 3 == 0)                    // if it is a multiple of 3 output wwA 
                std::cout << "wwA";

            std::cout << std::endl;
        }
    }

*/
    
}

namespace interdimensional
{
    args parseArgs(int c, char** v)
    {
        interdimensional::args argumentsIn;
        argumentsIn.step = 1;                               // the step is 1 unless entered

        if (c != 4 and c != 5)                              // must have 4 or 5 arguments to be valid
        {
            std::cout << "Error: Command line arguments are incorrect. Call program as (1) or (2)"
                << std::endl;
            std::cout << "(1)\t./AwwGeezMan {start} {stop} {dimension}" << std::endl;
            std::cout << "(2)\t./AwwGeezMan {start} {stop} {step} {dimension}" << std::endl;
            argumentsIn.dim = UNKNOWN;
        }
        else
        {
            argumentsIn.start = atoi(v[1]);
            argumentsIn.stop = atoi(v[2]);

            if (c == 5) argumentsIn.step = atoi(v[3]);      // if step there use it

            if (strcmp(v[c - 1], "C137") == 0)
            {
                argumentsIn.dim = C137;
            }
            else if (strcmp(v[c - 1], "Z286") == 0)
            {
                argumentsIn.dim = Z286;
            }
        }
        /*
        else if (strcmp(v[c - 1], "Z286") == 0) // must use strcmp not ==, == doesn't work
        {
            if (c == 5) Z286::Morty(atoi(v[1]), atoi(v[2]), atoi(v[3]));    // if step there use it
            else Z286::Morty(atoi(v[1]), atoi(v[2]));                         // when no step given
        }
        else
        {
            std::cout << "ERROR: Unknown dimension!!" << std::endl;             // no valid dimension
            return -1;
        }
        */
        std::cout << "D'oh!" << std::endl;

        return argumentsIn;
    }
}
