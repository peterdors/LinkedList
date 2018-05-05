## LinkedList
LinkedList is a library for creating dynamically allocated, linked lists of integers in C. It supports both insertion and deletion at the head and tail. While keeping an updated count of the number of elements in the list at one time. 

## Basic Example
For examples please refer to the `testcases` folder for test cases on each function. 

## How to use
Thourough documentation to every function can be found in the section `Exports`. For full examples see `testcases` folder.

### Creation
Simply use the built-in function to create a `list`

```C
LinkedList *list = create_list(void);
```

### Adding items to the list
Utilize the head_insert(...), tail_insert(...), or nth_insert(...) functions to add items into the list
```C
LinkedList *list = create_list(void);
    
head_insert(list, 0);

tail_insert(list, 2);

// inserts the value 1 into the second index of the list
// returns 1, if the list is not in bound of the indexed parameter
kth_insert(list, 1, 2);

print_list(list);

destroy_list(list);
```

`LinkedList: 0 1 2`

Note that it is important to call `destroy_list()` when done using a LinkedList.


### Reading values

```C
```


### Looping

You can easily loop through lists using the predefined `()` function.

```C

```


## Exports

* `create_node` - creates a single node
* `create_list` - creates a new LinkedList

* `destroy_list` - frees all dynamically allocated memory in the list

* `head_insert` - Inserts a node at the head of the linked list
* `tail_insert` - Inserts a node at the tail of the linked list

* `head_delete` - Deletes a node at the head of the linked list and returns the data from that node
* `tail_delete` - Deletes a node at the head of the linked list and returns the data from that node

* `kth_element` - Returns the data of the kth_element in the linked list
* `kth_node` - Returns the kth node of linked list

* `build_random_list` - Creates new list and inserts N number of random int nodes into the list
* `build_random_sorted_list` - Creates new list and inserts N number of random int nodes into the list in sorted ordering

* `print_list` - Prints out the current linked list.


## Build

LinkedList uses `gcc` to build. Simply do the following for running a test case:

`gcc tests/test01.c src/LinkedList.c`

`./a.out`


## Credits

* Dr. Szumlanski at UCF for inspiring me to continue with CS!
# LinkedList
