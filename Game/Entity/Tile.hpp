#pragma once

#include "Component/Sprite.hpp"
#include <vector>

enum TileType {
	Start, Wall, End, Ground
};

struct TilePosition
{
	int x;
	int y;
};


class Tile
{
public:
	Tile() :
		mPosition(TilePosition{ 0, 0 }),
		mType(TileType::Ground)
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

	void SetTileType(TileType type) { mType = type; };

protected :
	TileType mType;
	Sprite* mSprite;
	TilePosition mPosition;
};
