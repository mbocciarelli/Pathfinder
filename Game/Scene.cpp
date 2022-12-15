#include "Scene.hpp"

#include "Entity/SquareTile.hpp"

#include "Astar/Grid.h"
#include "Astar/Node.h"


bool Scene::init()
{
    window.create(sf::VideoMode(1920, 1080), "SFML works!");
    sf::Texture model;
    if (!model.loadFromFile("../../../../Game/Sprite/GroundSquare.png"))
        return false;
   
    TilePosition currentPosition {0, 0};

    int sizeTileX = model.getSize().x + margeTile.x;
    int sizeTileY = model.getSize().y + margeTile.y;
    int mapSizeX = window.getSize().x - margeMap.x * 2;
    int mapSizeY = window.getSize().y - margeMap.y * 2 - SizeTileBar;

    int tileHeight = mapSizeX / sizeTileX;
    int tileWidth = mapSizeY / sizeTileY;

    //Grille Pathfinder
    grid = new Grid(tileWidth, tileHeight, sizeTileX, sizeTileY);
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
            grid->SetNodeInGrid((int)tile->GetTileType(), currentPosition.x, currentPosition.y);

            currentPosition.x++;
        }
        currentPosition.x = 0;
        currentPosition.y++;
    }

    inputManager = new InputManager();

    return true;
}

void Scene::leftClickAction(sf::Vector2i mousePosition)
{
    if (mousePosition.x > margeMap.x && mousePosition.x < window.getSize().x - margeMap.x)
    {
        if (mousePosition.y > margeMap.y && mousePosition.y < window.getSize().y - margeMap.y - SizeTileBar)
        {
            Tile* tile = getTile(mousePosition);
            if (tile != nullptr)
            {
                TileType type = inputManager->getCurrentState()->getType();
                switch (type)
                {
                case TileType::Start:
                    tile->SetTileType<TileType::Start>();
                    break;
                case TileType::End:
                    tile->SetTileType<TileType::End>();
                    break;
                case TileType::Wall:
                    tile->SetTileType<TileType::Wall>();
                    break;
                case TileType::Portal:
                    tile->SetTileType<TileType::Portal>();
                    break;
                default:
                    tile->SetTileType<TileType::Ground>();
                    break;
                }
                
                if (type == TileType::Portal)
                {
                    if (portal1 == nullptr)
                        portal1 = tile;
                    else if (portal2 == nullptr)
                        portal2 = tile;

                    if (portal1 != nullptr && portal2 != nullptr)
                        grid->SetPortalInGrid((int)TileType::Portal, portal1->GetTilePosition().x, portal1->GetTilePosition().y, portal2->GetTilePosition().x, portal2->GetTilePosition().y);
                }
                else {
                    grid->SetNodeInGrid((int)type, tile->GetTilePosition().x, tile->GetTilePosition().y);
                }
            }
        }
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
            if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::KeyPressed)
            {
                inputManager->handleInput(event.key.code);

                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    leftClickAction(sf::Mouse::getPosition(window));
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    if (grid->StartAndEndSetup() && !astar->IsStart())
                    {
                        grid->InitGrid();
                        astar->Start();
                    }
                    break;
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
   
    if(astar->IsStart())
        astar->Update();
}

void Scene::render()
{
    for (auto& tile : mTiles)
    {
        SpriteRenderer().render(tile->GetSprite(), &window);
    }
    
    if (astar->IsStart())
        astar->Draw(window, margeMap.x, margeMap.y);
    
}