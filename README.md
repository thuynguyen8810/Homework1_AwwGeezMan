# ECE 275 Homework 1: Aww Geez Man

What if there was a Morty in another dimension who said everything backwards?


![The Personal Space Show](imgs/gettinWeird.jpg)

> Aww Geez Man, do we really have another Rick and Morty themed assignment!?

Yes, you do!!! Homework 1: "Aww Geez Man" will test your ability to:

* Again recieve and parse command line arguments
* Perform basic control flow and loops (as discussed in ECE 175)
* Define and utilize overloaded functions
* Define and utilize functions within different namespaces

## Program Requirements
You are to write a program to the following specifications:

1. Your program *shall* recieve command line arguments either as (1) ./AwwGeezMan {start} {stop} {dimension}, or (b) ./AwwGeezMan {start} {stop} {step} {dimension} where start, stop, and step are integer values while dimension is a string.
2. Your program *shall* loop from {start} to {stop} in steps of {step} (or 1 if no {step} is given) and print one of the following statements depending on the loop invariant (call it *i* here):
	* if *i* is a multiple of 3, print "*i*: Aww"
	* if *i* is a multiple of 5, print "*i*: Geez"
	* if *i* is a multiple of 15, print "*i*: Aww Geez Man"
3. If the dimension is given as "Z286", your program *shall* print the above statements in reverse (only the text is reversed, e.g., "*i*: wwA"). 

Below see two examples. Note that line starting with "#" should not be printed in your program and are there only to provide human and machine readable information, i.e., the "#" is a comment in these files.

An example of one valid command line argument: 

```
# Command arguments: 4 25 C137
# Solution:
Morty C137 says:
4: 
5: Geez
6: Aww
7: 
8: 
9: Aww
10: Geez
11: 
12: Aww
13: 
14: 
15: Aww Geez Man
16: 
17: 
18: Aww
19: 
20: Geez
21: Aww
22: 
23: 
24: Aww
25: Geez
```

Another example of valid command line arguments:

```
# Command arguments: 30 50 2 Z286
# Solution:
Morty Z286 says:
30: naM zeeG wwA
32: 
34: 
36: wwA
38: 
40: zeeG
42: wwA
44: 
46: 
48: wwA
50: zeeG
```

## Writing Your Program
The github is populated with the following directory structure (minus the output files):

```
Homework1_AwwGeezMan/
    ├── CMakeLists.txt
    ├── ReadMe.md
    ├── Tester
    │   ├── AwwGeezManSolution.py
    │   ├── AwwGeezMan_tests.cpp
    │   ├── AwwGeezMan_tests.hpp
    │   ├── CMakeLists.txt
    │   ├── ProgramTester.py
    │   ├── conftest.py
    │   ├── solution
    │   │   └── command_arguments.txt
    │   └── test_AwwGeezMan.py
    └── src
        ├── AwwGeezMan.cpp
        ├── CMakeLists.txt
        ├── Morty.cpp
        └── Morty.hpp
```
You do NOT need to edit *anything* except for ```src/AwwGeezMan.cpp```, ```src/Morty.cpp```, and ```src/Morty.hpp```. The ```Tester``` directory houses the Python scripts to test the program along with a suite of C++ unit tests (a concept which we will learn later) that will test the functions written in this assignment (see below for information on testing). There is an included CMakeLists.txt file - we will not learn CMake in this course but it's needed for the instructor to compile and run/test your code. Please do NOT edit the CMakeLists.txt file. Please, under no circumstances, should you edit the ```output_*.txt``` files. These were generated using the ```AwwGeezManSolution.py``` file which the instructor has provided for transparency. 

You must define two seperate namespaces for the two Mortys, i.e., Morty C137 and Morty Z286. You will thus have a namespace called C137 and another namespace called Z286. Within each of these namespaces must be a function named Morty which returns type void as is overloaded to accept either two or three integer values. One function will be ```Morty(start, stop, step)``` and the other will be ```Morty(start, stop)``` where each parameter is an interger value. Morty C137 will loop as defined in the program requirements and print the statements in forward-order. Morty Z286 will loop as defined in the program requirements and print the statements in reverse-order. 

### Extra Credit
Rick has created a device which parses command line arguments and returns them in a structure. You will attempt to replicate this in your program by creating another namespace and another function. In ```Morty.cpp``` you are given the following code for the extra credit: 

```C++
namespace interdimensional { 
	// Declare enumeration to hold the dimensions each Morty is from
	enum dimension {UNKNOWN = -1, C137, Z286};
	
	// Declare a structure to hold the arguments passed to the function
	struct args {
		int start;
		int stop;
		int step;
		dimension dim;
	};
	
	// Declare a function to parse the args and return the above declared structure
	args parseArgs(int c, char** v);
	
}
```

For 50% extra, i.e., a 150% on this assignment, impliment the ```interdimensional::parseArgs(int c, char** v)``` function which accepts an integer number of command line arguments and a pointer to pointer of type char which points to the first command line argument. Note that these are the exact same as ```main(int argc, char** argv)```. This function returns a structure of type ```interdimensional::args``` which holds the values of command line arguments as defined in the above declaration. Note that ```interdimensional::args.dim``` is of type ```interdimensional::dimension``` which is an *enumeration* type. An enumeration, or ```enum``` is a simple way of "declaring a distinct type whose value is restricted to a range of values" [ [enum ref](https://en.cppreference.com/w/cpp/language/enum) ]. The below example is from the linked reference page and illustrates the usage of enumerations: 

```C++
enum Color { red, green, blue };
Color r = red;
switch(r)
{
    case red  : std::cout << "red\n";   break;
    case green: std::cout << "green\n"; break;
    case blue : std::cout << "blue\n";  break;
}
```
Note that because Rick Sanchez has invented interdimensional travel, these declarations and function fall within the namespace interdimensional! 

To submit the extra credit, upload your code to the "extra_credit" branch on GitHub. This branch houses unit-tests to randomly generate command line arguments and pass to ```interdimensional::parseArgs( )```. 

### Useful References
Below are listed references that might be useful

* Namespaces tutorial: <http://www.cplusplus.com/doc/oldtutorial/namespaces/>
* Overloading tutorial: <http://www.cplusplus.com/doc/tutorial/functions2/>
* Relational operator (==) for strings: <http://www.cplusplus.com/reference/string/string/operators/> 
* Tutorial on Modulo (%) operator: <https://www.cprogramming.com/tutorial/modulus.html> 

### Incrimental Buildup
Breaking this task into chunks, there are some main things you want to accomplish:

- [ ] Parse the command line arguments and print back to the console to validate
- [ ] Perform the looping and printing of appropriate statements for one Morty
- [ ] Overload the Morty function
- [ ] Create the Morty from another dimension
- [ ] Print based on command line arguments

## Testing Your Program
To test your program, the instructor has written a custom Python-based testing framework which utilized pytest. You'll notice in ```Tester``` there are four Python3 scripts which will be used to test your program. When you create a pull request on GitHub, the program will execute ```pytest``` which will utilize the instructor's ```ProgramTester``` to test the output of your program against the solution for any given command line arguments. There are 76 tests for this program which should run in under five seconds. If your output does not match the solution (except for whitespace; the tester disreguards linese that are completely whitespace), you will fail a test and the tester object will show exactly which lines are different and will postulate a guess as to where exactly the lines are different. The ```Tester``` directory also houses C++ unit test envoked by ```ctest``` which will call and execute your program. Note that if the python test, i.e., the output test, is passing but the C++ testing is not, then you have not conformed to the program specifications for function parameters and/or namespaces. 
