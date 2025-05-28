#pragma once
#include <memory>
#include <vector>
#include <string>
#include "ingredients.hpp"

// Pizza compuesta por una masa y un conjunto de toppings
class Pizza {
public:
    Pizza(std::unique_ptr<Dough> dough, std::vector<std::unique_ptr<Topping>> toppings)
        : dough_(std::move(dough)), toppings_(std::move(toppings)) {}

    [[nodiscard]] std::string description() const {
        std::string desc = dough_->description() + " dough pizza with ";
        for (const auto& topping : toppings_) {
            desc += topping->description() + ", ";
        }
        if (!toppings_.empty()) {
            desc.pop_back();
            desc.pop_back();
        }
        return desc;
    }

private:
    std::unique_ptr<Dough> dough_;
    std::vector<std::unique_ptr<Topping>> toppings_;
};
