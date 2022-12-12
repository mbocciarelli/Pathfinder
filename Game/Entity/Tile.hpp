#pragma once

#include "Component/Sprite.hpp"
#include <vector>

struct TilePosition
{
	int x;
	int y;
};


class Tile
{
public:
	Tile() :
		mPosition(TilePosition {0, 0})
	{
		mSprite = new Sprite();
	}

	void create(std::string pathTexture)
	{
		mSprite->create(pathTexture);
	}

	void SetTilePosition(TilePosition pos)
	{
		mPosition.x = pos.x;
		mPosition.y = pos.y;
	}

	sf::Sprite* GetSprite() {
		return mSprite->GetSprite();
	}

	virtual void update(int xOrigin, int yOrigin, int xMarge, int yMarge)
	{
		
	}

protected :
	Sprite* mSprite;
	TilePosition mPosition;
};
