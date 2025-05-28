#pragma once
#include "ingredients.hpp"

class ThinCrustDough : public Dough {
public:
    std::string description() const override { return "Thin Crust Dough"; }
};

class ThickCrustDough : public Dough {
public:
    std::string description() const override { return "Thick Crust Dough"; }
};

class Bacon : public Topping {
public:
    std::string description() const override { return "Crispy Bacon"; }
};

class Pineapple : public Topping {
public:
    std::string description() const override { return "Fresh Pineapple"; }
};

class Pepperoni : public Topping {
public:
    std::string description() const override { return "Spicy Pepperoni"; }
};

class Tomato : public Topping {
public:
    std::string description() const override { return "Sliced Tomato"; }
};
