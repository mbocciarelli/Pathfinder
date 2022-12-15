#include "Scene.hpp"

#include "Entity/SquareTile.hpp"

#include "Astar/Grid.h"
#include "Astar/Node.h"


bool Scene::init()
{
    window.create(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Texture model;
    if (!model.loadFromFile("../../../../Game/Sprite/BlueSquare.png"))
        return false;
   
    TilePosition currentPosition {0, 0};

    int sizeTileX = model.getSize().x + margeTile.x;
    int sizeTileY = model.getSize().y + margeTile.y;
    int mapSizeX = window.getSize().x - margeMap.x * 2;
    int mapSizeY = window.getSize().y - margeMap.y * 2 - SizeTileBar;

    int tileHeight = mapSizeX / sizeTileX;
    int tileWidth = mapSizeY / sizeTileY;

    //Grille Pathfinder
    Grid* grid = new Grid(tileWidth, tileHeight, sizeTileX, sizeTileY);
    grid->AddObstacle((int)TileType::Wall);
    astar =new AstarExe(grid);

    for (int i = 0; i < tileWidth; i++)
    {
        for (int j = 0; j < tileHeight; j++)
        {
            auto tile = new SquareTile();
            mTiles.push_back(tile);
            tile->SetTileType<TileType::Ground>();
            tile->SetTilePosition(currentPosition);
            //TO TEST PATHFINDING
            if (currentPosition.x == 0 && currentPosition.y == 0) {
                tile->SetTileType<TileType::Start>();
            }

            if (currentPosition.x == 15 && currentPosition.y == 15) {
                tile->SetTileType<TileType::End>();
            }

            if (currentPosition.x > 10 && currentPosition.x < 12 && ((currentPosition.y >= 0 && currentPosition.y < 22) || (currentPosition.y > 24 && currentPosition.y < 30))) {
                tile->SetTileType<TileType::Wall>();
            }

            grid->SetNodeInGrid((int)tile->GetTileType(), currentPosition.x, currentPosition.y);

            currentPosition.x++;
        }
        currentPosition.x = 0;
        currentPosition.y++;
    }

    grid->InitGrid();
    astar->Start();

    
    return true;
}

void Scene::leftClickAction(sf::Vector2i mousePosition)
{
    Tile* tile = getTile(mousePosition);
    if (tile != nullptr)
    {
        tile->SetTileType<TileType::Wall>();
    }
}


void Scene::start() {
    
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    leftClickAction(sf::Mouse::getPosition(window));
                }
            }
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
   // astar->Update();
    /*if (start && end)
        pathfinding.update();*/
    astar->Update();
}

void Scene::render()
{
    for (auto& tile : mTiles)
    {
        SpriteRenderer().render(tile->GetSprite(), &window);
    }
    
    /*if (start and end)
        pathfinding.render(&windows);*/
    astar->Draw(window, margeMap.x, margeMap.y);
    
}