//header file representing a queue with max size of 100
//queue stores integers as data
//author: fmoham26 (Fawaz Mohammad)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#ifndef QUEUE_H
#define QUEUE_H //prevents errors that occur when this file referenced multiple times
#define MAX_QUEUE_SIZE 100
#define TRUE 1
#define FALSE 0
typedef int Item;
typedef int bool;


void make_empty(void); //initalizes queue
bool is_empty(void); //checks if queue is empty
bool is_full(void); //checks if queue is full
void enqueue(Item i); //adds item to end of queue
Item dequeue(void); //removes item from front of queue and returns data stored in it
Item first(void); //returns data stored in front of queue
Item last(void); //returns data stored at end of queue
#endif
