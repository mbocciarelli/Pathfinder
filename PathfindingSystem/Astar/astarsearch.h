#pragma once

#include "Grid.h"
#include "Node.h"

class AstarExe
{

private:
	Grid* m_grid;
	std::vector<Node*> m_open;
	std::vector<Node*> m_closed;
	Node* m_startNode;
	Node* m_goalNode;

	//Runtime variables
	bool m_started = false;
	bool m_found = false;
	int m_debugCount = 0;
	Node* m_processingNode;

	int ComputeHeuristic(Node* _node)
	{
		int toGoal = abs(m_goalNode->column - _node->column) + abs(m_goalNode->line - _node->line);
		//int toGoal = pow( (m_goalNode->j - _node->j), 2) + pow( (m_goalNode->i - _node->i),2);
		//toGoal = sqrt(toGoal);
		_node->heuristic = _node->cost + toGoal;
		return _node->heuristic;
	};
	void CheckNeighbours(Node* _node)
	{
		CheckNode(_node->column, _node->line - 1, _node->cost + 1, _node);
		//down
		CheckNode(_node->column, _node->line + 1, _node->cost + 1, _node);
		//left
		CheckNode(_node->column - 1, _node->line, _node->cost + 1, _node);
		//right
		CheckNode(_node->column + 1, _node->line, _node->cost + 1, _node);
	};
	void CheckNode(int i, int j, int _cost, Node* _parent)
	{
		//out of bounds
		if (i < 0 || i > m_grid->GetWidth() - 1 || j < 0 || j > m_grid->GetHeight() - 1)
			return;
		//Get Node at the position in the grid
		Node* node = &(*m_grid->GetNodeAt(i, j));
		//don't process walls
		if (m_grid->IsAnObstacle(node->type))
			return;
		//Set cost if not done yet
		if (node->cost == 0)
			node->cost = _cost;

		//Find in OPEN & CLOSE
		bool inOpen = BetterExistsInList(m_open, node);
		bool inClosed = BetterExistsInList(m_closed, node);
		//if not in any list or no better exists
		if (!inOpen && !inClosed) {
			node->parent = _parent;
			ComputeHeuristic(node);
			printf("[OPEN] Node (%d,%d) added (h:%d)\n", i, j, node->heuristic);
			m_open.push_back(node);
		}
	};
	void BuildBestPath()
	{
		if (m_processingNode->Equals(m_startNode)) {
			return;
		}
		m_processingNode->finalWayID = m_processingNode->cost;
		m_processingNode = m_processingNode->parent;
	};

	Node* PopBest() 
	{
		int bestIndex = 0;
		int bestHeuristic = 50000;
		int bestCost = 50000;
		Node* tempNode;
		//find best heuristic index
		for (int i = 0; i < m_open.size(); i++) {
			tempNode = m_open.at(i));
			/*if ((tempNode->heuristic < bestHeuristic)
				 || (tempNode->heuristic == bestHeuristic && tempNode->cost < bestCost) ) {
				bestIndex = i;
				bestHeuristic = tempNode->heuristic;
				bestCost = tempNode->cost;
			}*/
			if (tempNode->heuristic < bestHeuristic) {
				bestIndex = i;
				bestHeuristic = tempNode->heuristic;
				bestCost = tempNode->cost;
			}
		}
		//get best node
		Node* node = &(*m_open.at(bestIndex));
		//erase it from list
		m_open.erase(m_open.begin() + bestIndex);
		return node;
	};

	int FindIndexInList(std::vector<Node*> _list, Node* _toFind)
	{
		for (int i = 0; i < _list.size(); i++) {
			if (_toFind->Equals(_list.at(i))) {
				return i;
			}
		}
		return -1;
	};
	bool BetterExistsInList(std::vector<Node*> _list, Node* _toFind)
	{
		for (int i = 0; i < _list.size(); i++) {
			if (_toFind->Equals(_list.at(i))) {
				if (_list.at(i)->cost <= _toFind->cost)
					return true;
			}
		}
		return false;
	};

public:
	AstarExe(Grid* _grid)
	{
		m_grid = _grid;
	};
	~AstarExe() = default;

	void Start()
	{
		m_started = true;
		m_startNode = m_grid->GetStartNode();
		m_goalNode = m_grid->GetGoalNode();

		//First node to check
		m_open.push_back(m_startNode);

		m_debugCount = 0;
	};
	void Update()
	{
		if (m_found) {
			BuildBestPath();
			return;
		}
		if (!m_started || m_open.size() <= 0)
			return;
		//Get best node from the OPEN list
		m_processingNode = PopBest();
		m_processingNode->visited = true;
		//keep position
		int i = m_processingNode->column, j = m_processingNode->line;

		printf("------ %d ProCESSing Node (%d,%d) -------\n", m_debugCount, i, j);

		//check if this is the goal
		if (m_processingNode->Equals(m_goalNode)) {
			printf("Found Goal\n");
			m_found = true;
			return;
		}
		else {
			CheckNeighbours(m_processingNode);
		}

		//Add current node to closed list
		m_closed.push_back(m_processingNode);

		m_debugCount++;
	};
};
