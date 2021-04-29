/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-aurelien.joncour
** File description:
** Vector.cpp.c
*/

#include <cmath>
#include "Vector.hpp"

using namespace plazza;

Vector::Vector()
{
}

Vector::Vector(double ix, double iy) : x(ix), y(iy)
{
}

Vector::Vector(Vector const &v) : x(v.x), y(v.y)
{
}

Vector &Vector::ceil()
{
    this->x = std::ceil(this->x);
    this->y = std::ceil(this->y);

    return *this;
}

Vector &Vector::round()
{
    this->x = std::round(this->x);
    this->y = std::round(this->y);

    return *this;
}

Vector &Vector::floor()
{
    this->x = std::floor(this->x);
    this->y = std::floor(this->y);

    return *this;
}

Vector Vector::operator+(Vector const &v)
{
    return Vector(this->x + v.x, this->y + v.y);
}

Vector Vector::operator-(Vector const &v)
{
    return Vector(this->x - v.x, this->y - v.y);
}

Vector &Vector::operator=(Vector const &v)
{
    this->x = v.x;
    this->y = v.y;
    return *this;
}

bool Vector::operator==(Vector const &v) const
{
    return this->x == v.x && this->y == v.y;
}

bool Vector::operator!=(Vector const &v) const
{
    return this->x != v.x || this->y != v.y;
}