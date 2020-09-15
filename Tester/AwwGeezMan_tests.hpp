#define BOOST_TEST_MODULE AwwGeezMan
#include <boost/test/included/unit_test.hpp>

#define RANDOM_ARG_MAX 1000000

// Include the student's work in a separate namespace
#include "../src/Morty.hpp"
#include <cstdlib>
#include <random>

#if defined( EXTRA_CREDIT ) 
int getDim(std::string dimstr) {
	if (dimstr == "C137")
		return interdimensional::C137;
	else if (dimstr == "Z286")
		return interdimensional::Z286;
	else
		return interdimensional::UNKNOWN;
}

void test_argument_parse(std::vector<std::string> args_string) {
	// Construct argc and argv as would be passed from the main function
	// during normal execution
	std::vector<char*> argv;
	for (const auto& arg : args_string)
		argv.push_back((char*)arg.data());
	argv.push_back(nullptr);

	// Call the student's function to parse the arguments
	interdimensional::args args =
			interdimensional::parseArgs(argv.size()-1, argv.data());

	// Test that the output is correct
	int start, stop, step, dim;

	if (args_string.size() == 5) {
		start = std::stoi(args_string[1]);
		stop = std::stoi(args_string[2]);
		step = std::stoi(args_string[3]);
		dim = getDim(args_string[4]);
	}
	else {
		start = std::stoi(args_string[1]);
		stop = std::stoi(args_string[2]);
		step = 1;
		dim = getDim(args_string[3]);
	}

	BOOST_CHECK( args.dim == dim );
	BOOST_CHECK( args.start == start );
	BOOST_CHECK( args.stop == stop );
	BOOST_CHECK( args.step == step );
}

#endif