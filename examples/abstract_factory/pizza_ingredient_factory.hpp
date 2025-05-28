#pragma once
#include "ingredients.hpp"
#include <memory>

class PizzaIngredientFactory {
public:
    virtual ~PizzaIngredientFactory() = default;
    virtual std::unique_ptr<Dough> create_dough() const = 0;
    virtual std::unique_ptr<Topping> create_topping() const = 0;
};
