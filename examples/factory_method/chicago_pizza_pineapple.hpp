#pragma once
#include "pizza.hpp"
#include "ingredient_creators/ingredient_creators.hpp"
#include <memory>
#include <vector>

inline std::unique_ptr<Pizza> create_chicago_pineapple_pizza() {
    ThickCrustDoughCreator dough_creator;
    PineappleCreator pineapple_creator;
    MozzarellaCheeseCreator cheese_creator;
    std::vector<std::unique_ptr<Topping>> toppings;
    toppings.push_back(pineapple_creator());
    toppings.push_back(cheese_creator());
    return std::make_unique<Pizza>(dough_creator(), std::move(toppings));
} 