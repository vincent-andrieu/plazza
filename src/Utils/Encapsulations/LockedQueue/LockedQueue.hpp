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
    explicit LockedQueue(const std::queue<T> &queue);
    ~LockedQueue() = default;

    void pop(T elem) override;
    void push(T elem) override;
    [[nodiscard]] bool empty() const override;

  private:
    std::mutex _mutex;
};

#endif // PLAZZA_LOCKEDQUEUE_HPP