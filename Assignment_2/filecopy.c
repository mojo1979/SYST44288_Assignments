/* Filename: filecopy.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 14th, 2019 8:30 PM
 * Program Title: Assignment 2 Question 2 - FileCopy
 * Program Description: This program copies one file to another using file IO and pipes
 */

// Headers and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

// Function Prototypes
void readFIleToPipe();
void writeFileFromPipe();

// Main
int main ( int argc, char *argv[] ) {
	// Begin coding here!
  if ( argc > 3 || argc < 3 ) {
    printf("Usage: filecopy source_file destination_file\n");
    return 0;
  }
  int pInOut[2], pid, pipeRes;
  pipeRes = pipe(pInOut);
  if (pipeRes < 0) {
    fprintf(stderr, "Pipe failed to initialize! Error Code: %d", pipeRes);
    return 0;
  }
  printf("Pipe initialized! You may continue to program!");

  //pid = fork();
  /*if (pid == 0) {

  } else {

  }*/

	return 0;
}

// Functions
