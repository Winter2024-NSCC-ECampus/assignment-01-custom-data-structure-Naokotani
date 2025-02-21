# Linked list 
A simple application to make random Moby Dick quotes and edit them. Demonstrates a variation on a Linked List, and using tail call optimization to recursively edit it.

# Build
To build run `make` in the root directory. Requires gcc compiler or another compiler with tail call optimization.

# Functions
## append(value) adds a new node containing value to the end of the list
`LinkedList.c` line 71
## prepend(value) adds a new node containing value to the start of the list
`LinkedList.c` line 88
## size returns the total number of nodes in the list
`LinkedList.c` line 9
## head returns the first node in the list
`LinkedList.c` line 14
## tail returns the last node in the list
`LinkedList.c` line 19
## at(index) returns the node at the given index
`LinkedList.c` line 168
## pop removes the last element from the list
`LinkedList.c` line 180
## contains?(value) returns true if the passed in value is in the list and otherwise returns false.
`LinkedList.c` line 225
## find(value) returns the index of the node containing value, or nil if not found.
`LinkedList.c` line 211
