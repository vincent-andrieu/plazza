/*
** EPITECH PROJECT, 2021
** Plazza
** File description:
** UserInput.hpp
*/

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include "Interfaces/IDisplayModule.hpp"

#include <string>
#include <memory>
#include <unordered_map>

using namespace plazza;

#define USERMAXLEN 300

class UserInput {
  public:
    UserInput();
    ~UserInput();
    void reset();
    void runInput(std::shared_ptr<IDisplayModule> module);
    std::string getInput() const;
    void setInputState(std::string line);

  private:
    std::string _input;
    const std::unordered_map<IDisplayModule::KeyList, char> _link = {
        {IDisplayModule::KeyList::KEY_A, 'A'}, // A
        {IDisplayModule::KeyList::KEY_B, 'B'}, // B
        {IDisplayModule::KeyList::KEY_C, 'C'}, // C
        {IDisplayModule::KeyList::KEY_D, 'D'}, // D
        {IDisplayModule::KeyList::KEY_E, 'E'}, // E
        {IDisplayModule::KeyList::KEY_F, 'F'}, // F
        {IDisplayModule::KeyList::KEY_G, 'G'}, // G
        {IDisplayModule::KeyList::KEY_H, 'H'}, // H
        {IDisplayModule::KeyList::KEY_I, 'I'}, // I
        {IDisplayModule::KeyList::KEY_J, 'J'}, // J
        {IDisplayModule::KeyList::KEY_K, 'K'}, // K
        {IDisplayModule::KeyList::KEY_L, 'L'}, // L
        {IDisplayModule::KeyList::KEY_M, 'M'}, // M
        {IDisplayModule::KeyList::KEY_N, 'N'}, // N
        {IDisplayModule::KeyList::KEY_O, 'O'}, // O
        {IDisplayModule::KeyList::KEY_P, 'P'}, // P
        {IDisplayModule::KeyList::KEY_Q, 'Q'}, // Q
        {IDisplayModule::KeyList::KEY_R, 'R'}, // R
        {IDisplayModule::KeyList::KEY_S, 'S'}, // S
        {IDisplayModule::KeyList::KEY_T, 'T'}, // T
        {IDisplayModule::KeyList::KEY_U, 'U'}, // U
        {IDisplayModule::KeyList::KEY_V, 'V'}, // V
        {IDisplayModule::KeyList::KEY_W, 'W'}, // W
        {IDisplayModule::KeyList::KEY_X, 'X'}, // X
        {IDisplayModule::KeyList::KEY_Y, 'Y'}, // Y
        {IDisplayModule::KeyList::KEY_Z, 'Z'}, // Z
        {IDisplayModule::KeyList::KEY_1, '1'}, // 1
        {IDisplayModule::KeyList::KEY_2, '2'}, // 2
        {IDisplayModule::KeyList::KEY_3, '3'}, // 3
        {IDisplayModule::KeyList::KEY_4, '4'}, // 4
        {IDisplayModule::KeyList::KEY_5, '5'}, // 5
        {IDisplayModule::KeyList::KEY_6, '6'}, // 6
        {IDisplayModule::KeyList::KEY_7, '7'}, // 7
        {IDisplayModule::KeyList::KEY_8, '8'}, // 8
        {IDisplayModule::KeyList::KEY_9, '9'}, // 9
        {IDisplayModule::KeyList::KEY_0, '0'}, // 0
        {IDisplayModule::KeyList::KEY_SPACE, ' '}, // ' '
        {IDisplayModule::KeyList::ENTER, '\n'}, // '\n'
        {IDisplayModule::KeyList::SEMICOLON, ';'}, // ';'
    };
};

#endif