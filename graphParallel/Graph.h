#pragma once

#include "Node.h"

#include <list>

class Node;

class Graph
{
public:
	// the Graph is constructed from a .txt file, which has 2 parts:
	// 1. node declarations (eg. "example")
	// 2. connection declaration(eg. "example1 example2")
	// separating the two there is a line which contains three asterisks: "***"
	explicit Graph(const char* const fileName);

	void print();

	~Graph();

private:
	std::list<Node*> entryPoints;	// nodes which have no parent
	std::list<Node*> allNodes;

	// fills the entryPoints list
	void createEntryList();

	// assings each node in the graph its "level" value
	void assignLevels();

	Node* findNode(const std::string& nodeName) const;
};



