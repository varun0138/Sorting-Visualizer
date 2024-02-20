#pragma once

#include <SFML/Graphics.hpp>


class Button {

    sf::RectangleShape m_button;
    sf::Font m_font;
    sf::Text m_text;
    
    sf::Vector2f m_pos;
    sf::Vector2f m_dim;

    sf::Color m_fillColor;
    sf::Color m_clickFillColor;

    float m_outlineThickness;
    sf::Color m_outlineColor;

    std::string m_string;
    sf::Color m_textColor;

    sf::Vector2f m_origin;

public:

    Button();

    void draw(sf::RenderWindow& window);
    void loadText(sf::RenderWindow& window);
    bool isOver(sf::Vector2i mousePos);

    // 
    void setFont(sf::Font& font);

    void setSize(sf::Vector2f dim);
    void setSize(float x, float y);
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);
    void setFillColor(sf::Color color);
    void setClickFillColor(sf::Color color);

    void setOutlineThickness(float thickness);
    void setOutlineColor(sf::Color color);

    void setString(const std::string& text);
    void setTextColor(sf::Color color);

    void setOrigin(sf::Vector2f origin);

    // 
    sf::RectangleShape& getButton();
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
    sf::Color getFillColor() const;
    sf::Color getClickedFillColor() const;
    float getOutlineThickness() const;
    sf::Color getOutlineColor() const;
    std::string getString() const;
    sf::Color getTextColor() const;


    

};
