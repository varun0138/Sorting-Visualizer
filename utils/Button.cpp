#include "Button.hpp"

Button::Button() {

}

void Button::draw(sf::RenderWindow& window) {

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    
    m_button.setSize(m_dim);
    m_button.setPosition(m_pos);
    m_button.setOrigin(m_origin);

    if(isOver(mousePos)) m_button.setFillColor(m_clickFillColor);
    else m_button.setFillColor(m_fillColor);
    
    m_button.setOutlineColor(m_outlineColor);
    m_button.setOutlineThickness(m_outlineThickness);
    
    window.draw(m_button);
    loadText(window);
}

void Button::loadText(sf::RenderWindow& window) {

    m_text.setString(m_string);
    m_text.setFont(m_font);

    m_text.setFillColor(m_textColor);

    unsigned int textSize = static_cast<unsigned int>(std::min(m_dim.x / m_string.length(), m_dim.y) * 1.2f);
    m_text.setCharacterSize(textSize);

    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setPosition(m_pos.x + (m_dim.x - textRect.width)/2, m_pos.y + (m_dim.y - textRect.height)/2 - textRect.top);

    window.draw(m_text);
}

bool Button::isOver(sf::Vector2i mousePos) {
    if(m_pos.x <= mousePos.x && mousePos.x <= m_pos.x + m_dim.x) {
        if(m_pos.y <= mousePos.y && mousePos.y <= m_pos.y + m_dim.y) {
            return true;
        }
    }
    return false;
}


void Button::setFont(sf::Font& font) {
    m_font = font;
}

void Button::setSize(sf::Vector2f dim) {
    m_dim = dim;
}

void Button::setSize(float x, float y) {
    m_dim = sf::Vector2f(x, y);
    // m_dim.x = x; m_dim.y = y;
}

void Button::setPosition(sf::Vector2f pos) {
    m_pos = pos;
}

void Button::setPosition(float x, float y) {
    m_pos = sf::Vector2f(x, y);
    // m_pos.x = x; m_pos.y = y;
}

void Button::setFillColor(sf::Color color) {
    m_fillColor = color;
}

void Button::setClickFillColor(sf::Color color) {
    m_clickFillColor = color;
}

void Button::setOutlineThickness(float thickness) {
    m_outlineThickness = thickness;
}

void Button::setOutlineColor(sf::Color color) {
    m_outlineColor = color;
}

void Button::setString(const std::string& text) {
    m_string = text;
}

void Button::setTextColor(sf::Color color) {
    m_textColor = color;
}

sf::RectangleShape& Button::getButton() {
    return m_button;
}

void Button::setOrigin(sf::Vector2f origin) {
    m_origin = origin;
}


sf::Vector2f Button::getPosition() const {
    return m_pos;
}

sf::Vector2f Button::getSize() const {
    return m_dim;
}