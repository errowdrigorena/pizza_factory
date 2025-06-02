#pragma once

#include "pizza.hpp"
#include "factory/dynamic_factory.hpp"
#include "ny_pizza_cheese.hpp"
#include "ny_pizza_bacon.hpp"
#include "ny_pizza_pepperoni.hpp"
#include "ny_pizza_pineapple.hpp"
#include "ny_pizza_veggie.hpp"

class NyPizzaStore {
public:
    NyPizzaStore() {
        pizza_factory_.register_creator("cheese", &create_ny_cheese_pizza);
        pizza_factory_.register_creator("bacon", &create_ny_bacon_pizza);
        pizza_factory_.register_creator("pepperoni", &create_ny_pepperoni_pizza);
        pizza_factory_.register_creator("pineapple", &create_ny_pineapple_pizza);
        pizza_factory_.register_creator("veggie", &create_ny_veggie_pizza);
    }

    [[nodiscard]]
    std::unique_ptr<Pizza> order(const std::string& type) const {
        return pizza_factory_.make(type);
    }

private:
    Dynamic_factory<Pizza, std::string> pizza_factory_;
};
