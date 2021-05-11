/*
 * EPITECH PROJECT, 2021
 * Product.hpp
 * File description:
 * implement methods of product interface
 */

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Interfaces/ProductInterface.hpp"

template <typename Type, typename Size, typename IngredientType> class Product : public IProduct<Type, Size, IngredientType> {
  public:
    Product() = default;
    Product(const Product<Type, Size, IngredientType> &src);
    ~Product() = default;

    Product<Type, Size, IngredientType> &operator=(const Product<Type, Size, IngredientType> &rhs);

    [[nodiscard]] bool operator==(const IProduct<Type, Size, IngredientType> &product) const override;
    [[nodiscard]] bool operator!=(const IProduct<Type, Size, IngredientType> &product) const override;

    [[nodiscard]] Type getType() const override;
    void setType(Type type) override;

    [[nodiscard]] Size getSize() const override;
    void setSize(Size size) override;

    [[nodiscard]] double getPreparationTime() const override;
    void setPreparationTime(double preparationTime) override;

    [[nodiscard]] const std::vector<IngredientType> &getIngredients() const override;
    void setIngredients(const std::vector<IngredientType> &ingredients) override;

    [[nodiscard]] bool isFinished() const override;
    void setFinished() override;

  private:
    Type _type;
    Size _size;
    double _preparationTime{};
    std::vector<IngredientType> _ingredients;
    bool _finished = false;
};

#endif