#pragma once
#include "pizza.hpp"
#include "ingredient_creators/ingredient_creators.hpp"
#include <memory>
#include <vector>

inline std::unique_ptr<Pizza> create_ny_pepperoni_pizza() {
    ThinCrustDoughCreator dough_creator;
    PepperoniCreator pepperoni_creator;
    MozzarellaCheeseCreator cheese_creator;
    std::vector<std::unique_ptr<Topping>> toppings;
    toppings.push_back(pepperoni_creator());
    toppings.push_back(cheese_creator());
    return std::make_unique<Pizza>(dough_creator(), std::move(toppings));
}
