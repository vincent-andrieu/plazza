/*
 * EPITECH PROJECT, 2021
 * Product.hpp
 * File description:
 * implement methods of product interface
 */

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "Interfaces/ProductInterface.hpp"

template <typename Type, typename Size, typename Ingredient> class Product : public IProduct<Type, Size, Ingredient> {
  public:
    Product() = default;
    Product(const Type &type, const Size &size, double preparationTime, const std::vector<Ingredient> &ingredients);
    Product(const Product<Type, Size, Ingredient> &src);
    ~Product() = default;

    Product<Type, Size, Ingredient> &operator=(const Product<Type, Size, Ingredient> &rhs);

    [[nodiscard]] bool operator==(const IProduct<Type, Size, Ingredient> &product) const override;
    [[nodiscard]] bool operator!=(const IProduct<Type, Size, Ingredient> &product) const override;

    [[nodiscard]] Type getType() const override;
    void setType(Type type) override;

    [[nodiscard]] Size getSize() const override;
    void setSize(Size size) override;

    [[nodiscard]] double getPreparationTime() const override;
    void setPreparationTime(double preparationTime) override;

    [[nodiscard]] const std::vector<Ingredient> &getIngredients() const override;
    void setIngredients(const std::vector<Ingredient> &ingredients) override;

    [[nodiscard]] bool isFinished() const override;
    void setFinished() override;

  private:
    Type _type;
    Size _size;
    double _preparationTime{};
    std::vector<Ingredient> _ingredients;
    bool _finished = false;
};

#endif