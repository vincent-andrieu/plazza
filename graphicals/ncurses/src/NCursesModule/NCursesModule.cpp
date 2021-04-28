/*
 * EPITECH PROJECT, 2021
 * src
 * File description:
 * ncurses.cpp - Created: 15/03/2021
 */

#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>
#include "NCursesModule/NCursesModule.hpp"

extern "C"
{
    std::shared_ptr<IDisplayModule> entryPoint()
    {
        return std::make_shared<NCursesModule>();
    }
}

NCursesModule::NCursesModule()
{
    this->_term.open();
    this->setMouseStat();
}

NCursesModule::~NCursesModule()
{
    this->_term.close();
}

void NCursesModule::open(UNUSED Coord screenSize, UNUSED Vector screenScale)
{
    this->_isOpen = true;
}

void NCursesModule::close()
{
    this->_isOpen = false;
}

bool NCursesModule::isOpen() const
{
    return this->_isOpen;
}

void NCursesModule::putRectFill(IDisplayModule::Color color, Coord size, Coord pos)
{
    attron(COLOR_PAIR(color));
    for (size_t x = pos.x; x < pos.x + size.x; x++)
        for (size_t y = pos.y; y < pos.y + size.y; y++)
            mvprintw(y, x, CHAR_RECT);
    attroff(COLOR_PAIR(color));
}

void NCursesModule::putRectOutline(IDisplayModule::Color color, Coord size, Coord pos)
{
    attron(COLOR_PAIR(color));
    for (size_t x = pos.x; x < pos.x + size.x - 1; x++) {
        mvprintw(pos.y, x, CHAR_RECT);
        mvprintw(pos.y + size.y - 1, x, CHAR_RECT);
    }
    for (size_t y = pos.y; y <= pos.y + size.y - 1; y++) {
        mvprintw(y, pos.x, CHAR_RECT);
        mvprintw(y, pos.x + size.x - 1, CHAR_RECT);
    }
    attroff(COLOR_PAIR(color));
}

void NCursesModule::putCircle(IDisplayModule::Color color, Coord pos, size_t radius)
{
    radius--;
    attron(COLOR_PAIR(color));
    for (size_t x = std::round(pos.x) - radius; x <= std::round(pos.x) + radius; x++)
        for (size_t y = std::round(pos.y) - radius; y <= std::round(pos.y) + radius; y++)
            if (std::floor(sqrt(pow(std::max((size_t) std::round(pos.x), x) - std::min((size_t) std::round(pos.x), x), 2)
                    + pow(std::max((size_t) std::round(pos.y), y) - std::min((size_t) std::round(pos.y), y), 2)))
                == radius)
                mvprintw(y, x, CHAR_CIRCLE);
    attroff(COLOR_PAIR(color));
}

void NCursesModule::putText(IDisplayModule::Color color, Coord pos, std::string const &value)
{
    attron(COLOR_PAIR(color));
    mvprintw(pos.y, pos.x, value.c_str());
    attroff(COLOR_PAIR(color));
}

void NCursesModule::displayScreen()
{
}

void NCursesModule::refreshScreen()
{
    refresh();
    this->setMouseStat();
    this->_keysBuffer.clear();
    for (int code = getch(); code != ERR; code = getch())
        this->_keysBuffer.push_back(code);
}

void NCursesModule::clearScreen()
{
    clear();
}

bool NCursesModule::isKeyPress(const IDisplayModule::KeyList key) const
{
    return std::find(this->_keysBuffer.begin(), this->_keysBuffer.end(), this->_keyList.at(key)) != this->_keysBuffer.end();
}

Coord NCursesModule::getMousePos() const
{
    return this->_mousePos;
}

bool NCursesModule::isMouseClicked() const
{
    return this->_mouseClicked;
}

void NCursesModule::setMouseStat()
{
    MEVENT mEvent;

    this->_mouseClicked = this->isKeyPress(EKeyList::KEY_MOUSE_CLICK);
    if (getmouse(&mEvent) == OK) {
        this->_mousePos = Coord(mEvent.x, mEvent.y);
    } else {
        this->_mousePos = Coord(0, 0);
    }
}