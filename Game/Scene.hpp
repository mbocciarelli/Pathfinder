#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Astar/astarsearch.h"
#include "Entity/Tile.hpp"
#include "Input/InputManager.h"
#include "UI/Button.h"  


class Scene
{
public :
	bool init();
	void start();
	void update();
	void render();

private :
    InputManager* inputManager;
    Grid* grid;
	AstarExe* astar;
	sf::RenderWindow window;
	std::vector<Tile*> mTiles;
    //std::vector<Button*> mButtons;
    sf::Event currentEvent;
    
    sf::Text* textaddstart;
    sf::Text* textaddwall;
    sf::Text* textaddportal;
    sf::Text* textaddgoal;
    sf::Text* textStartPathfinder;

    sf::Font* font;
    Tile* portal1 = nullptr;
    Tile* portal2 = nullptr;

	struct Marging {
		int x;
		int y;
	};

public:
    Tile* getTile(sf::Vector2i mousePosition){
        for (Tile* tile : mTiles)
        {
            if (tile->IsMouseOnTile(mousePosition))
                return tile;
        }
        return nullptr;
    }



    void leftClickAction(sf::Vector2i mousePosition);

	Marging margeMap { 30, 30 };
	Marging margeTile { 2, 2 };
	int SizeTileBar = 150;
};