/*
 * EPITECH PROJECT, 2021
 * interfaces
 * File description:
 * ProductInterface.hpp
 */

#ifndef PRODUCT_INTERFACE_HPP
#define PRODUCT_INTERFACE_HPP

#include <vector>

template <typename Type, typename Size, typename IngredientType> class IProduct {
  public:
    virtual ~IProduct() = default;

    [[nodiscard]] virtual bool operator==(const IProduct &product) const = 0;
    [[nodiscard]] virtual bool operator!=(const IProduct &product) const = 0;

    [[nodiscard]] virtual Type getType() const = 0;
    [[nodiscard]] virtual Size getSize() const = 0;
    [[nodiscard]] virtual size_t getPreparationTime() const = 0;
    [[nodiscard]] virtual const std::vector<IngredientType> &getIngredientList() const = 0;
};

#endif