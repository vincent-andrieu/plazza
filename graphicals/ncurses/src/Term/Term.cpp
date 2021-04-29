/*
 * EPITECH PROJECT, 2021
 * text
 * File description:
 * term.cpp - Created: 23/01/2021
 */

#include <sys/ioctl.h>
#include <ncurses.h>
#include <cstring>
#include <stdlib.h>
#include <exception>
#include "Term/Term.hpp"

Term::Term()
{
}

Term::~Term()
{
}

void Term::open()
{
    const char *term_env = getenv("TERM");
    const char *keypad_mode = tigetstr("smkx");

    if (term_env == NULL)
        throw std::exception(); // No term env
    if (keypad_mode == NULL)
        throw std::exception(); // Keypad mode error
    putp(keypad_mode);
    initscr();
    this->setTermMode(false);
    this->initNCurses();
}

void Term::close()
{
    this->setTermMode(true);
    endwin();
}

void Term::setTermMode(bool toggle)
{
    static struct termios old_term;
    struct termios new_term;

    if (!toggle) {
        if (ioctl(0, TCGETS, &old_term) || ioctl(0, TCGETS, &new_term))
            throw std::exception(); // Fail to get terms
        new_term.c_lflag &= ~ECHO;
        new_term.c_lflag &= ~ICANON;
        new_term.c_cc[VTIME] = 1;
        new_term.c_cc[VMIN] = 0;
        if (ioctl(0, TCSETS, &new_term))
            throw std::exception(); // Fail to set new term
    } else if (ioctl(0, TCSETS, &old_term))
        throw std::exception(); // Fail to set old term
}

void Term::initNCurses()
{
    curs_set(0);
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    if (has_colors() == false) {
        endwin();
        throw std::exception(); // Didn't have colors
    }
    attron(A_NORMAL);
    start_color();
    for (size_t i = 1; i < 8; i++)
        init_pair(i, i, COLOR_BLACK);
}