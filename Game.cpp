#include "Game.hpp"

Game::Game() {
    init();
}

void Game::setBars(int size) {
    m_bars.clear();

    m_size = size;
    m_sidePad = 5; 
    m_downPad = m_sidePad; 
    m_topPad = 100;
    m_gap = 0; 
    m_barWidth = (extend - m_sidePad*2)/m_size - m_gap; 

    for(int i = 0; i < m_size; i++) {
        m_bars.push_back(m_random.randint(10, m_height - m_topPad));
    }

    m_sortedBars = m_bars;
    std::sort(m_sortedBars.begin(), m_sortedBars.end());

    m_traverseBars = {0, 0};
}

void Game::run() {

    while(m_running) {

        if(!m_paused) {
            update();

            m_currentFrame++;
        }

        render();
        userInput();

        
    }

}

void Game::init() {

    m_font.loadFromFile("fonts/Retron2000.ttf");

    m_window.create(sf::VideoMode(m_width, m_height), "Game", sf::Style::Close | sf::Style::Titlebar);

    setBars(120);

    m_pauseButton.setFont(m_font);
    m_pauseButton.setSize(m_buttonDim);
    m_pauseButton.setPosition(extend + 90, 10);
    m_pauseButton.setFillColor(m_buttonColor);
    m_pauseButton.setClickFillColor(m_buttonClickColor);
    m_pauseButton.setOutlineThickness(2);
    m_pauseButton.setOutlineColor(sf::Color::White);
    m_pauseButton.setTextColor(sf::Color::White);

    m_shuffleButton.setFont(m_font);
    m_shuffleButton.setSize(m_buttonDim);
    m_shuffleButton.setPosition(extend + 90, 60);
    m_shuffleButton.setFillColor(m_buttonColor);
    m_shuffleButton.setClickFillColor(m_buttonClickColor);
    m_shuffleButton.setOutlineThickness(2);
    m_shuffleButton.setOutlineColor(sf::Color::White);
    m_shuffleButton.setString("SHUFFLE");
    m_shuffleButton.setTextColor(sf::Color::White);


    
    m_slider.setFont(m_font);
    m_slider.setSize(280, 20);
    m_slider.setPosition(extend + 10, 130);
    m_slider.setFillColor(m_buttonColor);
    m_slider.setClickFillColor(m_buttonClickColor);
    m_slider.setOutlineThickness(3);
    m_slider.setOutlineColor(sf::Color::White);
    m_slider.setRange(10, 200);


    m_sortAlgo = {"BUBBLE", "INSERT", "CYCLE", "QUICK", "BRICK", "SELECT", "EXCHANGE", "GNOME"};
    int x = 90;
    int y = 200;
    int gap = 10;
    for(unsigned int i = 0; i < m_sortAlgo.size(); i++) {
        Button sortButton;
        sortButton.setFont(m_font);
        sortButton.setSize(m_buttonDim);
        sortButton.setPosition(extend + x, y);
        sortButton.setFillColor(m_buttonColor);
        sortButton.setClickFillColor(m_buttonClickColor);
        sortButton.setOutlineThickness(2);
        sortButton.setOutlineColor(sf::Color::White);
        sortButton.setString(m_sortAlgo[i]);
        sortButton.setTextColor(sf::Color::White);
        m_sortButtons.push_back(sortButton);
        y += gap + m_buttonDim.y;
    }

    m_currentSortButton.setFont(m_font);
    m_currentSortButton.setSize(280, m_buttonDim.y + 10);
    m_currentSortButton.setPosition(extend + 10, y + 20);
    m_currentSortButton.setFillColor(m_buttonColor);
    m_currentSortButton.setClickFillColor(m_buttonClickColor);
    m_currentSortButton.setOutlineThickness(2);
    m_currentSortButton.setOutlineColor(sf::Color::White);
    m_currentSortButton.setString("CURRENT: " + m_sortAlgo[m_currentSort-1]);
    m_currentSortButton.setTextColor(sf::Color::White);




}

void Game::render() {

    if(m_bars == m_sortedBars) {
        resetCall();
        m_paused = true;
        m_slider.setDrag(true);
    }

    if(m_paused) {
        m_pauseButton.setString("START");
        int newSize = m_slider.getCurrentValue();
        if(newSize != m_size) {
            setBars(newSize);
        }
        
    }
    else {
        m_pauseButton.setString("PAUSE");
        m_slider.setDrag(false);
    }

    
    m_window.clear(m_background);

    sf::RectangleShape bound;
    bound.setPosition(1, 1);
    bound.setSize(sf::Vector2f(extend - m_sidePad, m_height - m_sidePad));
    bound.setFillColor(m_background);
    bound.setOutlineThickness(1);
    bound.setOutlineColor(sf::Color::White);

    m_window.draw(bound);


    loadBars(m_bars, m_sortedBars, m_traverseBars);

    m_pauseButton.draw(m_window);
    m_shuffleButton.draw(m_window);

    m_currentSortButton.setString("CURRENT: " + m_sortAlgo[m_currentSort-1]);
    m_currentSortButton.draw(m_window);

    m_slider.draw(m_window);

    for(auto& button: m_sortButtons) {
        button.draw(m_window);
    }
    

    m_window.display();

}


void Game::update() {

    

    if     (m_currentSort == 1)  {m_traverseBars = m_bubble.sort(m_bars); m_swaps = m_bubble.getSwaps();}
    else if(m_currentSort == 2)  {m_traverseBars = m_insert.sort(m_bars);}
    else if(m_currentSort == 3)  {m_traverseBars = m_cycle.sort(m_bars);}
    else if(m_currentSort == 4)  {m_traverseBars = m_quick.sort(m_bars); m_swaps = m_quick.getSwaps();}
    else if(m_currentSort == 5)  {m_traverseBars = m_brick.sort(m_bars);}
    else if(m_currentSort == 6)  {m_traverseBars = m_select.sort(m_bars);}
    else if(m_currentSort == 7)  {m_traverseBars = m_exchange.sort(m_bars);}
    else if(m_currentSort == 8)  {m_traverseBars = m_gnome.sort(m_bars);}
}

void Game::userInput() {

    

    sf::Event event;
    while(m_window.pollEvent(event)) {
        if(event.type == sf::Event::Closed) {
            m_running = false;
        }    
        if(event.type == sf::Event::MouseButtonPressed) {
            if(event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
                if(m_pauseButton.isOver(mousePos)) {
                    std::cout << "PAUSE" << std::endl;
                    m_paused = !m_paused;
                    // m_slider.setDrag(m_paused);
                }
                if(m_shuffleButton.isOver(mousePos) && m_slider.getDrag()) {
                    std::cout << "SHUFFLE" << std::endl;
                    m_swaps = 0;
                    std::random_shuffle(m_bars.begin(), m_bars.end());
                    resetCall();
                }

                for(unsigned int i = 0; i < m_sortButtons.size(); i++) {
                    if(m_sortButtons[i].isOver(mousePos)) {
                        resetCall();
                        m_currentSort = i+1;
                        std::cout << m_sortAlgo[i] << " SORT" << std::endl;
                        break;
                    }
                }   
            }  
         
        }
    }

}

void Game::loadBars(const std::vector<int>& bars, const std::vector<int>& sorted, const std::vector<int>& traverse) {
    sf::RectangleShape rect;
    float x = m_sidePad;
    for(int i = 0; i < m_size; i++) {

        float y = (m_height - m_downPad) - bars[i];

        sf::Color barColor = {239, 220, 220};
        if((i == traverse[0] || i == traverse[1]) && m_bars != m_sortedBars) {
            barColor = {255, 100, 100};
        }
        else if(bars[i] == sorted[i]) {
            barColor = {136, 219, 137}; 
        }


        rect.setFillColor(barColor);
        rect.setPosition(x, y);
        rect.setSize(sf::Vector2f(m_barWidth, bars[i]));
        m_window.draw(rect);

        x += (m_barWidth + m_gap);
    }

}


void Game::resetCall() {
    m_bubble.reset();
    m_insert.reset();
    m_cycle.reset();
    m_quick.reset();
    m_brick.reset();
    m_select.reset();
    m_exchange.reset();
    m_gnome.reset();
}