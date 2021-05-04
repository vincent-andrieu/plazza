/*
 * EPITECH PROJECT, 2021
 * Interfaces
 * File description:
 * CookInterface.hpp - Created: 26/04/2021
 */

#ifndef COOK_INTERFACE_HPP
#define COOK_INTERFACE_HPP

#include <queue>
#include "Product/Pizza/Pizza.hpp"

template <typename ProductType, typename ProductSize, typename ProductIngredientType> class ICook {
  public:
    virtual ~ICook() = default;
    /**
     * @brief Check if the cook is cooking
     * @return True if cooking, false otherwise
     */
    virtual [[nodiscard]] bool isCooking() = 0;

    virtual void cook(ProductType type, ProductSize size, std::vector<ProductIngredientType> ingredients) = 0;
    /**
     * @brief check if has finished cooking
     * @throw If not cooking or finished cooking
     * @return True if finished cooking, false otherwise
     */
    virtual [[nodiscard]] bool hasFinishedCooking() = 0;

    /**
     * @brief Retrieve cooked product
     * @throw If nothing cooked
     * @return Cooked product
     */
    virtual IProduct<ProductType, ProductSize, ProductIngredientType> getCookedProduct() const = 0;
};

#endif