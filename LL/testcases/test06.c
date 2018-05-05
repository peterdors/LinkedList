// Peter Dorsaneo
// test06.c
// tests the functionality of sort_linked_list function
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
	

	sort_linked_list(list);

	printf("\n\n");

	print_list(list);

	// use our recursive destroyer this time :)
	recursive_destroy_list(list);
	return 0;
}
