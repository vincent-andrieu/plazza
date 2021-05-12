/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-vincent.andrieu
** File description:
** SdlModule
*/

#ifndef SDLMODULE_HPP_
#define SDLMODULE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include "IDisplayModule.hpp"

#define WIN_TITLE            "Plazza"
#define OUTLINE_WIDTH        1
#define TEXT_SIZE            20.1
#define RADIUS_COEF          4
#define ASSETS_FILEPATH      "assets/"
#define ASSET_FILE(filepath) (std::string(ASSETS_FILEPATH) + filepath)

using namespace plazza;

class SdlModule : public IDisplayModule {
  public:
    SdlModule();
    ~SdlModule();

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
    void _refreshKeys();
    bool isEqualKey(const SDL_Event event, const IDisplayModule::KeyList key) const;
    bool isMouseClicked() const; // Any key of the mouse
    Coord getMousePos() const;

  private:
    bool _isOpen;
    Vector _screenSize;
    Vector _screenScale;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    TTF_Font *_police;

    std::vector<SDL_Event> _keysBuffer;

    std::unordered_map<IDisplayModule::Color, SDL_Color> _colorList = {{IDisplayModule::Color::BLACK, SDL_Color{0, 0, 0, 255}},
        {IDisplayModule::Color::RED, SDL_Color{255, 0, 0, 255}}, {IDisplayModule::Color::GREEN, SDL_Color{0, 255, 0, 255}},
        {IDisplayModule::Color::YELLOW, SDL_Color{255, 255, 0, 255}}, {IDisplayModule::Color::BLUE, SDL_Color{0, 0, 255, 255}},
        {IDisplayModule::Color::MAGENTA, SDL_Color{255, 0, 255, 255}}, {IDisplayModule::Color::CYAN, SDL_Color{0, 255, 255, 255}},
        {IDisplayModule::Color::WHITE, SDL_Color{255, 255, 255, 255}}};

    std::unordered_map<IDisplayModule::KeyList, SDL_Keycode> _keyList = {
        // GUI
        {IDisplayModule::KeyList::NEXT_GAME, SDLK_1},            // &
        {IDisplayModule::KeyList::PREV_GAME, SDLK_2},            // é
        {IDisplayModule::KeyList::NEXT_LIB, SDLK_3},             // "
        {IDisplayModule::KeyList::PREV_LIB, SDLK_4},             // '
        {IDisplayModule::KeyList::RESTART_GAME, SDLK_BACKSPACE}, // back space
        {IDisplayModule::KeyList::MENU, SDLK_m},                 // M
        {IDisplayModule::KeyList::EXIT, SDLK_COMMA},             // ,
        {IDisplayModule::KeyList::PAUSE, SDLK_p},                // P
        // Keys
        {IDisplayModule::KeyList::KEY_A, SDLK_a}, // A
        {IDisplayModule::KeyList::KEY_B, SDLK_b}, // B
        {IDisplayModule::KeyList::KEY_C, SDLK_c}, // C
        {IDisplayModule::KeyList::KEY_D, SDLK_d}, // D
        {IDisplayModule::KeyList::KEY_E, SDLK_e}, // E
        {IDisplayModule::KeyList::KEY_F, SDLK_f}, // F
        {IDisplayModule::KeyList::KEY_G, SDLK_g}, // G
        {IDisplayModule::KeyList::KEY_H, SDLK_h}, // H
        {IDisplayModule::KeyList::KEY_I, SDLK_i}, // I
        {IDisplayModule::KeyList::KEY_J, SDLK_j}, // J
        {IDisplayModule::KeyList::KEY_K, SDLK_k}, // K
        {IDisplayModule::KeyList::KEY_L, SDLK_l}, // L
        {IDisplayModule::KeyList::KEY_M, SDLK_m}, // M
        {IDisplayModule::KeyList::KEY_N, SDLK_n}, // N
        {IDisplayModule::KeyList::KEY_O, SDLK_o}, // O
        {IDisplayModule::KeyList::KEY_P, SDLK_p}, // P
        {IDisplayModule::KeyList::KEY_Q, SDLK_q}, // Q
        {IDisplayModule::KeyList::KEY_R, SDLK_r}, // R
        {IDisplayModule::KeyList::KEY_S, SDLK_s}, // S
        {IDisplayModule::KeyList::KEY_T, SDLK_t}, // T
        {IDisplayModule::KeyList::KEY_U, SDLK_u}, // U
        {IDisplayModule::KeyList::KEY_V, SDLK_v}, // V
        {IDisplayModule::KeyList::KEY_W, SDLK_w}, // W
        {IDisplayModule::KeyList::KEY_X, SDLK_x}, // X
        {IDisplayModule::KeyList::KEY_Y, SDLK_y}, // Y
        {IDisplayModule::KeyList::KEY_Z, SDLK_z}, // Z
        // Num
        {IDisplayModule::KeyList::KEY_1, SDLK_1}, // 1
        {IDisplayModule::KeyList::KEY_2, SDLK_2}, // 2
        {IDisplayModule::KeyList::KEY_3, SDLK_3}, // 3
        {IDisplayModule::KeyList::KEY_4, SDLK_4}, // 4
        {IDisplayModule::KeyList::KEY_5, SDLK_5}, // 5
        {IDisplayModule::KeyList::KEY_6, SDLK_6}, // 6
        {IDisplayModule::KeyList::KEY_7, SDLK_7}, // 7
        {IDisplayModule::KeyList::KEY_8, SDLK_8}, // 8
        {IDisplayModule::KeyList::KEY_9, SDLK_9}, // 9
        {IDisplayModule::KeyList::KEY_0, SDLK_0}, // 0
        // Special
        {IDisplayModule::KeyList::ARROW_UP, SDLK_UP},             // arrow up
        {IDisplayModule::KeyList::ARROW_DOWN, SDLK_DOWN},         // arrow down
        {IDisplayModule::KeyList::ARROW_LEFT, SDLK_LEFT},         // arrow left
        {IDisplayModule::KeyList::ARROW_RIGHT, SDLK_RIGHT},       // arrow right
        {IDisplayModule::KeyList::BACK_SPACE, SDLK_BACKSPACE},    // backspace
        {IDisplayModule::KeyList::KEY_SPACE, SDLK_SPACE},         // space
        {IDisplayModule::KeyList::KEY_MOUSE_CLICK, SDLK_UNKNOWN}, // click souris
        {IDisplayModule::KeyList::ENTER, SDLK_KP_ENTER},          // enter
        {IDisplayModule::KeyList::SEMICOLON, SDLK_SEMICOLON}      // ;
    };
};

#endif /* !SDLMODULE_HPP_ */