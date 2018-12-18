# OpenMP-and-Pthread

# Question 1 (A serial C program):
Suppose the run-time of a serial program is given by Tserial= n2, where the units of the run-time are in microseconds. Suppose that a parallelization of this program has run-time Tparallel= (n2/p) + log2(p). Write a program that ﬁnds the speedups and efﬁciencies of this program for various values of n and p. Run your program with n= 10, 20, 40, . . . ,320, and p= 1,2,4, . . .,128.<br><br>

# Question 2: (MPI)

# Question 3 :(PThread)
Write a parallel program using pthread to accomplish the same as the following serial program. For the following serial program, the user enters a line and the program outputs the number of occurrences of each character.
For the parallel program if we have n threads we should divide the line into n segments and let each thread counts the characters of its segment.
Note: Do not count the space or the tab characters.<br><br>

#Question 4 (OpenMP): 

Write a program using OpenMP to hire 8 threads to accomplish the following: <br>
a) Declare a shared array: a of type integer of size 800.<br>
b) Declare a shared array: b of type integer of size 8.<br>
c) Generates 800 random numbers in the range 0 to 50,000 inclusive and stores them in array: a.<br>
d) The 8 threads with the ranks 0, 1, 2, 3, 4, 5, 6, 7 find the biggest number of array: a, from indices 0 to 99, 100 to 199, 200, 299, 300 to 399, 400 to 499, 500 to 599, 600 to 699,  700 to 799 and store them in b[0], b[1], b[2], b[3], b[4], b[5], b[6], and b[7] respectively.<br>
d) The function: main displays the biggest number of array: b.<br>

