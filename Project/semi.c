/* Filename: semi.c
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

typedef int buffer_item;
#define BUFFER_SIZE 5

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
  return 0;
}

// Function Definitions
void* producer (void* param) {
  //Producer Thread
}

void* consumer (void* param) {
  // Consumer Thread
}

int insert_item (buffer_item item) {
  // Insert Function
  return 0;
}

int remove_item (buffer_item* item) {
  // Remove Function
  return 0;
}
