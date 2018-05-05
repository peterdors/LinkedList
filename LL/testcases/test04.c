// peter dorsaneo
// test04.c
// tests the functionality of kth_delete function
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// make sure to update this include if we change our directories around
#include "../src/LinkedList.h"

int main(void)
{

	LinkedList *list = build_random_list(10);

	// print our beginning list 
	print_list(list);

	// perform head and tail deletions
	printf("Deleting node %d...\n", head_delete(list));
	printf("Deleting node %d...\n", head_delete(list));
	printf("Deleting node %d...\n", tail_delete(list));
	printf("Deleting node %d...\n", tail_delete(list));

	// check our head and tail pointers with peek(...)
	printf("The new head is %d\n", peek(list->head));
	printf("The new tail is %d\n", peek(list->tail));

	// verify everything by printing our list after the deletions
	print_list(list);

	destroy_list(list);
	return 0;
}
