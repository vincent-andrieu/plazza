/*
** EPITECH PROJECT, 2021
** LockedQueue.hpp.h
** File description:
** std::queue with a mutex and lock_guards
*/
#ifndef PLAZZA_LOCKEDQUEUE_HPP
#define PLAZZA_LOCKEDQUEUE_HPP

#include <queue>
#include <mutex>

template <typename T> class LockedQueue : public std::queue<T> {
  public:
    LockedQueue() = default;
    explicit LockedQueue(const std::queue<T> &queue) : std::queue<T>(queue){};
    ~LockedQueue() = default;

    void pop()
    {
        std::lock_guard<std::mutex> my_lock(_mutex);
        std::queue<T>::pop();
    };
    void push(const T &elem)
    {
        std::lock_guard<std::mutex> my_lock(_mutex);
        std::queue<T>::push(elem);
    };
    const T &getFront()
    {
        std::lock_guard<std::mutex> my_lock(_mutex);
        const T &my_elem(std::queue<T>::front());

        std::queue<T>::pop();
        return my_elem;
    };
    const T &front()
    {
        std::lock_guard<std::mutex> my_lock(_mutex);
        return std::queue<T>::front();
    };
    const T &back()
    {
        std::lock_guard<std::mutex> my_lock(_mutex);
        return std::queue<T>::back();
    };
    [[nodiscard]] bool empty() const
    {
        return std::queue<T>::empty();
    };

  private:
    std::mutex _mutex;
};

#endif // PLAZZA_LOCKEDQUEUE_HPP