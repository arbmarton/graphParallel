#include "stdafx.h"
#include "Graph.h"

#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

void printVector(const std::vector<std::string>& vec)
{
	for (int i = 0; i < vec.size(); ++i) 
	{
		std::cout << "Dependency level: " << i + 1 << ", elements: " << vec[i] << '\n';
	}
}

Graph::Graph(const char* const fileName)
{
	// this marks if we are reading the node declarations or the edges
	bool declarations = true;	

	std::ifstream in(fileName);
	std::string   line;
	while (std::getline(in, line))
	{
		if (line == "***")
		{
			declarations = false;
			continue;
		}

		if (declarations)
		{
			if (findNode(line))
			{
				std::cout << "input parsing error: duplicate node name encountered!\n";
				continue;
			}
			allNodes.push_front(new Node(line));
		}
		else
		{
			if (allNodes.empty())
			{
				std::cout << "input parsing error: no nodes added!\n";
				break;
			}

			std::istringstream stream(line);
			std::string parentName;
			std::string childName;

			if (!(stream >> parentName >> childName))
			{
				std::cout << "input parsing error: invalid edge declaration!\n";
				continue;
			}

			auto parentNode = findNode(parentName);
			auto childNode  = findNode(childName);

			if (!parentNode || !childNode)
			{
				std::cout << "input parsing error: nodes do not exist!\n";
				continue;
			}

			connectNodes(parentNode, childNode);
		}
	}

	createEntryList();
	assignLevels();
}

void Graph::print()
{
	// sort the nodes by their "level" value
	allNodes.sort([](Node* left, Node* right)
		{
			return left->getLevel() < right->getLevel();
		}
	);

	// the number of dependency layers is given by the "level" value of the last element in the sorted list
	std::vector<std::string> outputStrings;
	const int maxDependencyLevel = allNodes.back()->getLevel();
	outputStrings.resize(maxDependencyLevel);

	auto   iter  = allNodes.begin();
	while (iter != allNodes.end())
	{
		outputStrings[(*iter)->getLevel() - 1] += (*iter)->getName() + ", ";
		++iter;
	}

	printVector(outputStrings);
}

Graph::~Graph()
{
	for (Node*& node : allNodes)
	{
		delete node;
	}
}

// fills the entryPoints list
void Graph::createEntryList()
{
	for (Node*& node : allNodes)
	{
		if (node->getParents().size() == 0)
		{
			entryPoints.push_front(node);
		}
	}

	std::cout << entryPoints.size() << " entrypoints added.\n";
}

void Graph::assignLevels()
{
	for (Node*& node : entryPoints)
	{
		node->assignLevelValue(1);
	}
}

Node* Graph::findNode(const std::string& nodeName) const
{
	for (Node* node : allNodes)
	{
		if (node->getName() == nodeName)
		{
			return node;
		}
	}

	// if the node is not in the list return nullptr
	return nullptr;
}
