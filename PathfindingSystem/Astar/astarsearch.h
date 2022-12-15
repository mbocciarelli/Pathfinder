#pragma once

#include "Grid.h"
#include "Node.h"
#include <queue>
#include <unordered_map>

template<typename T, typename priority_t>
struct PriorityQueue {
	typedef std::pair<priority_t, T> PQElement;
	std::priority_queue<PQElement, std::vector<PQElement>,
		std::greater<PQElement>> elements;

	inline bool empty() const {
		return elements.empty();
	}

	inline void put(T item, priority_t priority) {
		elements.emplace(priority, item);
	}

	T get() {
		T best_item = elements.top().second;
		elements.pop();
		return best_item;
	}
};


class AstarExe
{

private:
	Grid* m_grid;
	std::vector<Node*> m_open;
	std::vector<Node*> m_closed;
	Node* m_startNode;
	Node* m_goalNode;

	std::unordered_map<Node*, Node*> came_from;
	std::unordered_map<Node*, double> cost_so_far;

	//Runtime variables
	bool m_started = false;
	bool m_found = false;
	Node* m_processingNode;

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

	};

	bool IsStart() {
		return m_started;
	}

private :

	inline int heuristic(Node* a, Node* b) {
		return std::abs(a->line - b->line) + std::abs(a->column - b->column);
	}


public :
	std::vector<Node*> reconstruct_path() {
		std::vector<Node*> path;
		Node* current = m_goalNode;
		if (came_from.find(m_goalNode) == came_from.end()) {
			return path; // no path can be found
		}
		while (current != m_startNode) {
			path.push_back(current);
			current = came_from[current];
		}
		path.push_back(m_startNode); // optional
		std::reverse(path.begin(), path.end());
		return path;
	}


	void Update() {
		PriorityQueue<Node*, int> frontier;
		frontier.put(m_startNode, 0);

		came_from[m_startNode] = m_startNode;
		cost_so_far[m_startNode] = 0;

		while (!frontier.empty())
		{
			Node* node = frontier.get();

			if (node == m_goalNode)
				break;

			for (auto neighbour : node->GetNeighbours())
			{
				int new_cost = cost_so_far[node] + neighbour->cost;
				if (cost_so_far.find(neighbour) == cost_so_far.end()
					|| new_cost < cost_so_far[neighbour])
				{
					neighbour->visited = true;
					cost_so_far[neighbour] = new_cost;
					int priority = new_cost + heuristic(neighbour, m_goalNode);
					frontier.put(neighbour, priority);
					came_from[neighbour] = node;
				}
			}
		}
	}
	void Draw(sf::RenderWindow& _window, int margeX, int margeY) {
		m_grid->Draw(_window, margeX, margeY, reconstruct_path());
	};
};
