#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Image.hpp>
#include <iostream>
#include "Node.h"
#include "string"

class Grid
{

	//Variables
private:
	std::vector<Node> m_gridData;
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
			m_gridData[index].line = line;
			m_gridData[index].column = col;
			m_gridData[index].type = type;
		}
	};

	Node* GetNodeAt(int line, int col)
	{
		const unsigned int index = col * m_height + line;
		//std::cout << "Col : " << col << " MHeight : " << m_height << " Line : " << line << std::endl;
		if (index < m_gridData.size())
		{
			return &m_gridData[index];
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
			const Node& node = m_gridData[G->line * m_height + G->column];
			rect.setFillColor(sf::Color::Green);
			rect.setPosition(sf::Vector2f(G->line * (m_cellWidth - 10) + margeX + G->line * 10 + ((m_cellWidth - 10) / 4), G->column * (m_cellHeight - 10) + margeY + G->column * 10 + ((m_cellHeight - 10) / 4)));
			_window.draw(rect);
			
		}

		//
		/*for (int j = 0; j < m_width; j++) {
			for (int i = 0; i < m_height ; i++) {
				//get the type of the cell
				const Node& node = m_gridData[j * m_height + i];
				rect.setPosition(sf::Vector2f(i * (m_cellWidth - 10) + margeX + i * 10 + ((m_cellWidth - 10) / 4), j * (m_cellHeight - 10) + margeY + j * 10 + ((m_cellHeight - 10) / 4)));

				//Colorize it
				switch (node.type) {
				case S_GROUND_TYPE: rect.setFillColor(sf::Color::White); break;
				case S_WALL_TYPE: rect.setFillColor(sf::Color::Black); break;
				//case S_GOAL_TYPE: rect.setFillColor(sf::Color::Red); break;
				//case S_START_TYPE: rect.setFillColor(sf::Color::Blue); break;
				}
				if (node.visited == true && node.type != Grid::S_START_TYPE) {
					rect.setFillColor(sf::Color::Magenta);
					_window.draw(rect);
				}
				if (node.finalWayID >= 0) {
					rect.setFillColor(sf::Color::Green);
					_window.draw(rect);
				}
				//set position 
				//rect.setPosition(sf::Vector2f(i * 64, j * 64));
				//then finally draw
			}
		}
		*/
	}


	int GetWidth() { return m_width; };
	int GetHeight() { return m_height; };
};