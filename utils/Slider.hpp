#pragma once

#include <SFML/Graphics.hpp>
#include "Button.hpp"


class Slider {

    Button m_track;
    Button m_handle;

    sf::Vector2f m_trackPos;
    sf::Vector2f m_trackDim;

    float m_start     = 0;
    float m_end       = 10;
    int   m_current   = m_start;

    std::string m_text;
    
    bool m_drag = true; // controls the handle movement


public:

    Slider();

    void draw(sf::RenderWindow& window);
    void setRange(float start, float end);
    bool isOver(sf::Vector2i mousePos);
    void moveHandle(sf::RenderWindow& window);

    void setFont(sf::Font& font);

    void setSize(sf::Vector2f dim);
    void setSize(float x, float y);
    void setPosition(sf::Vector2f pos);
    void setPosition(float x, float y);

    void setFillColor(sf::Color color);
    void setClickFillColor(sf::Color color);

    void setOutlineThickness(float thickness);
    void setOutlineColor(sf::Color color);

    void setSliderButton(Button& button);

    void setSliderText(const std::string& text);

    int getCurrentValue() const;

    void setDrag(bool drag);
    bool getDrag() const;

};