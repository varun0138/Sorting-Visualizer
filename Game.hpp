#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <algorithm>

#include "maths/Random.hpp"
#include "algorithms/include/BubbleSort.hpp"
#include "algorithms/include/InsertionSort.hpp"
#include "algorithms/include/CycleSort.hpp"
#include "algorithms/include/QuickSort.hpp"
#include "algorithms/include/BrickSort.hpp"
#include "algorithms/include/SelectionSort.hpp"
#include "algorithms/include/ExchangeSort.hpp"
#include "algorithms/include/GnomeSort.hpp"

#include "utils/Button.hpp"
#include "utils/Slider.hpp"


class Game {

private:
    const float m_width = 1600.0f;
    const float m_height = 720.0f; 

    const float extend = 1290.0f;    

    int m_size = 0;
    float m_sidePad = 5; // left & right side padding in the window
    float m_downPad = m_sidePad; // bottom padding
    float m_topPad = 100; // top padding
    int   m_gap = 0; // gap between the bars
    float m_barWidth = (extend - m_sidePad*2)/m_size - m_gap; // width of bars

    const sf::Color m_background = {20, 25, 30};

    sf::RenderWindow m_window;
    Random           m_random;
    sf::Font         m_font;
    sf::Text         m_text;

    BubbleSort     m_bubble;
    InsertionSort  m_insert;
    CycleSort      m_cycle;
    QuickSort      m_quick;
    BrickSort      m_brick;
    SelectionSort  m_select;
    ExchangeSort   m_exchange;
    GnomeSort      m_gnome;

    Slider m_slider;
    Button m_pauseButton;
    Button m_shuffleButton;
    Button m_currentSortButton;

    std::vector<std::string> m_sortAlgo;
    std::vector<Button> m_sortButtons;
    const sf::Color m_buttonColor = {20, 25, 30};
    const sf::Color m_buttonClickColor = {146, 134, 148};
    const sf::Vector2f m_buttonDim = {120, 40};

    std::vector<int> m_bars;
    std::vector<int> m_sortedBars;
    std::vector<int> m_traverseBars;

    bool m_running = true;
    bool m_paused = true;
    int  m_swaps = 0;
    int  m_currentSort = 1;
    int  m_currentFrame = 0;

    void init();
    void render();
    void update();
    void userInput();
    void loadBars(const std::vector<int>& bars, const std::vector<int>& sorted, const std::vector<int>& traverse);
    void resetCall();
    void setBars(int size);

public:

    Game();
    void run();

};


