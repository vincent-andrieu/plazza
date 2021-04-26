/*
 * EPITECH PROJECT, 2021
 * ConditionalVariables
 * File description:
 * ConditionalVariables.cpp - Created: 21/04/2021
 */

#include "Encapsulations/ConditionalVariables/ConditionalVariables.hpp"

template <typename T>
ConditionalVariables<T>::ConditionalVariables() : _mutex(std::make_unique<Mutex>()), _available(true), _var(0)
{
}

template <typename T>
ConditionalVariables<T>::ConditionalVariables(T var) : _mutex(std::make_unique<Mutex>()), _available(true), _var(var)
{
}

template <typename T>
ConditionalVariables<T>::ConditionalVariables(std::unique_ptr<Mutex> &&mutex, T var) : _mutex(std::move(mutex)), _available(true), _var(var)
{
}

template <typename T>
ConditionalVariables<T>::~ConditionalVariables()
{
    this->_mutex.reset();
}

template <typename T>
bool ConditionalVariables<T>::isAvailable()
{
    return this->_available;
}

template <typename T>
void ConditionalVariables<T>::wait()
{
    while (!this->_available)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

template <typename T>
T ConditionalVariables<T>::getVar()
{
    return this->_var;
}

template <typename T>
bool ConditionalVariables<T>::setVar(T var)
{
    if (this->_available) {
        this->forceSetVar(var);
        return true;
    }
    return false;
}

template <typename T>
void ConditionalVariables<T>::forceLock()
{
    if (this->_available) {
        this->_available = false;
        this->_mutex->lock();
    }
}

template <typename T>
void ConditionalVariables<T>::forceUnlock()
{
    if (!this->_available) {
        this->_mutex->unlock();
        this->_available = true;
    }
}

template <typename T>
void ConditionalVariables<T>::forceSetVar(T var)
{
    this->forceLock();
    this->_var = var;
    this->forceUnlock();
}

template class ConditionalVariables<int>;