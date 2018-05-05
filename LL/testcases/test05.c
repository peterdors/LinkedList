// Peter Dorsaneo
// test05.c
// tests the functionality of head_delete function
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// make sure to update this include if we change our directories around
#include "../src/LinkedList.h"

int main(void)
{

	LinkedList *list = build_random_list(100);

	// print our beginning list 
	print_list(list);
	

	// just delete the whole list one by one
	while (list->head != NULL)
		head_delete(list);
	// print the list again
	// this time it's empty
	print_list(list);

	// use our recursive destroyer this time :)
	recursive_destroy_list(list);
	return 0;
}
