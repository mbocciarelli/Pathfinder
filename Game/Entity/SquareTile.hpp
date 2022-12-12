#pragma once

#include "Tile.hpp"
#include "../SpriteRenderer.hpp"

class SquareTile : public Tile
{
public :
	void update(int xOrigin, int yOrigin, int xMarge, int yMarge) override
	{
		auto texture = mSprite->GetSprite()->getTextureRect();

		int x = xOrigin + mPosition.x * texture.width;
		int y = yOrigin + mPosition.y * texture.height;

		if (mPosition.x >= 0)
			y += xMarge * mPosition.y;
		if (mPosition.y >= 0)
			x += yMarge * mPosition.x;

		mSprite->SetPosition(x, y);
	}
};
