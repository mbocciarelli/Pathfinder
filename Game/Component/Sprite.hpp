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

	void create(std::string path)
	{
		mPathTexture = path;
		LoadSprite();
	}

	void SetPosition(int x, int y) {
		mSprite->setPosition(x, y);
	}

	sf::Sprite* GetSprite() {
		return mSprite;
	}

private:
	void LoadSprite()
	{
		if (!mTexture.loadFromFile(mPathTexture))
		{
			throw std::runtime_error("Fail to load texture");
			return;
		}

		mSprite = new sf::Sprite(mTexture);
	}

private:
	std::string mPathTexture;
	sf::Sprite* mSprite;
	sf::Texture mTexture;

};