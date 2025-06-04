#pragma once
#include "pizza.hpp"
#include "ingredient_creators/ingredient_creators.hpp"
#include <memory>
#include <vector>
#include <utility>

inline auto create_ny_pineapple_pizza() -> std::unique_ptr<Pizza> {
    ThinCrustDoughCreator dough_creator;
    PineappleCreator pineapple_creator;
    MozzarellaCheeseCreator cheese_creator;
    std::vector<std::unique_ptr<Topping>> toppings;
    toppings.push_back(pineapple_creator.create());
    toppings.push_back(cheese_creator.create());
    return std::make_unique<Pizza>(dough_creator.create(), std::move(toppings));
}
