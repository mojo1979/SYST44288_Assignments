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

// Global variables
int avgResult = 0;
int minResult = 0;
int maxResult = 0;

// Function Prototypes
void *thread_CalcAvg(void *vargp);
void *thread_CalcMax(void *vargp);
void *thread_CalcMin(void *vargp);

// Main Function
int main (int argc, char *argv[]) {
	pthread_t threadId[3];
	if (argc == 1) {
		fprintf(stderr, "Usage: stats <num 1> <num 2> <num 3> ... <num n>");
		return -1;
	}

	int numbers[argc - 1];
	for (int i = 1; i < argc; i++) {
		// Get values
		errno = 0;
		numbers[i-1] = strtol(argv[i], NULL, 10);
		/*if (errno == && numbers[i-1] == ) {

		}*/
	}
	pthread_create(&threadId[0], NULL, thread_CalcAvg, NULL);
	pthread_create(&threadId[1], NULL, thread_CalcMax, NULL);
	pthread_create(&threadId[2], NULL, thread_CalcMin, NULL);

  // Wait for threads to finish
	for (int i = 0; i < 3; i++) {
		pthread_join(threadId[i], NULL);
	}

	return 0;
}

// Functions
 void *thread_CalcAvg(void *vargp) {
	 printf("Calculated Average\n");
 }

 void *thread_CalcMax(void *vargp) {
	 printf("Calculated Max\n");
 }

 void *thread_CalcMin(void *vargp) {
	 printf("Calculated Min\n");
 }
