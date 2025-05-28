#pragma once
#include "pizza_ingredient_factory.hpp"
#include "ingredients/concrete_ingredients.hpp"
#include "factory/concrete_creator.hpp"

class NyIngredientFactory final : public PizzaIngredientFactory {
public:
    std::unique_ptr<Dough> create_dough() const override {
        return dough_creator_();
    }

    std::unique_ptr<Topping> create_topping() const override {
        return topping_creator_();
    }

private:
    Concrete_creator<Dough, ThinCrustDough> dough_creator_;
    Concrete_creator<Topping, Bacon> topping_creator_;
};
