// graphParallel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

int main()
{	
	Graph graph("input.txt");
	graph.print();

	system("pause");
    return 0;
}

