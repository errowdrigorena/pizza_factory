#pragma once
#include "ingredient_creators/ingredient_creators.hpp"
#include "pizza.hpp"
#include <memory>
#include <utility>
#include <vector>

inline auto create_chicago_bacon_pizza() -> std::unique_ptr<Pizza> {
    ThickCrustDoughCreator dough_creator;
    BaconCreator bacon_creator;
    MozzarellaCheeseCreator cheese_creator;
    std::vector<std::unique_ptr<Topping>> toppings;
    toppings.push_back(bacon_creator.create());
    toppings.push_back(cheese_creator.create());
    return std::make_unique<Pizza>(dough_creator.create(), std::move(toppings));
}
