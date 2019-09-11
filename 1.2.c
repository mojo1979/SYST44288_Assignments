/* Filename: 1.2.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 6th, 2019 3:00 AM
 * Program Title: Assignment 1 Part 2
 * Program Description: This program calculates euler's totient (phi) of a range of numbers.
 */

// Headers and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>

// Function Prototypes
int gcd ( int x, int y );
int phi ( int x );

// Main
int main ( int argc, char *argv[] ) {
	// looping through all arguments starting from argv[1] to find phi for each arg.
	for(int i = 1 ; i<argc; i++){
		int number = strtol(argv[i], NULL, 10);
		printf("phi(%d) is %d\n", number, phi(number));
	}

	return 0;
}

// Functions
int gcd ( int x, int y ) {
	// End Euclidean Algorithm when remainder is zero
	if ( y == 0 ) {

		// Return GCD value
		return x;
	}

	// Continue Euclidean Algorithm Recursively
	return gcd( y, x % y );
}

int phi ( int x ) {
	//Initalize relative prime count to 0
	unsigned int count = 0;
	for ( int i = 1; i < x; i++ ) {

		//Increase count if current number is GCD = 1 with x
		if ( gcd( i, x ) == 1 ) {
			count++;
		}
	}

	//Return phi(x) = count
	return count;
}
