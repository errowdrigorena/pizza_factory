#include "ny_pizza_store.hpp"
#include "chicago_pizza_store.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    // Create both pizza stores
    NyPizzaStore nyStore;
    ChicagoPizzaStore chicagoStore;

    // List of pizza types to order
    std::vector<std::string> orders = { "cheese", "pepperoni", "pineapple", "bacon", "veggie" };

    // Order from NY store
    std::cout << "Ordering from NY store:\n";
    for (const auto& type : orders) {
        auto pizza = nyStore.order(type);
        std::cout << "Ordered a " << type << " pizza: " << pizza->description() << std::endl;
    }

    // Order from Chicago store
    std::cout << "\nOrdering from Chicago store:\n";
    for (const auto& type : orders) {
        auto pizza = chicagoStore.order(type);
        std::cout << "Ordered a " << type << " pizza: " << pizza->description() << std::endl;
    }

    return 0;
}
