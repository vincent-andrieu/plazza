/*
 * EPITECH PROJECT, 2021
 * SfmlModule
 * File description:
 * SfmlModule.cpp - Created: 16/03/2021
 */

#include <memory>
#include <algorithm>
#include <exception>
#include "SfmlModule/SfmlModule.hpp"

extern "C"
{
    std::shared_ptr<IDisplayModule> entryPoint()
    {
        return std::make_shared<SfmlModule>();
    }
}

void SfmlModule::open(Vector screenSize, Vector screenScale)
{
    this->_screenScale = screenScale;
    this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(screenSize.x, screenSize.y), WINDOW_NAME);
    this->_window->setTitle(WINDOW_NAME);
    this->_window->setFramerateLimit(30);
}

void SfmlModule::close()
{
    if (this->_window) {
        this->_window->close();
        this->_window.release();
    }
}

bool SfmlModule::isOpen() const
{
    if (this->_window)
        return this->_window->isOpen();
    return false;
}

void SfmlModule::putRectFill(plazza::IDisplayModule::Color color, plazza::Coord size, plazza::Coord pos)
{
    sf::RectangleShape rect({(float) (size.x * this->_screenScale.x), (float) (size.y * this->_screenScale.y)});

    rect.setPosition({(float) (pos.x * this->_screenScale.x), (float) (pos.y * this->_screenScale.y)});
    rect.setFillColor(this->_colorList.at(color));

    this->_window->draw(rect);
}

void SfmlModule::putRectOutline(plazza::IDisplayModule::Color color, plazza::Coord size, plazza::Coord pos)
{
    sf::RectangleShape rect({(float) (size.x * this->_screenScale.x - OUTLINE_WIDTH * 2),
        (float) (size.y * this->_screenScale.y - OUTLINE_WIDTH * 2)});

    rect.setPosition(
        {(float) (pos.x * this->_screenScale.x + OUTLINE_WIDTH), (float) (pos.y * this->_screenScale.y + OUTLINE_WIDTH)});
    rect.setOutlineColor(this->_colorList.at(color));
    rect.setOutlineThickness(OUTLINE_WIDTH);
    rect.setFillColor(sf::Color::Transparent);

    this->_window->draw(rect);
    this->putRectFill(color, Coord(size.x, 1), Coord(pos.x, pos.y + 0.1));
    this->putRectFill(color, Coord(size.x, 1), Coord(pos.x, pos.y + size.y - 1));
}

void SfmlModule::putCircle(plazza::IDisplayModule::Color color, plazza::Coord pos, size_t radius)
{
    sf::CircleShape circle(radius * RADIUS_COEF);
    const float x = pos.x * this->_screenScale.x + ((pos.x + 1) * this->_screenScale.x - (pos.x * this->_screenScale.x)) / 2
        - (radius * RADIUS_COEF);
    const float y = pos.y * this->_screenScale.y + ((pos.y + 1) * this->_screenScale.y - (pos.y * this->_screenScale.y)) / 2
        - (radius * RADIUS_COEF);

    circle.setPosition({x, y});
    circle.setFillColor(this->_colorList.at(color));

    this->_window->draw(circle);
}

void SfmlModule::putText(plazza::IDisplayModule::Color color, plazza::Coord pos, std::string const &value)
{
    sf::Font font;
    if (!font.loadFromFile(ASSET_FILE("font.ttf")))
        return;

    sf::Text text(value, font, TEXT_SIZE);

    text.setPosition({(float) (pos.x * this->_screenScale.x), (float) (pos.y * this->_screenScale.y)});
    text.setFillColor(this->_colorList.at(color));
    text.setString(value);

    if (this->_window)
        this->_window->draw(text);
}

void SfmlModule::displayScreen()
{
    if (this->_window)
        this->_window->display();
}

void SfmlModule::refreshScreen()
{
    this->_refreshKeys();
}

void SfmlModule::_refreshKeys()
{
    sf::Event event{};

    this->_keysBuffer.clear();
    while (this->_window && this->_window->pollEvent(event))
        if (event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::Closed
            || event.type == sf::Event::EventType::MouseButtonPressed)
            this->_keysBuffer.push_back(event);

    if (std::find_if(this->_keysBuffer.begin(), this->_keysBuffer.end(),
            [](const sf::Event &event) {
                return event.type == sf::Event::Closed;
            })
        != this->_keysBuffer.end())
        this->close();
}

void SfmlModule::clearScreen()
{
    if (this->_window)
        this->_window->clear();
}

bool SfmlModule::isKeyPress(const IDisplayModule::KeyList key) const
{
    return std::find_if(this->_keysBuffer.begin(), this->_keysBuffer.end(), [this, key](const sf::Event &event) {
        return event.type == sf::Event::EventType::KeyPressed && this->isEqualKeyCode(event.key.code, key);
    }) != this->_keysBuffer.end();
}

bool SfmlModule::isEqualKeyCode(const sf::Keyboard::Key eventCode, const IDisplayModule::KeyList key) const
{
    return eventCode == this->_keyList.at(key);
}

plazza::Coord SfmlModule::getMousePos() const
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(*this->_window.get());

    return Coord(mousePos.x / this->_screenScale.x, mousePos.y / this->_screenScale.y);
}

bool SfmlModule::isMouseClicked() const
{
    return std::find_if(this->_keysBuffer.begin(), this->_keysBuffer.end(), [](const sf::Event &event) {
        return event.type == sf::Event::MouseButtonPressed;
    }) != this->_keysBuffer.end();
}