#pragma once

#include "Component/Sprite.hpp"
#include <vector>

enum TileType {
	Start = 0, 
	End, 
	Ground,
	Wall,
	Portal
};

struct Generator {
	static sf::Texture* Generate(std::string path) {
		sf::Texture* texture = new sf::Texture();
		bool result = texture->loadFromFile(path);
		if (!result)
		{
			throw std::runtime_error("Fail to load texture");
			return nullptr;
		}
		return texture;
	}
};

class Initialisator {
private :
	sf::Texture* textureStart;
	sf::Texture* textureEnd;
	sf::Texture* textureGround;
	sf::Texture* textureWall;
	sf::Texture* texturePortal;

public :
	Initialisator()
	{
		textureStart = Generator::Generate("../../../../Game/Sprite/StartSquare.png");
		textureEnd = Generator::Generate("../../../../Game/Sprite/EndSquare.png");
		textureGround = Generator::Generate("../../../../Game/Sprite/GroundSquare.png");
		textureWall = Generator::Generate("../../../../Game/Sprite/WallSquare.png");
		texturePortal = Generator::Generate("../../../../Game/Sprite/PortailSprite.png");
	}

	sf::Texture* instanciate(TileType type) {
		switch (type)
		{
		case Start:
			return textureStart;
		case End:
			return textureEnd;
		case Ground:
			return textureGround;
		case Wall:
			return textureWall;
		case Portal:
			return texturePortal;
		default:
			break;
		}
	}
};

class Instanciator {
private:
	static Instanciator* instance;
	Initialisator textureInit;

	Instanciator() :
		textureInit()
	{}

	static Instanciator* GetInstance() {
		if (!instance)
			instance = new Instanciator();
		return instance;
	}


public:

	static sf::Texture* GetTexture(TileType type) {
		return GetInstance()->textureInit.instanciate(type);
	}
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
		auto texture = Instanciator::GetTexture(type);
		mSprite->CreateSprite(texture);
	}

	TileType GetTileType() const
	{
		return mType;
	}

	TilePosition GetTilePosition() const
	{
		return mPosition;
	}

	sf::Sprite* GetSprite() {
		return mSprite->GetSprite();
	}

    bool IsMouseOnTile(sf::Vector2i mousePosition){
        sf::Vector2f position = mSprite->GetSprite()->getPosition();
        float width = mSprite->GetSprite()->getLocalBounds().width;
        float height = mSprite->GetSprite()->getLocalBounds().height;
        sf::Vector2f size = sf::Vector2f(width, height);
        /*std::cout << "Position : " << position.x << " ; " << position.y << std::endl;
        std::cout << "Size : " << size.x << " ; " << size.y << std::endl;*/
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
	TileType mType;
	Sprite* mSprite;
	TilePosition mPosition;
};
