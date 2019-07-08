#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>
using std::string;

//==== String Functions =====//
class StringUtil
{
public:

	static void change_from_to( char* str, const char from, const char to );
	static void change_from_to( string & str, const char from, const char to );
	static void chance_underscore_to_space( string & str );
	static void chance_space_to_underscore( string & str );

	static bool replace_once( string & str, const string & from, const string & to );
	static void replace_all( string & str, const string & from, const string & to  );

	static void remove_leading( string & str, char c );
	static void remove_trailing( string & str, char c );

	static string int_to_string( int i, const char* format );
	static string double_to_string( double v, const char* format );
	//string point_to_string( const point & point, const char* format );
	static bool string_to_uint( string input, unsigned int *output );  //use strtoul instead <cstdlib> (stdlib.h)
	static bool string_to_double( string input, double *output );	//use strtod instead <cstdlib> (stdlib.h)

	static int count_char_matches( string & str, char c );

	static int compute_hash( const string & str );
	
	static string to_lower_case( const string & str );
	
	//other useful functions for string conversion ... I should change string_to_uint and string_to_double functions for the standard functions in the code ... but I'm too lazy sometimes ... moreover, if it works, do not repair it. FunTom of the Blue Screen
	/*
	<cstdlib> (stdlib.h)
	C Standard General Utilities Library
	This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.

	Functions
	String conversion

	atof
		Convert string to double (function )

	atoi
		Convert string to integer (function )

	atol
		Convert string to long integer (function )

	atoll
		Convert string to long long integer (function )

	strtod
		Convert string to double (function )

	strtof
		Convert string to float (function )

	strtol
		Convert string to long integer (function )

	strtold
		Convert string to long double (function )

	strtoll
		Convert string to long long integer (function )

	strtoul
		Convert string to unsigned long integer (function )

	strtoull
		Convert string to unsigned long long integer (function )*/

};


#endif // STRINGUTIL_H
