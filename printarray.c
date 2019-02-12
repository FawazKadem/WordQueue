// initializes array and prints it using pointers/pointer arithmetic
// author: fmoham26 (Fawaz Mohammad)
// compiled and tested on obelix
#include <stdio.h>
#include <stdlib.h>


int main()
{

	int i; 
	int *arr = (int *)malloc(9 * sizeof(int)); //allocates memory for 9 integers
	int *p;
	p = arr;

	arr[0] = 12;

	for(i = 1 ; i < 8 ;i++){  //populates array other than first and last element
		arr[i] = arr[i-1] + 11;
	}

	arr[8] = 90;


	
	// print the value and the address of each element of array
	for (i = 0 ; i < 9 ; i++)
	{
		printf("arr[%d]: value is %d and address is %p\n", i, p[i], &p[i]); //prints iteration using index of array
		printf("arr[%d]: value is %d and address is %p\n", i, *(p+i), (p+i)); //prints iteration using pointer arithmetic
	}
return 0;

}
