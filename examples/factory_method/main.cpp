#include "ny_pizza_store.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    NyPizzaStore store;
    std::vector<std::string> orders = { "cheese", "pepperoni", "pineapple", "bacon", "veggie" };

    for (const auto& type : orders) {
        auto pizza = store.order_pizza(type);
        std::cout << "Ordered a pizza: " << pizza->description() << std::endl;
    }

    return 0;
}
