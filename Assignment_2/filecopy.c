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

#define STRING_BUF_SIZE 255

// Function Prototypes
void readFileToPipe(int *fd, FILE **fPtr);
void writeFileFromPipe(int *fd, FILE **fPtr);
int initFiles(char *inFileName, char *outFileName, FILE **inPtr, FILE **outPtr);

// Main
int main (int argc, char *argv[]) {
	// Begin coding here!
  int pfd[2], pid, pipeRes;
  FILE *inputPtr, *outputPtr;

  if (argc > 3 || argc < 3) {
    fprintf(stderr, "Usage: filecopy source_file destination_file\n");
    return -1;
  }

  pipeRes = pipe(pfd);

  if (pipeRes < 0) {
    perror("pipe() failed");
    return -1;
  }

  if (initFiles (argv[1], argv[2], &inputPtr, &outputPtr) == -1) {
    return -1;
  }

  pid = fork();

  if (pid > 0) {
    printf("I'm a Parent! PID = %d\n", pid);
    readFileToPipe(pfd, &inputPtr);
    fclose(inputPtr);
    wait(NULL);
  } else if (pid < 0) {
     perror("fork() failed");
  } else {
    printf("I'm a Child! PID = %d\n", pid);
    writeFileFromPipe(pfd, &outputPtr);
    fclose(outputPtr);
  }
	return 0;
}

// Functions
void readFileToPipe(int *fd, FILE **fPtr) {
  close(fd[0]);
  char strBuf[STRING_BUF_SIZE];
  while (fgets(strBuf, STRING_BUF_SIZE, *fPtr) != NULL) {
    write(fd[1], strBuf, STRING_BUF_SIZE);
  }
  close(fd[1]);
}

void writeFileFromPipe(int *fd, FILE **fPtr) {
  close(fd[1]);
  char strBuf[STRING_BUF_SIZE];
  int numSize;
  while ((numSize = read(fd[0], strBuf, STRING_BUF_SIZE)) > 0) {
    fputs(strBuf, *fPtr);
  }
  close(fd[0]);
}

int initFiles(char *inFileName, char *outFileName, FILE **inPtr, FILE **outPtr) {
  *inPtr = fopen(inFileName, "r");

  if (*inPtr == NULL) {
    perror("fopen() failed");
    return -1;
  }

  *outPtr = fopen(outFileName, "w+");

  if (*outPtr == NULL) {
    perror("fopen() failed");
    return -1;
  }
}
