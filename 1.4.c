/* Filename: 1.4.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 6th, 2019 3:00 AM
 * Program Title: Assignment 1
 * Program Description: Implements a function (rmstr) to remove a set of characters from a string
 */

// Headers and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// Function Prototypes
void rmstr ( char * x, char * y );

// Main
int main ( int argc, char *argv[] ) {
	// Begin Coding Here!
	rmstr( argv[1], argv[2] );
	printf("%s\n", argv[1]);
	return 0;
}

// Functions
void rmstr ( char * x, char * y ) {

	for(int k=0; k < strlen(y); k++){
		for( int i = 0; i < strlen(x); i++) {

			// If current character is equal to character to remove
			if ( x[i] == y[k] ) {

				// Starting at index i, shift all letters down
				int j = i + 1;
				while (x[j] != 0) {
					x[j - 1] = x[j];
					j++;
				}

				// Set last char as string terminator char val 0
				x[strlen(x)-1] = 0;

				// Set index back to check if char is still equal to character to remove
				i--;
			}
		}
	}





















	// for( int i = 0; i < strlen(x); i++) {
	// 	for(int j = 0; j< strlen(y); j++)
	// 	{
	// 		if(x[i] == y[j])
	// 		x[i] = x[i+1];
	// 	}

}
