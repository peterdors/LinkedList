// Peter Dorsaneo

// LinkedList.c
// =============
// Linked lists. Supports head removal and tail insertion. Maintains head and
// tail pointers within a LinkedList struct. 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#include "LinkedList.h"

#define RANDOM_LIST_SIZE 100
// UTILITY FUNCTIONS
// =================
// function returns a random integer between 
// 1 and N, where N is the parameter to input
// must call srand(time(NULL)) within the function you are using this 
// rand function inside of. 
// otherwise will get repeats
int ret_rand_val(int n)
{
	return rand() % n + 1;
}

// CREATE FUNCTIONS
// ================
node *create_node(int data)
{
	node *n = malloc(sizeof(node));

	n->data = data;
	n->next = NULL;

	return n;
}

LinkedList *create_list(void)
{
	// This creates our linked list and 
	// sets the head and tail pointer to NULL.
	return calloc(1, sizeof(LinkedList));
}

// DESTROY FUNCTION
// ================
void recursive_destroy_list_helper(node *n)
{
	if (n == NULL)
		return;

	recursive_destroy_list_helper(n->next);
	free(n);
}

LinkedList *recursive_destroy_list(LinkedList *list)
{
	node *temp;

	if (list == NULL) 
		return NULL;

	if (list->head == NULL)
	{
		free(list);
		return NULL;
	}

	recursive_destroy_list_helper(list->head);

	free(list);
	return NULL;
}

LinkedList *destroy_list(LinkedList *list)
{
	node *temp;

	if (list == NULL) 
		return NULL;

	if (list->head == NULL)
	{
		free(list);
		return NULL;
	}
	
	while (list->head != NULL)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}

	list->size = 0;
	free(list);
	return NULL;
}

// INSERTION FUNCTIONS
// ===================
void tail_insert(LinkedList *list, int data)
{
	if (list == NULL) return;

	if (list->tail == NULL)
	{
		list->head = list->tail = create_node(data);
		list->size ++;
		return;
	}

	list->tail->next = create_node(data);

	list->tail = list->tail->next;
	(list->size)++;
}

void head_insert(LinkedList *list, int data)
{
	node *temp;

	if (list == NULL) return;

	if (list->head == NULL)
	{
		list->head = list->tail = create_node(data);
		list->size ++;
		return;
	}
	// store the current head
	temp = list->head;
	// set the new head
	list->head = create_node(data);
	// restore the linked list
	list->head->next = temp;
	list->size ++;
}

// POP/DEQUEUE/DELETE FUNCTIONS
// ============================
// returns the value of the head node 
// we deleted
int head_delete(LinkedList *list)
{
	node *temp;
	int retval;
	// error handling
	if (list == NULL || list->head == NULL) 
		return EMPTY_LIST_ERR;

	temp = list->head;
	retval = temp->data;

	list->head = list->head->next;

	free(temp);

	if (list->head == NULL)
		list->tail = NULL;

	(list->size)--;

	return retval;
}

int tail_delete(LinkedList *list)
{
	node *new_tail, *old_tail, *temp;
	int retval;
	
	// error handling
	if (list == NULL || list->head == NULL) 
		return EMPTY_LIST_ERR;

	temp = list->head;

	// if the next item in the list is the tail
	// then we will want to stop at the node
	// prior to the tail.
	while (temp->next != list->tail)
	{
		temp = temp->next;
	}

	new_tail = temp;
	old_tail = temp->next;

	new_tail->next = NULL;
	list->tail = new_tail;

	retval = old_tail->data;
	
	(list->size)--;

	free(old_tail);
	return retval;
}

// deletes the node at index k in the list
int kth_delete(LinkedList *list, int k)
{
	// want to go through the list k number of times
	// then delete the node we land on. 
	// i.e. delete the k'th node
	node *temp, *node_to_delete;
	int i, retval;

	// error handling
	if (list == NULL || list->head == NULL || k > list->size) 
		return EMPTY_LIST_ERR;

	temp = list->head;

	// should stop at the node prior to the
	// node we want to delete
	while (i < k-1)
	{	
		if (temp->next != NULL)
			temp = temp->next;
		else
			return EMPTY_LIST_ERR;

		i++;
	}
	// store the return value
	// i.e. the node to be deleted
	retval = temp->next->data;
	// reference the node to be deleted
	node_to_delete = temp->next;
	// set the new next of the node prior to 
	// deleting to be the next of the save node 
	// (the node we are deleting)
	temp->next = node_to_delete->next;

	free(node_to_delete);
	return retval;
}



// SEARCH FUNCTIONS
// ================
// Returns the k'th element in the linked list.
// if k is greater than the list->size then return error
int kth_element(LinkedList *list, int k)
{
	int i = 0;
	node *temp;

	if (list == NULL || list->head == NULL) 
		return EMPTY_LIST_ERR; 

	temp = list->head;
	// start i at 1 because we are already at the head of the list
	// i.e. we are already at the first element in the list
	// if it is not NULL...
	for (i = 1; i < k; i++)
	{
		if (temp == NULL)
		{
			return EMPTY_LIST_ERR; 
		}

		temp = temp->next;
	}

	return temp->data;
}

// returns the pointer to the N'th node as indicated 
// in the parameter
node *kth_node(LinkedList *list, int k)
{
	int i = 0;
	node *temp;

	if (list == NULL || list->head == NULL) 
		return NULL; 

	temp = list->head;

	// start i at 1 because we are already at the head of the list
	// i.e. we are already at the first element in the list
	// if it is not NULL...
	for (i = 1; i < k; i++)
	{
		if (temp == NULL)
		{
			return NULL; 
		}

		temp = temp->next;
	}

	return temp;
}

// returns the data in the node specified
// mainly used for checking our head and tail pointers
int peek_helper(node *curr)
{
	return curr == NULL ? EMPTY_LIST_ERR : curr->data;
}

// option parameter is used for choosing
// whether to peek at the head (option = 0)
// or to peek at the tail (option = 1) 
int peek(LinkedList *list, int option)
{
	if (list == NULL) 
		return EMPTY_LIST_ERR;

	if (option <= 0)
		return peek_helper(list->head);
	else if (option >= 1)
		return peek_helper(list->tail);
	else
		return EMPTY_LIST_ERR;
}


// RANDOM LIST GENERATORS
// ======================
// builds the random list and inserts at the head
// creates a random list of ints between 1 and RANDOM_LIST_SIZE
LinkedList *build_random_list(int n)
{
	int i;
	srand(time(NULL));

	LinkedList *list = create_list();

	// inserting n numbers of data into the list
	for (i = 0; i < n; i++)
	{
		// inserts either a 1 or a 0 into the LinkedList.
		head_insert(list, ret_rand_val(RANDOM_LIST_SIZE));	
	}

	list->size = n;
	return list;
}


/* BAD FUNCTION CURRENTLY WORK IN PROGRESS

	// builds the random list and inserts at the head
	// creates a random list of ints between 0 and 1
	LinkedList *buildRandomSortedList(int n)
	{
		srand(time(NULL));
		int i, num;
		LinkedList *list = create_list();
		node *temp1, *save;

		// sorted insert of a linked list
		// traverse thorugh the list until we hit a value greater than
		// the value we are inserting

		// lets insert some data and set our tail as well...
		list->head = create_node(ret_rand_val());
		list->tail = list->head;


		for (i = 0; i < n-1; ++i)
		{
			temp1 = list->head;
			// want to create a random node
			// and insert it into our list 
			// in sorted arrangement
			num = ret_rand_val();
			// temp1 = temp;
			
			while (num > temp1->data)
			{
				if (temp1->next != NULL)
				{
					temp1 = temp1->next;
				}			
				else
				{
					// handle null fall out case by 
					// creating a node at the end of the list
					temp1->next = create_node(num);
					// and set our new tail pointer
					list->tail = temp1->next;
				}

			}
			
			// otherwise we iterate through the while loop
			// and we have to handle a case of inserting 
			// in between nodes of the linked list
			// without destroying our list...

			// save the next of temp1
			save = temp1->next;
			// insert the new node in sorted order
			temp1->next = create_node(num);		
			// restore the saved node
			temp1->next->next = save;
		}


		list->size += n;
		return list;
	}

*/


// PRINT LIST FUNCTIONS
// ====================

// prints the list from the head
void print_list(LinkedList *list)
{
	node *temp;

	printf("Here is the list: ");

	if (list == NULL || list->head == NULL) 
	{
		printf("(empty list)\n");
		return;
	}

	temp = list->head;

	while (temp != NULL)
	{
		printf("%d%c", temp->data, temp->next == NULL ? '\n' : ' ');
		temp = temp->next;
	}
}


// SORTING FUNCTIONS
// =================
// sorting function that utilizes the bubble sort algorithm
// to sort a linked list if it's out of wack!
void sort_linked_list(LinkedList *list)
{
	node *curr, *next;
	int swapped = 1;
	int i, j = 0, temp;

	if (list == NULL || list->head == NULL) 
		return;

	while (swapped)
	{
		swapped = 0;

		curr = list->head;
		next = curr->next;

		for (i = 0; i < list->size - 1 - j; ++i)
		{
			if (next == NULL)
				break;

			if (curr->data > next->data)
			{
				temp = curr->data;
				curr->data = next->data;
				next->data = temp;
				// swapped set to one so we continue the while loop
				swapped = 1;
			}
			curr = curr->next;
			next = next->next;
		}
		++j;
	}

	
}
