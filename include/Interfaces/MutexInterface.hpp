/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * MutexInterface.hpp
 */

#ifndef MUTEX_INTERFACE_HPP
#define MUTEX_INTERFACE_HPP

class Imutex {
    public :
        virtual ~Imutex() = default;
        virtual void lock() = 0;
        virtual void unlock() = 0;
        virtual void trylock() = 0;
};

#endif