/*
 * EPITECH PROJECT, 2021
 * Mutex
 * File description:
 * Mutex.hpp - Created: 21/04/2021
 */

#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <pthread.h>
#include "MutexInterface.hpp"

class Mutex : public Imutex
{
  public:
    Mutex();
    ~Mutex();
    void lock();
    void unlock();
    void trylock();
  private:
    pthread_mutex_t _mutex;
};

#endif