# push_swap
push_swap sorting algorithm for 2 stacks

PUSH SWAP is a project where students are tasked with sorting arrays of numbers with given constraints in the most efficient method possible.

The program is given a random number of integers (can't be two of the same). It then sorts these integers using two stacks and a set of instructions allowed by the assignment.

These instructions are:

PA (Push A): Push top of stack B to top of stack A
PB (Push B): Push top of stack A to top of stack B
SA (Swap A): Swap the first two values on stack A
SB (Swap B): Swap the first two values on stack B
SS (Swap Both): Swap A and Swap B
RA (Rotate A): Take the first value on stack A and move it to the back of stack A, rotating the rest of the stack
RB (Rotate B): Take the first value on stack B and move it to the back of stack B, rotating the rest of the stack
RR (Rotate Both): Rotate both stacks
RRA (Reverse Rotate A): Take the last value on stack A and move it to the front of stack A
RRB (Reverse Rotate B): Take the last value on stack B and move it to the front of stack B
RRR (Reverse Rotate Both): Reverse rotate both stacks

The method used in this project combines quicksort with insertion sort. It partitions stack A until it is a small enough size to effectively use insertion sort.

INSTRUCTIONS:

1. Make
2. Run as follows: ./push_swap $(LIST OF INTEGERS)
3. Push swap will output a list of instructions that should be applied to the integers in order to sort them.


As well as this, part of the assignment is to write a 'Checker' program, which receives as an argument a list of integers.
Checker will then wait for instructions, reading from the standard input and sequentially execute these instructions one by one on the integers.
At the end Checker will output either 'OK' (the list is sorted on stack A and stack B is empty) or 'KO'.

Here is an example of how to run checker:

#!/bin/bash
LIST=(80 35 17 -442 1004 -23 95 -1423)
./push_swap $(LIST) | ./checker $(LIST)

The full information about this project can be found in the PDF.
