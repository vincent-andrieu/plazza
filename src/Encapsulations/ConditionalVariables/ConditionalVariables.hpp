/*
 * EPITECH PROJECT, 2021
 * ConditionalVariables
 * File description:
 * ConditionalVariables.hpp - Created: 21/04/2021
 */

#ifndef CONDITIONAL_VARIABLE_HPP
#define CONDITIONAL_VARIABLE_HPP

#include <memory>
#include <thread>
#include "Encapsulations/Mutex/Mutex.hpp"

template <typename T> class ConditionalVariables {
  public:
    ConditionalVariables();
    ConditionalVariables(T var);
    ConditionalVariables(std::unique_ptr<Mutex> &&mutex, T var);
    ~ConditionalVariables();
    bool isAvailable();
    void wait();
    T getVar();
    void setVar(T var);
    void force_lock();
    void force_unlock();

  private:
    std::unique_ptr<Mutex> _mutex;
    bool _available;
    T _var;
};

#endif