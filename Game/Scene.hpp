#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity/Tile.hpp"

class Scene
{
public :
	bool init();
	void start();
	void update();
	void render();

private :
	sf::RenderWindow window;
	std::vector<Tile*> mTiles;

	struct Marging {
		int x;
		int y;
	};

    Tile* getTile(sf::Vector2i mousePosition){
        std::cout << "Mouse position : " << mousePosition.x << " ; " << mousePosition.y << std::endl;
        for (Tile* tile : mTiles)
        {
            if (tile->IsMouseOnTile(mousePosition))
                return tile;
        }
        return nullptr;
    }

    void leftClickAction(sf::Vector2i mousePosition);

	Marging margeMap { 30, 30 };
	Marging margeTile { 10, 10 };
	int SizeTileBar = 150;
};