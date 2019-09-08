/* Filename: 1.1.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 6th, 2019 3:00 AM
 * Program Title: Assignment 1
 * Program Description: This program lists out Armstrong Numbers based on user parameters entered at execution.
 */

// Headers and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

// Function Prototypes
bool isArmstrongNumber ( int power, int number );

// Main
int main ( int argc, char *argv[] ) {
	// Begin Coding Here!
	
	return 0;
}

// Functions
bool isArmstrongNumber ( int power, int number ) {
	// Local variables to hold sum of powered digits and digit divisor
	int sum = 0, digitCount = 0, value = number;

	// Count the digits and sum power of current digit
	do {
		sum += pow( value % 10, power );
		value = value / 10;
		digitCount++;
	} while ( value != 0 );

	// if sum equals the number it is an Armstrong Number
	if ( number == sum && power == digitCount ) {
		return true;
	}
	return false;
}
