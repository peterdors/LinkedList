// TODO: find most frequently occurring number in the linked list of random ints
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "LinkedList.h"
int findMaxNumberInList(LinkedList *list)
{
	node *temp;
	int max = 0;
	int i;

	if (list == NULL || list->head == NULL) 
		return EMPTY_LIST_ERR; 

	temp = list->head;
	max = temp->data;

	for (i = 0; i < list->size-1; i++)
	{	
		if (temp && max < temp->data)
		{	
			max = temp->data;
			temp = temp->next;
		}
	}

	return max;
}


int findMaxArrayValue(int *array, int n)
{
	int i;
	int max_counter = array[0];
	int max_val = 0;
	// start at one because we assign 
	// max to be the first value in the array
	for (i = 1; i < n; i++)
	{
		if (max_counter < array[i])
			max_val = i;
	}

	return max_val;
}

// Given(s): 
// 	1. the number of elements in the linked list via list->size 
int findMostFrequent(LinkedList *list)
{
	int *array, max, i;
	node *temp;
	int size;

	if (list == NULL || list->head == NULL) 
		return EMPTY_LIST_ERR; 

	temp = list->head;
	// allocate memory for the size of the array
	size = findMaxNumberInList(list);
	// NOTE this only works for binary (0's and 1's)
	array = calloc(size + 1, sizeof(int));

	// Go through the entire list, inserting into
	// the array for what is in the list data
	for (i = 0; i < list->size; i++)
	{
		if (temp != NULL)
		{				
			(array[temp->data])++; 
			temp = temp->next;
		}
	}

	max = findMaxArrayValue(array, size);

	printf("\nThe most frequently occurring number in the list is: %d\n", max);
	
	free (array);
	return max;
}

int main(int argc, char **argv)
{
	int k = 4;

	if (argc < 2)
		return 1;

	LinkedList *list = buildRandomSortedList(atoi(argv[1]));

	findMostFrequent(list);

	printList(list);
	printf("\n");

	return 0;
}
