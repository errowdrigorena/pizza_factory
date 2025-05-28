#pragma once
#include <string>

class Dough {
public:
    virtual ~Dough() = default;
    virtual std::string description() const = 0;
};

class Topping {
public:
    virtual ~Topping() = default;
    virtual std::string description() const = 0;
};
