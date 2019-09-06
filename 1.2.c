/* Filename: 1.2.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 6th, 2019 3:00 AM
 * Program Title: Assignment 1
 * Program Description: This program calculates euler's totient (phi) of a range
 											  of numbers.
 */

// Headers and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>

// Function Prototypes
int gcd ( int x, int y );

// Main
int main ( int argc, char *argv[] ) {
	// Begin Coding Here!

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
