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
pthread_mutex_t lockBuffer;
buffer_item buffer[BUFFER_SIZE];
int front = 0, rear = 0, sleepMax;

// Function Prototypes
void* producer (void* param);
void* consumer (void* param);
int insert_item (buffer_item item);
int remove_item (buffer_item *item);

// Main Function
int main (int argc, char* argv[]) {
  if (argc - 1 != 3) {
    fprintf(stderr, "Usage: buffer <run duration> <number of producer threads> <number of consumer threads>\n");
    return -1;
  }

  //Init Vars, Threads, Semas and Mutex
  int numProd = strtol(argv[2], NULL, 10), numCon = strtol(argv[3], NULL, 10);
  sleepMax = strtol(argv[1], NULL, 10);
  srand(time(0));
  sem_init(&empty, 0, BUFFER_SIZE);
  sem_init(&full, 0, 0);
  pthread_mutex_init(&lockBuffer, NULL);
  int Producer_PThreads[numProd], Consumer_PThreads[numCon];
  pthread_t workerThreads[numProd+numCon];

  // Start Producer and Consumer threads
  for (int i = 0; i < numProd; i++) {
    Producer_PThreads[i] = pthread_create(&workerThreads[i], NULL, producer, NULL);
  }
  for (int i = numProd; i < numProd+numCon; i++) {
    Consumer_PThreads[i-numProd] = pthread_create(&workerThreads[i], NULL, consumer, NULL);
  }

  // Wait for argument defined amount of seconds
  sleep(sleepMax);

  // Exit after waiting
  return 0;
}

// Function Definitions
void* producer (void* _param) {
  buffer_item item;
  while (1) {

    // Sleep for random time between half of main sleep and 1 second.
    sleep((rand()%sleepMax/2)+1);

    // Generate a random buffer_item.
    item = rand();

    // Counting semaphore for empty space in buffer. If empty, sema does not wait.
    sem_wait(&empty);

    // Lock the buffer, if it is already locked, wait for unlock.
    pthread_mutex_lock(&lockBuffer);

    // Insert and print generated item.
    if(!insert_item(item)){
      printf("Producer produced %d\n", item);
    } else {
      fprintf(stderr,"Producer Thread: Failed to insert item!\n");
    }

    // Unlock buffer when done.
    pthread_mutex_unlock(&lockBuffer);

    // Signal counting semaphore that a slot in queue is full.
    sem_post(&full);
  }
}

void* consumer (void* _param) {
  buffer_item item;
  while (1) {

    // Sleep for random time between half of main sleep and 1 second.
    sleep((rand()%sleepMax/2)+1);

    // Wait for a full slot in queue. If signaled, continue.
    sem_wait(&full);

    // Lock the buffer, wait for unlock if locked already.
    pthread_mutex_lock(&lockBuffer);

    // Remove and print item
    if(!remove_item(&item)){
      printf("Consumer consumed %d\n", item);
    } else {
      fprintf(stderr, "Consumer Thread: Failed to remove item!\n");
    }

    // Release buffer when done (unlock).
    pthread_mutex_unlock(&lockBuffer);

    // Signal counting semaphore 1 empty spot.
    sem_post(&empty);
  }
}

int insert_item (buffer_item item) {

  //insert item into buffer
  buffer[front] = item;

  // Advance front index by 1. If front index reached end of array, set front to 0.
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

  // Read buffer at rear index to output
  *item = buffer[rear];

  // Advance rear index by 1. If rear index reached end of array, set rear to 0.
  if (rear == (BUFFER_SIZE-1)) {
    rear = 0;
    return 0;
  } else {
    rear++;
    return 0;
  }
  return -1;
}
