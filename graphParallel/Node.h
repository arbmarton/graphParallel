#pragma once

#include "Graph.h"

#include <list>

class Graph;

class Node
{
public:
	explicit Node(const std::string& newName);

	std::list<Node*> getParents()  const;
	std::list<Node*> getChildren() const;
	int				 getLevel()	   const;
	std::string		 getName()	   const;

	void addParent(Node* newParent);
	void addChildren(Node* newChild);

	void assignLevelValue(const int newLevel);

	~Node();

private:
	std::list<Node*> parents;	// nodes this depends from
	std::list<Node*> children;	// nodes depending from this

	std::string name;	// unique id
	int level;			// dependency layer count
};

void connectNodes(Node* parent, Node* child);

