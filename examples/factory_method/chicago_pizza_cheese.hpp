#pragma once
#include "pizza.hpp"
#include "ingredient_creators/ingredient_creators.hpp"
#include <memory>
#include <vector>
#include <utility>

inline auto create_chicago_cheese_pizza() -> std::unique_ptr<Pizza> {
    ThickCrustDoughCreator dough_creator;
    MozzarellaCheeseCreator cheese_creator;
    std::vector<std::unique_ptr<Topping>> toppings;
    toppings.push_back(cheese_creator.Create());
    return std::make_unique<Pizza>(dough_creator.Create(), std::move(toppings));
}