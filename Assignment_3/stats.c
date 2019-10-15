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
int numOfValues = 0;

// Function Prototypes
void *thread_CalcAvg(void *numArray);
void *thread_CalcMax(void *numArray);
void *thread_CalcMin(void *numArrayS);

// Main Function
int main (int argc, char *argv[]) {
	pthread_t threadId[3];
  numOfValues = argc - 1;

	if (argc == 1) {
		fprintf(stderr, "Usage: stats <num 1> <num 2> <num 3> ... <num n>");
		return -1;
	}

	int numbers[numOfValues];
	for (int i = 1; i < argc; i++) {
		// Get values
		errno = 0;
		numbers[i-1] = strtol(argv[i], NULL, 10);
		/*if (errno == && numbers[i-1] == ) {

		}*/
	}

	// Start the threads
	pthread_create(&threadId[0], NULL, thread_CalcAvg, numbers);
	pthread_create(&threadId[1], NULL, thread_CalcMax, numbers);
	pthread_create(&threadId[2], NULL, thread_CalcMin, numbers);

  // Wait for threads to finish
	for (int i = 0; i < 3; i++) {
		pthread_join(threadId[i], NULL);
	}
	printf("Average value is\n%d\n",avgResult);
	printf("Minimum value is\n%d\n",minResult);
	printf("Maximum value is\n%d\n",maxResult);

	return 0;
}

// Functions
 void *thread_CalcAvg(void *numArray) {
	 int *values = (int *)numArray;
	 for (int i = 0; i < numOfValues; i++)
	   avgResult += values[i];
	 avgResult = avgResult/numOfValues;
 }

 void *thread_CalcMax(void *numArray) {
	 int *values = (int *)numArray;
	 for (int i = 0; i < numOfValues; i++){
		 if (i == 0) {
			 maxResult = values[i];
		 } else if (values[i] > maxResult) {
			 maxResult = values[i];
		 }
	 }
 }

 void *thread_CalcMin(void *numArray) {
	 int *values = (int *)numArray;
	 for (int i = 0; i < numOfValues; i++){
		 if (i == 0) {
			 minResult = values[i];
		 } else if (values[i] < minResult) {
			 minResult = values[i];
		 }
	 }
 }
