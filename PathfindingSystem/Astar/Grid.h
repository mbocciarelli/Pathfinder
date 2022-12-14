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

	static const int S_WALL_TYPE = 0;
	static const int S_GROUND_TYPE = 1;
	static const int S_START_TYPE = 2;
	static const int S_GOAL_TYPE = 3;

public:
	void SetValueAt(int width, int height, int type) 
	{
		const unsigned int index = width * width + height;
		if (index < m_gridData.size())
		{
			m_gridData[index].line = width;
			m_gridData[index].column = height;
			m_gridData[index].type = type;
		}
	};

	Node* GetNodeAt(int col, int line)
	{
		const unsigned int index = col * m_width + line;
		if (index < m_gridData.size())
		{
			return &m_gridData[index];
		}

		return nullptr;
	};

	void SetStart(int width, int height) {
		m_startingNode = GetNodeAt(width, height);
	}

	void SetEnd(int width, int height) {
		m_goalNode = GetNodeAt(width, height);
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
		m_gridData.resize(width * height);
	};
	~Grid() = default;
	Node* GetStartNode() { return m_startingNode; };
	Node* GetGoalNode() { return m_goalNode; };
	void SetStartNode() {}


	void SetNodeInGrid(int type,int tileposX, int tileposY)
	{
		m_width = tileposX;
		m_height = tileposY;
		Node* node = GetNodeAt(tileposY, tileposX);
		node->type = type;
		node->column = tileposY;
		node->line = tileposX;
	}

	void Draw(sf::RenderWindow& _window) const
	{
		//create rect template for the grid
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(m_cellWidth, m_cellWidth));

		//
		for (int j = 0; j < m_height; j++) {
			for (int i = 0; i < m_width; i++) {
				//get the type of the cell
				const Node& node = m_gridData[j * m_width + i];
				//Colorize it
				switch (node.type) {
				/*case S_GROUND_TYPE: rect.setFillColor(sf::Color::White); break;
				case S_WALL_TYPE: rect.setFillColor(sf::Color::Black); break;
				case S_GOAL_TYPE: rect.setFillColor(sf::Color::Red); break;
				case S_START_TYPE: rect.setFillColor(sf::Color::Blue); break;
				*/
				}
				if (node.visited == true && node.type != Grid::S_START_TYPE) {
					rect.setFillColor(sf::Color::Yellow);
				}
				if (node.finalWayID >= 0) {
					rect.setFillColor(sf::Color::Green);
				}
				//set position 
				rect.setPosition(sf::Vector2f(i * 64, j * 64));
				//then finally draw
				_window.draw(rect);
				//TEXT
				/*text.setString(std::to_string(node->i)+","+std::to_string(node->j));
				text.setPosition(sf::Vector2f(i * 64, j * 64));
				text.setColor(sf::Color::Red);
				text.setCharacterSize(15);
				_window.draw(text);
				//cost
				text.setColor(sf::Color::Black);
				text.setPosition(sf::Vector2f(i * 64, j * 64 +20));
				text.setString("c"+std::to_string(node->cost) + ", h" + std::to_string(node->heuristic));
				_window->draw(text);*/
			}
		}
	}


	int GetWidth() { return m_width; };
	int GetHeight() { return m_height; };
};