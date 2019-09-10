/* Filename: 1.3.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 6th, 2019 3:00 AM
 * Program Title: Assignment 1
 * Program Description:
 */

// Headers and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>

// Function Prototypes
void rmchr ( char * x, char y );

// Main
int main ( int argc, char *argv[] ) {
	rmchr(argv[1],argv[2][0]);
	printf("%s\n", argv[1]);
	// Begin Coding Here!

	return 0;
}

// Functions
void rmchr ( char * x, char  y ){
	for(int i = 0; i<sizeof(x); i++){
		if (x[i] == y)
		{
			x[i] = x[i+1];
			for (int j = i+1; j < sizeof(x)-1; j++) {
				x[j] = x[j+1];
			}
		}
	}

}
