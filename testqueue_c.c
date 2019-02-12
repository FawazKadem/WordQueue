//program which implements a queue using a singly linked list
//author: fmoham26 (Fawaz Mohammad)
//compiled and tested on obelix

#include "queue.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structure representing a node
//stores data and pointer to next node
struct node
{
	Item value;
	struct node *next;

}*firstNode, *lastNode, *current;

int size; // number of nodes in list

//initializes empty queue
void make_empty(){
	firstNode = lastNode = NULL;
	size = 0;


}

//returns true (1) if queue is empty, false (0) otherwise
bool is_empty(){
	return (size == 0);
}

//returns true (1) if queue is full, false (0) otherwise
bool is_full(){
	return (size == MAX_QUEUE_SIZE);
}



//adds given item to end of queue
void enqueue(Item i){

	


	if (is_full()){ //error that occurs if queue is full
		printf("Queue is full. Cannot enqueue another item\n");
	}
	else{

		current = (struct node*) malloc(sizeof(struct node)); //allocate memory for new node
		current->next = NULL; 
		current->value = i;

		
		if (is_empty()){

			firstNode = lastNode = current;
			size++;
		}
		else{
			lastNode->next = current;
			lastNode = lastNode->next; 
			size++;
		}
	}
}

//removes node from front of queue and returns data stored in it
Item dequeue(){


	struct node *placeholder; // placeholder node for node to be removed
	Item returnData;

	if (is_empty()){ //error which occures if queue is empty
		printf("Queue is empty. Cannot dequeue item\n");
		return 0;
	}
	else{
		returnData = firstNode->value;
		placeholder = firstNode;
		firstNode = firstNode -> next;
		free(placeholder);
		size--;
		return returnData;

	}
}

//returns data stored in first node
Item first(void){
	if (is_empty()){
		printf("Queue is empty. First node is null and contains no data\n");
		return 0;
	}
	else {
		return firstNode->value;
	}

}

//returns data stored in last node
Item last(void){
	if (is_empty()){
		printf("Queue is empty. Last node is null and contains no data\n");
		return 0;
	}
	else {
		return lastNode->value;
	}

}

//creates a queue, enqueues and dequeues items.
int main(){

	make_empty();
	printf("%d\n", dequeue());
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
