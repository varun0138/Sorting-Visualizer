#include "Slider.hpp"

#include <cmath>

static float mapValue(float value, float inMin, float inMax, float outMin, float outMax) {
    return outMin + (value - inMin) * (outMax - outMin) / (inMax - inMin);
}

Slider::Slider() {}

void Slider::draw(sf::RenderWindow& window) {
    
    setRange(m_start, m_end);

    m_track.draw(window);
    m_handle.draw(window);

    if(m_drag) {
        moveHandle(window);
    }

}

void Slider::setRange(float start, float end) {
    m_start = start;
    m_end = end;

    m_current = mapValue(m_handle.getPosition().x, m_trackPos.x, m_trackPos.x + m_trackDim.x - m_handle.getSize().x, m_start, m_end);
    setSliderText(std::to_string(m_current));

}

bool Slider::isOver(sf::Vector2i mousePos) {
    if(m_trackPos.x <= mousePos.x && mousePos.x <= m_trackPos.x + m_trackDim.x) {
        if(m_trackPos.y <= mousePos.y && mousePos.y <= m_trackPos.y + m_trackDim.y) {
            return true;
        }
    }
    return false;
}

void Slider::moveHandle(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window) ;

    if(m_track.isOver(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(mousePos.x >= m_trackPos.x && mousePos.x + m_handle.getSize().x <= m_trackPos.x + m_trackDim.x) {
            m_handle.setPosition(mousePos.x, m_handle.getPosition().y);
        }    
    }
}

void Slider::setFont(sf::Font& font) {
    m_track.setFont(font);
    m_handle.setFont(font);
}

void Slider::setSize(sf::Vector2f dim) {
    m_trackDim = dim;
    m_track.setSize(dim);
    m_handle.setSize(sf::Vector2f(dim.x/4, dim.y));
}

void Slider::setSize(float x, float y) {
    m_trackDim = sf::Vector2f(x, y);
    m_track.setSize(x, y);
    m_handle.setSize(sf::Vector2f(x/4, y));
}

void Slider::setPosition(sf::Vector2f pos) {
    m_trackPos = pos;
    m_track.setPosition(pos);
    m_handle.setPosition(pos);
}

void Slider::setPosition(float x, float y) {
    m_trackPos = sf::Vector2f(x, y);
    m_track.setPosition(x, y);
    m_handle.setPosition(sf::Vector2f(x, y));
}

void Slider::setFillColor(sf::Color color) {
    m_track.setFillColor(color);
    m_handle.setFillColor(color);
}

void Slider::setClickFillColor(sf::Color color) {
    m_track.setClickFillColor(color);
    m_handle.setClickFillColor(color);
}

void Slider::setOutlineThickness(float thickness) {
    m_track.setOutlineThickness(thickness);
    m_handle.setOutlineThickness(thickness - 1);
}

void Slider::setOutlineColor(sf::Color color) {
    m_track.setOutlineColor(color);
    m_handle.setOutlineColor(color);
}

void Slider::setSliderButton(Button& button) {
    m_handle = button;
}


void Slider::setSliderText(const std::string& text) {
    m_handle.setString(text);
    m_handle.setTextColor(sf::Color::White);
}

int Slider::getCurrentValue() const {
    return m_current;
}

void Slider::setDrag(bool drag) {
    m_drag = drag;
}

bool Slider::getDrag() const {
    return m_drag;
}