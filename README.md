# graphParallel

This project is a simple program which reads in a .txt file containing a description of a graph symbolizing computable processes,
and tells you which of them can be run in parallel. 
A Graph object is constructed from a filename, which contains Nodes, representing the processes. By invoking the Graphs "print()"
functions the software tells us which Nodes can be run in parallel.

Assumptions about the input:
1. A .txt file in the same folder as the source files.
2. Preferably only english characters.
3. The file is divided into two sections by a line containing only three asterisks. (***)
4. The first section contains the name of the Nodes, all of them unique.
5. The second section contains the declarations of the edges of the graph, the names of the two connectd Nodes separated by a space. (Eg.: "node1 node2" means node2 is a child of node1)
6. Every line contains a single statement.

Example input:

     a
     b
     c
     d
     e
     f
     g
     h
     i
     j
     ***
     a g
     b c
     b d
     c e
     d e
     g h
     g i
     h j
     i j
     j f
     e f

Output:

The Graphs "print()" functions puts out a number of lines equal to the maximum layer depth, on each line showing which Nodes can be
run parallel.
