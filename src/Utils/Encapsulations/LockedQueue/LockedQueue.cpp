/*
** EPITECH PROJECT, 2021
** LockedQueue.cpp.cc
** File description:
** implementation of LockedQueue -> std::queue with a mutex and lock_guards
*/

#include "LockedQueue.hpp"

template <typename T> LockedQueue<T>::LockedQueue(const std::queue<T> &queue) : std::queue<T>(queue)
{
}

template <typename T> void LockedQueue<T>::pop(T elem)
{
    std::lock_guard<std::mutex> my_lock(_mutex);

    std::queue<T>::pop(elem);
}

template <typename T> void LockedQueue<T>::push(T elem)
{
    std::lock_guard<std::mutex> my_lock(_mutex);

    std::queue<T>::push(elem);
}

template <typename T> [[nodiscard]] bool LockedQueue<T>::empty() const
{
    return std::queue<T>::empty();
}