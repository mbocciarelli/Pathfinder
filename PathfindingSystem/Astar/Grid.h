#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Node.h"
#include "string"
#include "PortalNode.h"

class Grid
{

	//Variables
private:
	std::vector<Node*> m_gridData;
	Node* m_startingNode;
	Node* m_goalNode;
	std::vector<int> obstacles;

	int m_cellWidth = 0;
	int m_cellHeight = 0;
	int m_width = 0;
	int m_height = 0;

	static const int S_WALL_TYPE = 3;
	static const int S_GROUND_TYPE = 2;
	static const int S_START_TYPE = 0;
	static const int S_GOAL_TYPE = 1;

public:
	void SetValueAt(int type, int line, int col) 
	{
		const unsigned int index = col * m_height + line;
		if (index < m_gridData.size())
		{
			m_gridData[index]->line = line;
			m_gridData[index]->column = col;
			m_gridData[index]->type = type;
		}
	};

	Node* GetNodeAt(int line, int col)
	{
		const unsigned int index = col * m_height + line;
		//std::cout << "Col : " << col << " MHeight : " << m_height << " Line : " << line << std::endl;
		if (index < m_gridData.size())
		{
			return m_gridData[index];
		}

		return nullptr;
	};

	void SetStart(int line, int col) {
		m_startingNode = GetNodeAt(line, col);
		
	}

	void SetEnd(int line, int col) {
		m_goalNode = GetNodeAt(line, col);
	}

	bool StartAndEndSetup() {
		return m_startingNode != nullptr && m_goalNode != nullptr;
	}

	void AddObstacle(int type) {
		obstacles.push_back(type);
	}

	bool IsAnObstacle(int type) {
		for (int i = 0; i < obstacles.size(); i++) {
			if (obstacles[i] == type)
				return true;
		}

		return false;
	}

public:

	Grid(int width, int height, int sizeTilex, int sizeTiley)
	{
		m_cellWidth = sizeTilex;
		m_cellHeight = sizeTiley;
		m_width = width;
		m_height = height;


		m_gridData.resize(width * height);
		for (int i = 0; i < m_gridData.size(); i++)
			m_gridData[i] = new Node();
	};
	~Grid() = default;
	Node* GetStartNode() { 
		return m_startingNode; 
	};
	Node* GetGoalNode() { return m_goalNode; };


	void SetNodeInGrid(int type, int tileposX, int tileposY)
	{
		Node* node = GetNodeAt(tileposX, tileposY);
		node->type = type;
		if (type == S_START_TYPE)
			SetStart(tileposX, tileposY);
		if (type == S_GOAL_TYPE)
			SetEnd(tileposX, tileposY);

		node->column = tileposY;
		node->line = tileposX;
	}

	void SetPortalInGrid(int type, int tilepos_portal1_X, int tilepos_portal1_Y, int tilepos_portal2_X, int tilepos_portal2_Y)
	{
		PortalNode* portal1 = new PortalNode();
		PortalNode* portal2 = new PortalNode();

		m_gridData[tilepos_portal1_Y * m_height + tilepos_portal1_X] = portal1;
		m_gridData[tilepos_portal2_Y * m_height + tilepos_portal2_X] = portal2;
		portal1->SetDestination(portal2);
		portal2->SetDestination(portal1);

		portal1->line = tilepos_portal1_X;
		portal1->column = tilepos_portal1_Y;
		portal2->line = tilepos_portal2_X;
		portal2->column = tilepos_portal2_Y;
	}

	void InitGrid()
	{
		for (int line = 0; line < m_height; line++)
			for(int col = 0; col < m_width; col++)
			{
				Node* node = GetNodeAt(line, col);
				if (node->line > 0)
					AddNeighbour(node, GetNodeAt(node->line - 1, node->column));
				if (node->line < m_height - 1)
					AddNeighbour(node, GetNodeAt(node->line + 1, node->column));
				if (node->column > 0)
					AddNeighbour(node, GetNodeAt(node->line, node->column - 1));
				if (node->column < m_width - 1)
					AddNeighbour(node, GetNodeAt(node->line, node->column + 1));
			}
	}

	void AddNeighbour(Node* node, Node* neighbour) {
		if (!IsAnObstacle(neighbour->type))
		{
			node->AddNeighbour(neighbour);
		}
	}

	void Draw(sf::RenderWindow& _window, int margeX, int margeY, std::vector<Node*> GoodWay)
	{
		//create rect template for the grid
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(m_cellWidth/2, m_cellHeight /2));
		//rect.setSize(sf::Vector2f(25, 25));
		

		for (auto G : GoodWay)
		{
			rect.setFillColor(sf::Color::Green);
			rect.setPosition(sf::Vector2f(G->line * m_cellWidth + margeX, G->column * m_cellHeight + margeY));
			_window.draw(rect);
			
		}
	}


	int GetWidth() { return m_width; };
	int GetHeight() { return m_height; };
};