/*
 * EPITECH PROJECT, 2021
 * SfmlModule
 * File description:
 * SfmlModule.hpp - Created: 17/03/2021
 */

#ifndef SFML_MODULE_HPP
#define SFML_MODULE_HPP

#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "DisplayModuleInterface.hpp"

using namespace plazza;

typedef std::string string;

#define WINDOW_NAME   "Plazza"
#define RADIUS_COEF   4
#define OUTLINE_WIDTH 9
#define TEXT_SIZE     20.1

#define ASSETS_FILEPATH      "assets/"
#define ASSET_FILE(filepath) (string(ASSETS_FILEPATH) + filepath)

class SfmlModule : public IDisplayModule {
  public:
    SfmlModule();
    ~SfmlModule();

    void open(Vector screenSize, Vector screenScale);
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

    bool isEqualKeyCode(const sf::Keyboard::Key eventCode, const IDisplayModule::KeyList key) const;

  private:
    void _refreshKeys();

    Vector _screenScale;
    std::unique_ptr<sf::RenderWindow> _window;
    std::vector<sf::Event> _keysBuffer;

    std::unordered_map<IDisplayModule::Color, sf::Color> _colorList = {{IDisplayModule::Color::BLACK, sf::Color::Black},
        {IDisplayModule::Color::RED, sf::Color::Red}, {IDisplayModule::Color::GREEN, sf::Color::Green},
        {IDisplayModule::Color::YELLOW, sf::Color::Yellow}, {IDisplayModule::Color::BLUE, sf::Color::Blue},
        {IDisplayModule::Color::MAGENTA, sf::Color::Magenta}, {IDisplayModule::Color::CYAN, sf::Color::Cyan},
        {IDisplayModule::Color::WHITE, sf::Color::White}};

    std::unordered_map<IDisplayModule::KeyList, sf::Keyboard::Key> _keyList = {
        {IDisplayModule::KeyList::NEXT_GAME, sf::Keyboard::Num1},         // &
        {IDisplayModule::KeyList::PREV_GAME, sf::Keyboard::Num2},         // é
        {IDisplayModule::KeyList::NEXT_LIB, sf::Keyboard::Num3},          // "
        {IDisplayModule::KeyList::PREV_LIB, sf::Keyboard::Quote},         // '
        {IDisplayModule::KeyList::RESTART_GAME, sf::Keyboard::BackSpace}, // back space
        {IDisplayModule::KeyList::MENU, sf::Keyboard::M},                 // M
        {IDisplayModule::KeyList::EXIT, sf::Keyboard::Comma},             // ,
        {IDisplayModule::KeyList::PAUSE, sf::Keyboard::P},                // P
        // Keys
        {IDisplayModule::KeyList::KEY_A, sf::Keyboard::A}, // A
        {IDisplayModule::KeyList::KEY_B, sf::Keyboard::B}, // B
        {IDisplayModule::KeyList::KEY_C, sf::Keyboard::C}, // C
        {IDisplayModule::KeyList::KEY_D, sf::Keyboard::D}, // D
        {IDisplayModule::KeyList::KEY_E, sf::Keyboard::E}, // E
        {IDisplayModule::KeyList::KEY_F, sf::Keyboard::F}, // F
        {IDisplayModule::KeyList::KEY_G, sf::Keyboard::G}, // G
        {IDisplayModule::KeyList::KEY_H, sf::Keyboard::H}, // H
        {IDisplayModule::KeyList::KEY_I, sf::Keyboard::I}, // I
        {IDisplayModule::KeyList::KEY_J, sf::Keyboard::J}, // J
        {IDisplayModule::KeyList::KEY_K, sf::Keyboard::K}, // K
        {IDisplayModule::KeyList::KEY_L, sf::Keyboard::L}, // L
        {IDisplayModule::KeyList::KEY_M, sf::Keyboard::M}, // M
        {IDisplayModule::KeyList::KEY_N, sf::Keyboard::N}, // N
        {IDisplayModule::KeyList::KEY_O, sf::Keyboard::O}, // O
        {IDisplayModule::KeyList::KEY_P, sf::Keyboard::P}, // P
        {IDisplayModule::KeyList::KEY_Q, sf::Keyboard::Q}, // Q
        {IDisplayModule::KeyList::KEY_R, sf::Keyboard::R}, // R
        {IDisplayModule::KeyList::KEY_S, sf::Keyboard::S}, // S
        {IDisplayModule::KeyList::KEY_T, sf::Keyboard::T}, // T
        {IDisplayModule::KeyList::KEY_U, sf::Keyboard::U}, // U
        {IDisplayModule::KeyList::KEY_V, sf::Keyboard::V}, // V
        {IDisplayModule::KeyList::KEY_W, sf::Keyboard::W}, // W
        {IDisplayModule::KeyList::KEY_X, sf::Keyboard::X}, // X
        {IDisplayModule::KeyList::KEY_Y, sf::Keyboard::Y}, // Y
        {IDisplayModule::KeyList::KEY_Z, sf::Keyboard::Z}, // Z
        // Num
        {IDisplayModule::KeyList::KEY_1, sf::Keyboard::Num1}, // 1
        {IDisplayModule::KeyList::KEY_2, sf::Keyboard::Num2}, // 2
        {IDisplayModule::KeyList::KEY_3, sf::Keyboard::Num3}, // 3
        {IDisplayModule::KeyList::KEY_4, sf::Keyboard::Num4}, // 4
        {IDisplayModule::KeyList::KEY_5, sf::Keyboard::Num5}, // 5
        {IDisplayModule::KeyList::KEY_6, sf::Keyboard::Num6}, // 6
        {IDisplayModule::KeyList::KEY_7, sf::Keyboard::Num7}, // 7
        {IDisplayModule::KeyList::KEY_8, sf::Keyboard::Num8}, // 8
        {IDisplayModule::KeyList::KEY_9, sf::Keyboard::Num9}, // 9
        {IDisplayModule::KeyList::KEY_0, sf::Keyboard::Num0}, // 0
        // Special
        {IDisplayModule::KeyList::ARROW_UP, sf::Keyboard::Up},             // arrow up
        {IDisplayModule::KeyList::ARROW_DOWN, sf::Keyboard::Down},         // arrow down
        {IDisplayModule::KeyList::ARROW_LEFT, sf::Keyboard::Left},         // arrow left
        {IDisplayModule::KeyList::ARROW_RIGHT, sf::Keyboard::Right},       // arrow right
        {IDisplayModule::KeyList::BACK_SPACE, sf::Keyboard::Backspace},    // backspace
        {IDisplayModule::KeyList::KEY_SPACE, sf::Keyboard::Space},         // space
        {IDisplayModule::KeyList::KEY_MOUSE_CLICK, sf::Keyboard::Unknown}, // mouse click
        {IDisplayModule::KeyList::ENTER, sf::Keyboard::Enter},             // enter
        {IDisplayModule::KeyList::SEMICOLON, sf::Keyboard::Semicolon}};    // ;
};

#endif
