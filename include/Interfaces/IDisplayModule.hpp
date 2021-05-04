/*
** EPITECH PROJECT, 2021
** OOP_arcade_Interface
** File description:
** IDisplayModule
*/

#ifndef IDISPLAY_MODULE_HPP_
#define IDISPLAY_MODULE_HPP_

#include <stddef.h>
#include <string>
#include <utility>

#include "Vector.hpp"

namespace plazza
{
    typedef Vector Coord;

    class IDisplayModule {
      public:
        typedef enum class Color_s { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE } Color;

        typedef enum class EKeyList {
            // GUI
            NEXT_GAME,
            PREV_GAME,
            NEXT_LIB,
            PREV_LIB,
            RESTART_GAME,
            MENU,
            EXIT,
            PAUSE,
            // Keys
            KEY_A,
            KEY_B,
            KEY_C,
            KEY_D,
            KEY_E,
            KEY_F,
            KEY_G,
            KEY_H,
            KEY_I,
            KEY_J,
            KEY_K,
            KEY_L,
            KEY_M,
            KEY_N,
            KEY_O,
            KEY_P,
            KEY_Q,
            KEY_R,
            KEY_S,
            KEY_T,
            KEY_U,
            KEY_V,
            KEY_W,
            KEY_X,
            KEY_Y,
            KEY_Z,
            // Num
            KEY_1,
            KEY_2,
            KEY_3,
            KEY_4,
            KEY_5,
            KEY_6,
            KEY_7,
            KEY_8,
            KEY_9,
            KEY_0,
            // Special
            ARROW_UP,
            ARROW_DOWN,
            ARROW_LEFT,
            ARROW_RIGHT,
            BACK_SPACE,
            KEY_SPACE,
            KEY_MOUSE_CLICK,
            ENTER
        } KeyList;

        virtual ~IDisplayModule() = default;

        virtual void open(Vector screenSize, Vector screenScale) = 0;
        virtual void close() = 0;
        virtual bool isOpen() const = 0;

        virtual void putRectFill(Color color, Coord size, Coord pos) = 0;
        virtual void putRectOutline(Color color, Coord size, Coord pos) = 0;
        virtual void putCircle(Color color, Coord pos, size_t radius) = 0;
        virtual void putText(Color color, Coord pos, std::string const &value) = 0;

        virtual void displayScreen() = 0;
        virtual void refreshScreen() = 0;
        virtual void clearScreen() = 0;

        virtual bool isKeyPress(const KeyList key) const = 0;
        virtual bool isMouseClicked() const = 0; // Any key of the mouse
        virtual Coord getMousePos() const = 0;
    };
} // namespace plazza

#endif /* !IDISPLAYMODULE_HPP_ */
