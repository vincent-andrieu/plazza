/*
** EPITECH PROJECT, 2021
** include
** File description:
** Coord_t.hpp.h
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

namespace plazza
{
    class Vector {
      public:
        Vector();
        Vector(double ix, double iy);
        Vector(Vector const &v);
        ~Vector() = default;

        Vector &ceil();
        Vector &round();
        Vector &floor();

        bool operator==(Vector const &v) const;
        bool operator!=(Vector const &v) const;

        Vector &operator=(Vector const &v);
        Vector operator+(Vector const &v);
        Vector operator-(Vector const &v);

        double x;
        double y;
    };
} // namespace plazza

#endif // VECTOR_HPP_
