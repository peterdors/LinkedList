// Peter Dorsaneo
// test02.c
// tests our kth_element function

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../src/LinkedList.h"


int main(void)
{
	int i, retval;
	LinkedList *list = create_list();

	// simple insertion via tail
	for (int i = 1; i <= 100; ++i)
	{
		tail_insert(list, i);
	}

	// now lets get the k'th elements and print it out
	// keeping in mind that k ranges from 1 to N
	for (int i = 1; i <= 100; ++i)
	{	
		retval = kth_element(list, i);
		// our second char conversion specifies for 
		// whether to print a space 
		// or new line if we are at the end 
		// of our loop.
		printf("%d%c", retval, i < 100 ? ' ' : '\n');
	}

	
	destroy_list(list);
	return 0;
}
