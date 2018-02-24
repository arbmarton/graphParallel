#include "stdafx.h"
#include "Node.h"

Node::Node(const std::string& newName)
	: name(newName)
	, level(-1) // signifies that this node was not yet touched
{

}

std::list<Node*> Node::getParents()  const
{
	return parents;
}

std::list<Node*> Node::getChildren() const
{
	return children;
}

int Node::getLevel() const
{
	return level;
}

std::string Node::getName() const
{
	return name;
}

void Node::addParent(Node* newParent)
{
	parents.push_back(newParent);
}

void Node::addChildren(Node* newChild)
{
	children.push_back(newChild);
}

void Node::assignLevelValue(const int newLevel)
{
	if (newLevel > level)
	{
		level = newLevel;
	}

	for (Node*& node : children)
	{
		node->assignLevelValue(newLevel + 1);
	}
}

Node::~Node()
{

}


void connectNodes(Node* parent, Node* child)
{
	parent->addChildren(child);
	child->addParent(parent);
}