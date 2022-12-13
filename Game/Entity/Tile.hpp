#pragma once

#include "Component/Sprite.hpp"
#include <vector>

enum TileType {
	Start = 0, 
	End, 
	Ground,
	Wall
};

struct InitialisatorBase {
public :
	virtual std::string instanciate() = 0;
	virtual ~InitialisatorBase() {}
};

template<TileType T>
struct Initialisator : public InitialisatorBase {
public:
	virtual std::string instanciate() override { return ""; };
};

template<> struct Initialisator<TileType::Start> {
public:
	virtual std::string instanciate() { return "D:/Cours Ynov/ProjetM2/Pathfinder/Game/Sprite/GreenSquareMedium.png"; };
};

template<> class Initialisator<TileType::End> {
public:
	virtual std::string instanciate() { return "D:/Cours Ynov/ProjetM2/Pathfinder/Game/Sprite/RedSquareMedium.png"; };
};

template<> class Initialisator<TileType::Ground> {
public:
	virtual std::string instanciate() { return "D:/Cours Ynov/ProjetM2/Pathfinder/Game/Sprite/BlueSquareMedium.png"; };
};

template<> class Initialisator<TileType::Wall> {
public:
	virtual std::string instanciate() { return "D:/Cours Ynov/ProjetM2/Pathfinder/Game/Sprite/BlueSquareMedium.png"; };
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

	void SetTilePosition(TilePosition pos)
	{
		mPosition.x = pos.x;
		mPosition.y = pos.y;
	}

	template<TileType type>
	void SetTileType() 
	{
		mType = type;
		auto path = Initialisator<type>().instanciate();
		mSprite->CreateSprite(path);
	}

	sf::Sprite* GetSprite() {
		return mSprite->GetSprite();
	}

	virtual void update(int xOrigin, int yOrigin, int xMarge, int yMarge)
	{
		
	}

protected :
	TileType mType;
	Sprite* mSprite;
	TilePosition mPosition;
};
