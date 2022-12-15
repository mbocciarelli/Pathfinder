#include <SFML/Graphics.hpp>
#include "Entity/Tile.hpp"

class Button
{
private:
    sf::RectangleShape* sh;
    std::string txt;
    sf::Color m_color;
    TileType m_type;
    sf::Sprite* sprite;
    sf::Text textSprite;


public:
    Button() {};

    void CreateButton(sf::RectangleShape* shape, std::string text, sf::Color color, TileType type)
    {
        sh = shape;
        txt = text;
        m_color = color;
        m_type = type;
        // set sprite from shape and color
        sf::Texture texture;
        texture.create(shape->getSize().x, shape->getSize().y);
        sprite = new sf::Sprite(texture);
        sprite->setColor(color);
        sprite->setPosition(shape->getPosition());
        // set text sprite
        sf::Texture textTexture;
        textSprite.setString(text);
        textSprite.setFont(sf::Font());
        textSprite.setCharacterSize(20);
        sf::Color textColor;
        sf::Color outlineColor;
        if (color.r > 127 && color.g > 127 && color.b > 127)
        {
            textColor = sf::Color::Black;
            outlineColor = sf::Color::White;
        }
        else
        {
            textColor = sf::Color::White;
            outlineColor = sf::Color::Black;
        }
        textSprite.setFillColor(textColor);
        textSprite.setOutlineColor(outlineColor);
        textSprite.setOutlineThickness(1);
        // set text width from button sprite
        textSprite.setPosition(shape->getPosition().x + shape->getSize().x / 2 - textSprite.getLocalBounds().width / 2, shape->getPosition().y + shape->getSize().y / 2 - textSprite.getLocalBounds().height / 2);
        textTexture.create(textSprite.getLocalBounds().width, textSprite.getLocalBounds().height);
    }
};