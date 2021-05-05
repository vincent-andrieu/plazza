/*
 * EPITECH PROJECT, 2021
 * AProduct.hpp
 * File description:
 * implement methods of product interface
 */

#ifndef A_PRODUCT_HPP
#define A_PRODUCT_HPP

#include <vector>
#include "Interfaces/ProductInterface.hpp"

template <typename Type, typename Size, typename IngredientType> class AProduct : public IProduct<Type, Size, IngredientType> {
  public:
    ~AProduct() = default;

    [[nodiscard]] bool operator==(const IProduct<Type, Size, IngredientType> &product) const override;
    [[nodiscard]] bool operator!=(const IProduct<Type, Size, IngredientType> &product) const override;

    [[nodiscard]] Type getType() const override;
    void setType(Type type) override;

    [[nodiscard]] Size getSize() const override;
    void setSize(Size size) override;

    [[nodiscard]] size_t getPreparationTime() const override;
    void setPreparationTime(size_t preparationTime) override;

    [[nodiscard]] const std::vector<IngredientType> &getIngredients() const override;
    void setIngredients(const std::vector<IngredientType> &ingredients) override;

    [[nodiscard]] bool isFinished() override;
    void setFinished() override;

  private:
    Type _type;
    Size _size;
    size_t _preparationTime{};
    std::vector<IngredientType> _ingredients;
    bool _finished = false;
};

#endif