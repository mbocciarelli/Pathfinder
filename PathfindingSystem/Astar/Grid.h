#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Image.hpp>

#include "Node.h"

class Grid
{

	//Variables
private:
	std::vector<Node> m_gridData;
	int m_width = 10;
	int m_height = 10;
	int m_cellWidth = 64;
	int m_cellHeight = 64;

	Node* m_startingNode;
	Node* m_goalNode;

	sf::Font font;

public:
	static const int S_WALL_TYPE = 0;
	static const int S_GROUND_TYPE = 1;
	static const int S_START_TYPE = 2;
	static const int S_GOAL_TYPE = 3;

	void SetValueAt(int value, int i, int j)
	{
		const unsigned int index = _line * m_width + _col;
		if (index < m_gridData.size())
		{
			m_gridData[index].type = _value;
		}
	};
	Node* GetNodeAt(int i, int j)
	{
		const unsigned int index = _line * m_width + _col;
		if (index < m_gridData.size())
		{
			return &m_gridData[index];
		}

		return nullptr;
	};

	//functions
private:
	void FillStatic()
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
	};

public:
	Grid()
	{
		if (!font.loadFromFile("G:/Projects/MVSProjects/astar/Astar/dodjzem.ttf"))
		{
			// erreur...
		}
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
		sf::Text text;
		text.setFont(font);

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
	};

	int GetWidth(){return m_width};
	int GetHeight(){return m_height};
};