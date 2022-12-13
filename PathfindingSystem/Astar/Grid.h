#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Image.hpp>

#include "Node.h"

class Grid
{

	//Variables
private:
	std::vector<Node> m_gridData;
	Node* m_startingNode = nullptr;
	Node* m_goalNode = nullptr;
	std::vector<int> obstacles;

public:
	void SetValueAt(int width, int height, int type)
	{
		const unsigned int index = width * m_width + height;
		if (index < m_gridData.size())
		{
			m_gridData[index].ligne = width;
			m_gridData[index].column = height;
			m_gridData[index].type = type;
		}
	};

	Node* GetNodeAt(int width, int height) const
	{
		const unsigned int index = width * m_width + height;
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
			if(obstacles[i] == type)
				return true
		}

		return false;
	}

	//functions
private:
	/*void FillStatic()
	{
		FillColumn(0, new int[10] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
		FillColumn(1, new int[10] { 0, 1, 1, 1, 1, 0, 1, 1, 1, 0 });
		FillColumn(2, new int[10] { 2, 1, 1, 1, 1, 0, 1, 1, 1, 0 });
		FillColumn(3, new int[10] { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 });
		FillColumn(4, new int[10] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 });
		FillColumn(5, new int[10] { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 });
		FillColumn(6, new int[10] { 0, 1, 1, 1, 1, 1, 0, 1, 1, 0 });
		FillColumn(7, new int[10] { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 });
		FillColumn(8, new int[10] { 0, 1, 1, 1, 1, 1, 0, 1, 1, 0 });
		FillColumn(9, new int[10] { 0, 0, 0, 0, 0, 0, 0, 3, 0, 0 });

		m_startingNode = GetNodeAt(2, 0);
		m_goalNode = GetNodeAt(9, 7);
	};
	void FillColumn(int index, int* arr)
	{
		Node* node;
		for (int i = 0; i < m_height; i++) {
			node = GetNodeAt(_col, i);
			node->type = *(_array + i);
			node->column = _col;
			node->line = i;
		}
	};*/

public:
	Grid()
	{
		//Create default data
		m_gridData.resize(m_width * m_height);
		//FillRandom();
		FillStatic();
		//Print();
	};
	~Grid() = default;
	Node* GetStartNode(){return m_startingNode};
	Node* GetGoalNode(){return m_goalNode};

	void Print() 
	{
		for (int j = 0; j < m_height; j++) {
			for (int i = 0; i < m_width; i++) {
				printf("%d ", GetNodeAt(i, j)->type);
			}
			printf("\n");
		}
	};
	void Draw(sf::RenderWindow& _window) const
	{
		//create rect template for the grid
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f(m_cellWidth, m_cellWidth));
		//create text template
		//
		for (int j = 0; j < m_height; j++) {
			for (int i = 0; i < m_width; i++) {
				//get the type of the cell
				const Node& node = m_gridData[j * m_width + i];
				//Colorize it
				switch (node.type) {
				case S_GROUND_TYPE: rect.setFillColor(sf::Color::White); break;
				case S_WALL_TYPE: rect.setFillColor(sf::Color::Black); break;
				case S_GOAL_TYPE: rect.setFillColor(sf::Color::Red); break;
				case S_START_TYPE: rect.setFillColor(sf::Color::Blue); break;
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
			}
		}
	};

	int GetWidth(){return m_width};
	int GetHeight(){return m_height};
};