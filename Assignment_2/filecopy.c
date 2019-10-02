/* Filename: filecopy.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: September 14th, 2019 8:30 PM
 * Program Title: Assignment 2 Question 2 - FileCopy
 * Program Description: This program copies one text file to another using file IO, pipes and forks
 */

// Headers, Defines and Gl. Variable Declarations
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

#define STRING_BUF_SIZE 255

// Function Prototypes
void readFileToPipe(int *fd, FILE **fPtr);
void writeFileFromPipe(int *fd, FILE **fPtr);
int initFiles(char *inFileName, char *outFileName, FILE **inPtr, FILE **outPtr);

// Main
int main (int argc, char *argv[]) {

  // Variables and pointers
  int pfd[2], pid, pipeRes;
  FILE *inputPtr, *outputPtr;

  // Check argument length, display usage message if not enough arguments
  if (argc > 3 || argc < 3) {
    fprintf(stderr, "Usage: filecopy <source_file> <destination_file>\n");
    return -1;
  }

  // Store Pipe result and exit w/error if pipe failed
  pipeRes = pipe(pfd);

  if (pipeRes < 0) {
    perror("pipe() failed");
    return -1;
  }

  // Initialize files and exit if error exist for source or destination file
  if (initFiles (argv[1], argv[2], &inputPtr, &outputPtr) == -1) {
    return -1;
  }

  // Fork() and store pid in int variable
  pid = fork();

  if (pid > 0) {

    // If pid > 0 (parent) read file to pipe
    readFileToPipe(pfd, &inputPtr);

    // Close file stream when done
    fclose(inputPtr);

    // wait for child to finish task
    wait(NULL);
  } else if (pid < 0) {

    // Exit on fork() error
     perror("fork() failed");
  } else {

    // if pid == 0 (child), write pipe content to file
    writeFileFromPipe(pfd, &outputPtr);

    // Close File stream when done
    fclose(outputPtr);
  }

	return 0;
}

// Functions
void readFileToPipe(int *fd, FILE **fPtr) {

  // Close read end of pipe (not needed for writing)
  close(fd[0]);

  // Init a string buffer and read contents of file and write them to pipe
  char strBuf[STRING_BUF_SIZE];
  while (fgets(strBuf, STRING_BUF_SIZE, *fPtr) != NULL) {
    write(fd[1], strBuf, STRING_BUF_SIZE);
  }

  // close write end of pipe when done
  close(fd[1]);
}

void writeFileFromPipe(int *fd, FILE **fPtr) {
  // Close write end of pipe (not needed for reading)
  close(fd[1]);

  // Init a string buffer and read contents of pipe and write them to file
  char strBuf[STRING_BUF_SIZE];
  int numSize;
  while ((numSize = read(fd[0], strBuf, STRING_BUF_SIZE)) > 0) {
    fputs(strBuf, *fPtr);
  }

  //  Close read end of pipe when done
  close(fd[0]);
}

int initFiles(char *inFileName, char *outFileName, FILE **inPtr, FILE **outPtr) {

  // Open source (input) file with read permissions into inPtr
  *inPtr = fopen(inFileName, "r");

  // Return error when fopen() fails for inPtr
  if (*inPtr == NULL) {
    perror("fopen() failed");
    return -1;
  }

  // Open destination (output) file with write permissions (create file if it doesn't exist) into outPtr
  *outPtr = fopen(outFileName, "w+");

  // Return error when fopen() fails for outPtr
  if (*outPtr == NULL) {
    perror("fopen() failed");
    return -1;
  }
}
