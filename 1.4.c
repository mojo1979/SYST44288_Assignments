/* Filename: 1.4.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 6th, 2019 3:00 AM
 * Program Title: Assignment 1 Part 4
 * Program Description: Implements a function (rmstr) to remove a set of characters from a string
 */

// Headers and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// Function Prototypes
void rmstr ( char * str1, char * str2 );

// Main
int main ( int argc, char *argv[] ) {
	// call rmstr with strings argv[1] and argv[2] as parameters
	rmstr( argv[1], argv[2] );

	// print resulting string after rmstr execution
	printf( "%s\n", argv[1] );
	return 0;
}

// Functions
void rmstr ( char * str1, char * str2 ) {
	// iterate throught the second string
	for( int k = 0; k < strlen(str2); k++ ){

		// Iterate through the first string
		for( int i = 0; i < strlen(str1); i++ ) {

			// If current character is equal to character to remove
			if ( str1[i] == str2[k] ) {

				// Starting at index i, shift all letters down
				int j = i + 1;
				while ( str1[j] != 0 ) {
					str1[j - 1] = str1[j];
					j++;
				}

				// Set last char as string terminator char val 0
				str1[strlen(str1)-1] = 0;

				// Set index back to check if char is still equal to character to remove
				i--;
			}
		}
	}
}
