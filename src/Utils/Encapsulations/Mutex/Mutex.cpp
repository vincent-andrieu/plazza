/*
 * EPITECH PROJECT, 2021
 * Mutex
 * File description:
 * Mutex.cpp - Created: 21/04/2021
 */

#include "Encapsulations/Mutex/Mutex.hpp"

Mutex::Mutex()
{
    this->_mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_init(&this->_mutex, NULL);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&this->_mutex);
}

void Mutex::lock()
{
    pthread_mutex_lock(&this->_mutex);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&this->_mutex);
}

void Mutex::trylock()
{
    pthread_mutex_trylock(&this->_mutex);
}