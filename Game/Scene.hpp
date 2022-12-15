#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Astar/astarsearch.h"
#include "Entity/Tile.hpp"

struct Button
{
    sf::RectangleShape* shape;
    std::string text;
    sf::Color color;
    TileType type;
    sf::Sprite* sprite;
    sf::Text textSprite;

    Button(sf::RectangleShape* shape, std::string text, sf::Color color, TileType type) :
        shape(shape),
        text(text),
        color(color),
        type(type)
    {
        // set sprite from shape and color
        sf::Texture texture;
        texture.create(shape->getSize().x, shape->getSize().y);
        sprite = new sf::Sprite(texture);
        sprite->setColor(color);
        sprite->setPosition(shape->getPosition());
        // set text sprite
        sf::Texture textTexture;
        textSprite.setString(text);
        textSprite.setFont(sf::Font());
        textSprite.setCharacterSize(20);
        sf::Color textColor;
        sf::Color outlineColor;
        if (color.r > 127 && color.g > 127 && color.b > 127)
        {
            textColor = sf::Color::Black;
            outlineColor = sf::Color::White;
        }
        else
        {
            textColor = sf::Color::White;
            outlineColor = sf::Color::Black;
        }
        textSprite.setFillColor(textColor);
        textSprite.setOutlineColor(outlineColor);
        textSprite.setOutlineThickness(1);
        // set text width from button sprite
        textSprite.setPosition(shape->getPosition().x + shape->getSize().x / 2 - textSprite.getLocalBounds().width / 2, shape->getPosition().y + shape->getSize().y / 2 - textSprite.getLocalBounds().height / 2);
        textTexture.create(textSprite.getLocalBounds().width, textSprite.getLocalBounds().height);
    }
};

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
    std::vector<Button*> mButtons;

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