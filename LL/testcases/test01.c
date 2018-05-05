// peter dorsaneo
// test01.c
// tests the functionality of the insertion functions

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../src/LinkedList.h"

int main(void)
{
	int i;
	LinkedList *list = create_list();

	// lets insert into the head
	for (i = 10; i > 0; i--)
	{
		head_insert(list, i);
	}

	// now lets insert at the tail
	// inserting in a sorted arrangement
	// so to know what our printList output
	// should look like.

	for (i = 100; i < 110; i++)
	{
		tail_insert(list, i);
	}

	print_list(list);

	destroy_list(list);

	return 0;
}
