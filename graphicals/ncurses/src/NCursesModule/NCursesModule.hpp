/*
 * EPITECH PROJECT, 2021
 * ncurses
 * File description:
 * ncurses.hpp - Created: 15/03/2021
 */

#ifndef NCURSES_MODULE_HPP
#define NCURSES_MODULE_HPP

#include <ncurses.h>
#include <unordered_map>
#include "IDisplayModule.hpp"
#include "Term/Term.hpp"

using namespace plazza;

#define UNUSED __attribute__((unused))

#define CHAR_RECT   "#"
#define CHAR_CIRCLE "O"

class NCursesModule : public IDisplayModule {
  public:
    NCursesModule();
    ~NCursesModule();

    void open(UNUSED Coord screenSize, UNUSED Vector screenScale);
    void close();
    bool isOpen() const;

    void putRectFill(IDisplayModule::Color color, Coord size, Coord pos);
    void putRectOutline(IDisplayModule::Color color, Coord size, Coord pos);
    void putCircle(IDisplayModule::Color color, Coord pos, size_t radius);
    void putText(IDisplayModule::Color color, Coord pos, std::string const &value);

    void displayScreen();
    void refreshScreen();
    void clearScreen();

    bool isKeyPress(const IDisplayModule::KeyList key) const;
    bool isMouseClicked() const; // Any key of the mouse
    Coord getMousePos() const;

  private:
    void setMouseStat();

  private:
    Term _term;
    bool _isOpen;
    Coord _mousePos;
    bool _mouseClicked;

    std::vector<int> _keysBuffer;

    std::unordered_map<IDisplayModule::Color, int> _colorList = {{IDisplayModule::Color::BLACK, COLOR_BLACK},
        {IDisplayModule::Color::RED, COLOR_RED}, {IDisplayModule::Color::GREEN, COLOR_GREEN},
        {IDisplayModule::Color::YELLOW, COLOR_YELLOW}, {IDisplayModule::Color::BLUE, COLOR_BLUE},
        {IDisplayModule::Color::MAGENTA, COLOR_MAGENTA}, {IDisplayModule::Color::CYAN, COLOR_CYAN},
        {IDisplayModule::Color::WHITE, COLOR_WHITE}};

    std::unordered_map<IDisplayModule::KeyList, int> _keyList = {
        {IDisplayModule::KeyList::NEXT_GAME, 38},               // &
        {IDisplayModule::KeyList::PREV_GAME, 169},              // é
        {IDisplayModule::KeyList::NEXT_LIB, 34},                // "
        {IDisplayModule::KeyList::PREV_LIB, 39},                // '
        {IDisplayModule::KeyList::RESTART_GAME, KEY_BACKSPACE}, // back space
        {IDisplayModule::KeyList::MENU, 109},                   // M
        {IDisplayModule::KeyList::EXIT, 44},                    // ,
        {IDisplayModule::KeyList::PAUSE, 112},                  // P
        // Keys
        {IDisplayModule::KeyList::KEY_A, 97},  // A
        {IDisplayModule::KeyList::KEY_B, 98},  // B
        {IDisplayModule::KeyList::KEY_C, 99},  // C
        {IDisplayModule::KeyList::KEY_D, 100}, // D
        {IDisplayModule::KeyList::KEY_E, 101}, // E
        {IDisplayModule::KeyList::KEY_F, 102}, // F
        {IDisplayModule::KeyList::KEY_G, 103}, // G
        {IDisplayModule::KeyList::KEY_H, 104}, // H
        {IDisplayModule::KeyList::KEY_I, 105}, // I
        {IDisplayModule::KeyList::KEY_J, 106}, // J
        {IDisplayModule::KeyList::KEY_K, 107}, // K
        {IDisplayModule::KeyList::KEY_L, 108}, // L
        {IDisplayModule::KeyList::KEY_M, 109}, // M
        {IDisplayModule::KeyList::KEY_N, 110}, // N
        {IDisplayModule::KeyList::KEY_O, 111}, // O
        {IDisplayModule::KeyList::KEY_P, 112}, // P
        {IDisplayModule::KeyList::KEY_Q, 113}, // Q
        {IDisplayModule::KeyList::KEY_R, 114}, // R
        {IDisplayModule::KeyList::KEY_S, 115}, // S
        {IDisplayModule::KeyList::KEY_T, 116}, // T
        {IDisplayModule::KeyList::KEY_U, 117}, // U
        {IDisplayModule::KeyList::KEY_V, 118}, // V
        {IDisplayModule::KeyList::KEY_W, 119}, // W
        {IDisplayModule::KeyList::KEY_X, 120}, // X
        {IDisplayModule::KeyList::KEY_Y, 121}, // Y
        {IDisplayModule::KeyList::KEY_Z, 122}, // Z
        // Num
        {IDisplayModule::KeyList::KEY_1, 49}, // 1
        {IDisplayModule::KeyList::KEY_2, 50}, // 2
        {IDisplayModule::KeyList::KEY_3, 51}, // 3
        {IDisplayModule::KeyList::KEY_4, 52}, // 4
        {IDisplayModule::KeyList::KEY_5, 53}, // 5
        {IDisplayModule::KeyList::KEY_6, 54}, // 6
        {IDisplayModule::KeyList::KEY_7, 55}, // 7
        {IDisplayModule::KeyList::KEY_8, 56}, // 8
        {IDisplayModule::KeyList::KEY_9, 57}, // 9
        {IDisplayModule::KeyList::KEY_0, 48}, // 0
        // Special
        {IDisplayModule::KeyList::ARROW_UP, KEY_UP},           // arrow up
        {IDisplayModule::KeyList::ARROW_DOWN, KEY_DOWN},       // arrow down
        {IDisplayModule::KeyList::ARROW_LEFT, KEY_LEFT},       // arrow left
        {IDisplayModule::KeyList::ARROW_RIGHT, KEY_RIGHT},     // arrow right
        {IDisplayModule::KeyList::BACK_SPACE, KEY_BACKSPACE},  // backspace
        {IDisplayModule::KeyList::KEY_SPACE, 32},              // space
        {IDisplayModule::KeyList::KEY_MOUSE_CLICK, KEY_MOUSE}, // click souris
        {IDisplayModule::KeyList::ENTER, 10}                   // click souris
    };
};

#endif