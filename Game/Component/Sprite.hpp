#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <string>

#include "Component.hpp"

class Sprite : public Component
{
public:
	Sprite()
	{
	}

	void CreateSprite(sf::Texture* texture)
	{
		LoadSprite(texture);
	}

	void SetPosition(int x, int y) {
		mSprite->setPosition(x, y);
	}

	sf::Sprite* GetSprite() {
		return mSprite;
	}

private:
	void LoadSprite(sf::Texture* texture)
	{
		mSprite = new sf::Sprite(*texture);
	}

private:
	sf::Sprite* mSprite;

};