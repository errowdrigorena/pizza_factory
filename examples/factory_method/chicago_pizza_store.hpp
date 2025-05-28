#pragma once

#include "pizza.hpp"
#include "factory/dynamic_factory.hpp"
#include "chicago_pizza_cheese.hpp"
#include "chicago_pizza_bacon.hpp"
#include "chicago_pizza_pepperoni.hpp"
#include "chicago_pizza_pineapple.hpp"
#include "chicago_pizza_veggie.hpp"

class ChicagoPizzaStore {
public:
    ChicagoPizzaStore() {
        pizza_factory_.add_creator("cheese", &create_chicago_cheese_pizza);
        pizza_factory_.add_creator("bacon", &create_chicago_bacon_pizza);
        pizza_factory_.add_creator("pepperoni", &create_chicago_pepperoni_pizza);
        pizza_factory_.add_creator("pineapple", &create_chicago_pineapple_pizza);
        pizza_factory_.add_creator("veggie", &create_chicago_veggie_pizza);
    }

    [[nodiscard]]
    std::unique_ptr<Pizza> order(const std::string& type) const {
        return pizza_factory_.make(type);
    }

private:
    Dynamic_factory<Pizza, std::string> pizza_factory_;
}; 