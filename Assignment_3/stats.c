/* Filename: stats.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: October 1st, 2019 5:30 PM
 * Program Title: Assignment 3 Question 1 - Stats
 * Program Description:
 */

// Headers, Defines and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<pthread.h>

// Function Prototypes

// Main
int main (int argc, char *argv[]) {
	if (argc == 1) {
		fprintf(stderr, "Usage: stats <num 1> <num 2> <num 3> ... <num n>");
		return -1;
	}

	int numbers[argc - 1];
	for (int i = 1; i < argc; i++) {
		// Get values
	}

	return 0;
}
