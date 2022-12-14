#include <SFML/Graphics.hpp>
//#include <PathfindingSystem.hpp>

#include <vector>
#include "Scene.hpp"
#include "InputManager/InputManager.h"


int main()
{
    //Bar();
    /*sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

    std::vector<sf::CircleShape> shapes;

    int l = 0, c = 0;
    for (int i = 0; i < 10000; i++)
    {
        sf::CircleShape shape(50.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(sf::Vector2f(l * 100.f, c * 100.f));
        shapes.push_back(shape);

        ++l;
        if (l * 100.f > 1920 - 100.f)
        {
            l = 0;
            ++c;
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(sf::CircleShape shape : shapes)
            window.draw(shape);
        window.display();
    }*/

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    InputManager::InputManager inputManager;
    // new textfield
    auto *textField = new InputManager::TextField();
    inputManager.AddNode(textField);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //inputManager.Draw(window);
        try {
            inputManager.Draw(window);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        window.display();
    }
/*
    Scene scene;
    
    if(scene.init())
        scene.start();
*/

    return 0;
}