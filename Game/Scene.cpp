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
            //TO TEST PATHFINDING
           /* if (currentPosition.x == 1 && currentPosition.y == 4) {
                tile->SetTileType<TileType::Start>();
            }

            if (currentPosition.x == 20 && currentPosition.y == 10) {
                tile->SetTileType<TileType::End>();
            }*/

            grid->SetNodeInGrid((int)tile->GetTileType(), currentPosition.x, currentPosition.y);

            currentPosition.x++;
        }

        font = new sf::Font();
        if (!font->loadFromFile("../../../../game/arial.ttf"))
        {
            // error...
            std::cout << "pas de font" << std::endl;
        };
        //TEXT ADD START
        textaddstart = new sf::Text();
        textaddstart->setFont(*font);
        textaddstart->setString("Press S to select START");
        textaddstart->setCharacterSize(24); // in pixels, not points!
        textaddstart->setFillColor(sf::Color::Green);
        textaddstart->setStyle(sf::Text::Bold | sf::Text::Underlined);
        textaddstart->setPosition(150, window.getSize().y - 150);
        //Text add GOAL
        textaddgoal = new sf::Text();
        textaddgoal->setFont(*font);
        textaddgoal->setString("Press E to select END");
        textaddgoal->setCharacterSize(24); // in pixels, not points!
        textaddgoal->setFillColor(sf::Color::Red);
        textaddgoal->setStyle(sf::Text::Bold | sf::Text::Underlined);
        textaddgoal->setPosition(600, window.getSize().y - 150);
        //TEXT ADD PORTAL
        textaddportal = new sf::Text();
        textaddportal->setFont(*font);
        textaddportal->setString("Press P to select PORTAL");
        textaddportal->setCharacterSize(24); // in pixels, not points!
        textaddportal->setFillColor(sf::Color(163,73,164));
        textaddportal->setStyle(sf::Text::Bold | sf::Text::Underlined);
        textaddportal->setPosition(1050, window.getSize().y - 150);
        //TEXT ADD WALL
        textaddwall = new sf::Text();
        textaddwall->setFont(*font);
        textaddwall->setString("Press W to select WALL");
        textaddwall->setCharacterSize(24); // in pixels, not points!
        textaddwall->setFillColor(sf::Color(200, 84, 124));
        textaddwall->setStyle(sf::Text::Bold | sf::Text::Underlined);
        textaddwall->setPosition(1500, window.getSize().y - 150);
        //TEXT START PATHFIND
        textStartPathfinder = new sf::Text();
        textStartPathfinder->setFont(*font);
        textStartPathfinder->setString("Press SPACE to use ASTAR");
        textStartPathfinder->setCharacterSize(24); // in pixels, not points!
        textStartPathfinder->setFillColor(sf::Color::White);
        textStartPathfinder->setStyle(sf::Text::Bold | sf::Text::Underlined);
        textStartPathfinder->setPosition(window.getSize().x/2 - 180, window.getSize().y - 100);

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
    
    window.draw(*textaddstart);
    window.draw(*textaddgoal);
    window.draw(*textaddwall);
    window.draw(*textaddportal);
    window.draw(*textStartPathfinder);
   // window.draw(*textaddstart);
}