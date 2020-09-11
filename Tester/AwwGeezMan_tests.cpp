#define BOOST_TEST_MODULE AwwGeezMan
#include <boost/test/included/unit_test.hpp>

#include "AwwGeezMan_tests.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

//int add( int i, int j ) { return i+j; }

#if defined( EXTRA_CREDIT )

BOOST_AUTO_TEST_CASE( test_extra_credit )
{
	cout << "Testing extra credit for hard-coded case" << endl;

	// Test for various hard-coded arguments!
	vector< vector<string> > arguments = {
			{"./AwwGeezMan", "10", "20", "5", "C137"},
			{"./AwwGeezMan", "10", "20", "5", "Z286"},
			{"./AwwGeezMan", "10", "20", "C137"},
			{"./AwwGeezMan", "10", "20", "Z286"},
			{"./AwwGeezMan", "10", "20", "K198"},
	};

	// Test all the arguments in a loop
	for (vector<string> arg : arguments)
		test_argument_parse(arg);
}

BOOST_AUTO_TEST_CASE ( test_extra_credit_long )
{

	cout << "Testing extra credit for random case" << endl;


	vector< vector<string> > arguments;

	// Test for various random arguments
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(1, RANDOM_ARG_MAX);
	for (int i = 0; i < 100; i++) {
		vector<string> a = {"./AwwGeezMan",
				std::to_string(distrib(gen)),
				std::to_string(distrib(gen)),
				std::to_string(distrib(gen)),
				(distrib(gen) > RANDOM_ARG_MAX/2) ? "C137" : "Z286"};

		arguments.push_back(a);
	}

	// Test all the arguments in a loop
	for (vector<string> arg : arguments)
		test_argument_parse(arg);
}
#endif



BOOST_AUTO_TEST_CASE ( test_proper_program )
{
	// Just run the functions to make sure that they compile and execute. Pytest will take care
	// of the output. If this test fails but pytest passes, students have not followed program
	// instructions

	cout << "Testing that the Morty functions exists with the correct arguments and within the "
			<< "correct namespaces" << endl;

	C137::Morty(10, 12, 1);
	C137::Morty(10, 12);

	Z286::Morty(10, 12, 1);
	Z286::Morty(10, 12);
}
