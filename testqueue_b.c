//program which implements a queue using an array
//author: fmoham26 (Fawaz Mohammad)
//compiled and tested on obelix

#include "queue.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//index position that next element will go in
//index position of element that is next to be removed
//number of elements in queue, respectively
int firstEmpty, nextOut, size;

//initialize array
Item arrayQueue[MAX_QUEUE_SIZE];

//sets variables for empty array
void make_empty(){
	

	
	firstEmpty = 0;
	size = 0;



}

//returns whether or not queue is empty
bool is_empty(){
	return (size == 0);


}

//returns whether or not queue is full
bool is_full(){
	return (size == MAX_QUEUE_SIZE);
}

//adds item to end of queue
void enqueue(Item i){

	if (is_full()){ //error if queue is full
		printf("Queue is full. Cannot enqueue another item\n");
	}

	else{
		
		if (is_empty()){
			nextOut = 0;
		}
		arrayQueue[firstEmpty] = i;
		firstEmpty++;
		firstEmpty = firstEmpty % MAX_QUEUE_SIZE; //allows queue to wrap around
		size++;

	}

	

}

//removes first item in queue and returns data stored in it
Item dequeue(){

	Item result;
	if (is_empty()){ //error if queue is empty
		printf("Queue is empty. Cannot dequeue.\n");
		return 0;
	}
	else if (size == 1){ //if queue only has one item

		result = arrayQueue[nextOut];
		nextOut = -1;

		size = 0;
		firstEmpty = 0;


	}
	else{ 
		result = arrayQueue[nextOut];

		nextOut++;
		nextOut = nextOut % MAX_QUEUE_SIZE; //allows queue to wrap around
		size--;


	}

return result;

}

//returns data stored in first index of queue (not array)
Item first(){

	if (is_empty()){
		printf("Queue is empty. There is no first item.\n");
		return 0;
	}
	return arrayQueue[nextOut];

}

//returns data stored in last index of queue (not array)
Item last(){

	if (is_empty()){
		printf("Queue is empty. There is no last item.\n");
		return 0;
	}

	if (firstEmpty = 0){
		return arrayQueue[MAX_QUEUE_SIZE - 1];
	}

	return arrayQueue[firstEmpty - 1];

}

//creates queue, enqueues and dequeues items from it
int main(){

	make_empty();
	enqueue(45);
	enqueue(67);
	enqueue(78);
	enqueue(34);
	enqueue(675);
	enqueue(23);
	enqueue(756);

	
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	enqueue(42);
	
	while (size > 0){
		printf("%d\n", dequeue());
	}

	

return 0;
}
