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
    virtual void setType(Type type) = 0;

    [[nodiscard]] virtual Size getSize() const = 0;
    virtual void setSize(Size size) = 0;

    [[nodiscard]] virtual double getPreparationTime() const = 0;
    virtual void setPreparationTime(double preparationTime) = 0;

    [[nodiscard]] virtual const std::vector<IngredientType> &getIngredients() const = 0;
    virtual void setIngredients(const std::vector<IngredientType> &ingredients) = 0;

    [[nodiscard]] virtual bool isFinished() const = 0;
    virtual void setFinished() = 0;
};

#endif