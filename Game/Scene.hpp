#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Astar/astarsearch.h"
#include "Entity/Tile.hpp"

class Scene
{
public :
	bool init();
	void start();
	void update();
	void render();

private :
	AstarExe* astar;
	sf::RenderWindow window;
	std::vector<Tile*> mTiles;

	struct Marging {
		int x;
		int y;
	};

	Marging margeMap { 30, 30 };
	Marging margeTile { 10, 10 };
	int SizeTileBar = 150;
};