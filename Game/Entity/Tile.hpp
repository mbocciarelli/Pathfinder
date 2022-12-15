#pragma once

#include "Component/Sprite.hpp"
#include <vector>

struct TilePosition
{
	int x;
	int y;
};

enum class TileType
{
    Empty,
    Wall,
    Start,
    End,
    Path
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

    void SetSprite(std::string pathTexture){
        mSprite->create(pathTexture);
    }

    bool IsMouseOnTile(sf::Vector2i mousePosition){
        sf::Vector2f position = mSprite->GetSprite()->getPosition();
        float width = mSprite->GetSprite()->getLocalBounds().width;
        float height = mSprite->GetSprite()->getLocalBounds().height;
        sf::Vector2f size = sf::Vector2f(width, height);
        std::cout << "Position : " << position.x << " ; " << position.y << std::endl;
        std::cout << "Size : " << size.x << " ; " << size.y << std::endl;
        if (mousePosition.x >= position.x && mousePosition.x <= position.x + size.x)
        {
            if (mousePosition.y >= position.y && mousePosition.y <= position.y + size.y)
            {
                return true;
            }
        }
        return false;
    }

	virtual void update(int xOrigin, int yOrigin, int xMarge, int yMarge)
	{
		
	}

protected :
	Sprite* mSprite;
	TilePosition mPosition;
};
