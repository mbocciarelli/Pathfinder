#pragma once

#include <SFML/Graphics.hpp>

class SpriteRenderer
{
public :
	void render(sf::Sprite* sprite, sf::RenderWindow* window)
	{
		window->draw(*sprite);
	}
};