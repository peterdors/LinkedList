// Peter Dorsaneo

// LinkedList.h
// =============
// Header file for linked lists code. Includes struct definitions and functional
// prototypes. This library supports head removal and tail insertion. Maintains
// head and tail pointers within a LinkedList struct.
// Credit: Dr. Sean Szumlanski @ UCF

#ifndef __LINKEDLIST_H  // This is an include guard. It's fantastic!
#define __LINKEDLIST_H

#define EMPTY_LIST_ERR INT_MIN

typedef struct node
{
	int data;
	struct node *next;
} node;

typedef struct LinkedList
{
	node *head;
	node *tail;
	int size; // keeps track of the number of nodes in the linked list
} LinkedList;

// Functional prototypes. Notice that I only included functional prototypes for
// functions that we'd want to call from outside of this "library."

LinkedList *create_list(void);

LinkedList *destroy_list(LinkedList *list);

LinkedList *recursive_destroy_list(LinkedList *list);

void head_insert(LinkedList *list, int data);

void tail_insert(LinkedList *list, int data);

int head_delete(LinkedList *list);

int tail_delete(LinkedList *list);

int kth_delete(LinkedList *list, int k);

int kth_element(LinkedList *list, int k);

node *kth_node(LinkedList *list, int k);

int peek(LinkedList *list, int option);

LinkedList *build_random_list(int n);

// WORK IN PROGRESS
// LinkedList *build_random_sorted_list(int n);

void print_list(LinkedList *list);

void sort_linked_list(LinkedList *list);

#endif
