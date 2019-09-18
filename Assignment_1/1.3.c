/* Filename: 1.3.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 6th, 2019 3:00 AM
 * Program Title: Assignment 1 Part 3
 * Program Description: Implements an function (rmchr) to remove a character from a string.
 */

// Headers and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// Function Prototypes
void rmchr ( char * str, char c );

// Main
int main ( int argc, char *argv[] ) {
	// Call rmchr with argv[1] as string and argv[2][0] as char to remove
	rmchr(argv[1],argv[2][0]);

	// Print resulting string from argv[1]
	printf("%s\n", argv[1]);

	return 0;
}

// Functions
void rmchr ( char * str, char  c ){
	// For each charater of the string
	for( int i = 0; i < strlen(str); i++) {

		// If current character is equal to character to remove
		if ( str[i] == c ) {

			// Starting at index i, shift all letters down
			int j = i + 1;
			while (str[j] != 0) {
				str[j - 1] = str[j];
				j++;
			}

			// Set last char as string terminator char val 0
			str[strlen(str)-1] = 0;

			// Set index back to check if char is still equal to character to remove
			i--;
		}
	}
}
