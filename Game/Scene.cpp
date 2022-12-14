#include "Scene.hpp"

#include "Entity/SquareTile.hpp"

#include "Astar/Grid.h"
#include "Astar/Node.h"


bool Scene::init()
{
    window.create(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Texture model;
    if (!model.loadFromFile("../../../../Game/Sprite/BlueSquareMedium.png"))
        return false;
   
    TilePosition currentPosition {0, 0};

    int sizeTileX = model.getSize().x + margeTile.x;
    int sizeTileY = model.getSize().y + margeTile.y;
    int mapSizeX = window.getSize().x - margeMap.x * 2;
    int mapSizeY = window.getSize().y - margeMap.y * 2 - SizeTileBar;

    int tileHeight = mapSizeX / sizeTileX;
    int tileWidth = mapSizeY / sizeTileY;

    //Grille Pathfinder
    Grid* grid = new Grid(tileWidth, tileHeight,sizeTileX,sizeTileY);
    astar =new AstarExe(grid);

    for (int i = 0; i < tileWidth; i++)
    {
        for (int j = 0; j < tileHeight; j++)
        {
            auto tile = new SquareTile();
            mTiles.push_back(tile);
            tile->SetTileType<TileType::Ground>();
            tile->SetTilePosition(currentPosition);
            if (currentPosition.x == 4 && currentPosition.y == 4) {
                tile->SetTileType<TileType::Start>();
            }

            if (currentPosition.x == 20 && currentPosition.y == 5) {
                tile->SetTileType<TileType::End>();
            }
            grid->SetNodeInGrid((int)tile->GetTileType(), currentPosition.x, currentPosition.y);

            currentPosition.x++;
        }
        currentPosition.x = 0;
        currentPosition.y++;
    }

    astar->Start();
   
    //  grid.SetGrid();

    
    return true;
}

void Scene::start() {
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        update();
        window.clear();
        render();
        window.display();
    }
}

void Scene::update()
{
    for (auto& tile : mTiles)
    {
        tile->update(margeMap.x, margeMap.y, margeTile.x, margeTile.y);
    }
    astar->Update();
    /*if (start && end)
        pathfinding.update();*/
}

void Scene::render()
{
    for (auto& tile : mTiles)
    {
        SpriteRenderer().render(tile->GetSprite(), &window);
    }
    /*if (start and end)
        pathfinding.render(&windows);*/
}