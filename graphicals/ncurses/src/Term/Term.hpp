/*
 * EPITECH PROJECT, 2021
 * include
 * File description:
 * term.cpp - Created: 23/01/2021
 */

#ifndef TERM_HPP
#define TERM_HPP

#include <term.h>

class Term {
  public:
    Term() = default;
    ~Term() = default;

    void open();
    void close();

  private:
    void setTermMode(bool toggle);
    void initNCurses();
};

#endif