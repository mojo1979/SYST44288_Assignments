/* Filename: buffer.c
 * Name(s): Daniel Nawrocki, John Mo
 * Created: November 1st, 2019 8:00 AM
 * Program Title: Final Programming Project - Producer and Consumer Problem
 * Program Description: This C Program takes a look at the Producer and Consumer Problem and provides a solution via counting semaphores.
 *
 */

// Includes, Typedefs and Defines
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <time.h>
#include "buffer.h"

// Global Variables
sem_t full, empty;
buffer_item buffer[BUFFER_SIZE];
int front = 0, rear = 0;

// Function Prototypes
void* producer (void* param);
void* consumer (void* param);
int insert_item (buffer_item item);
int remove_item (buffer_item *item);

// Main Function
int main (int argc, char* argv[]) {
  // Begin coding here!
  if (argc - 1 != 3) {
    fprintf(stderr, "Usage: semi <run duration> <number of producer threads> <number of consumer threads>");
    return -1;
  }
  int napTime = strtol(argv[1], NULL, 10), numProd = strtol(argv[2], NULL, 10), numCon = strtol(argv[3], NULL, 10);
  srand(time(0));
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);
  int Producer_PThreads[numProd], Consumer_PThreads[numCon];
  pthread_t workerThreads[numProd+numCon];

  return 0;
}

// Function Definitions
void* producer (void* param) {
  buffer_item item;
  while (1) {
    sleep((rand()%5)+1);
    item = rand();
    sem_wait(&empty);
    if(!insert_item(item)){
      printf("Producer produced %d\n", item);
    } else {
      fprintf(stderr,"Producer Thread: Failed to insert item!");
    }
    sem_post(&full);
  }
}

void* consumer (void* param) {
  // Consumer Thread
}

int insert_item (buffer_item item) {
  buffer[front] = item;
  if (front == (BUFFER_SIZE-1)) {
    front = 0;
    return 0;
  } else {
    front++;
    return 0;
  }
  return -1;
}

int remove_item (buffer_item* item) {
  // Remove Function
  return 0;
}
