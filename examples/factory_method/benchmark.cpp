#include "ny_pizza_store.hpp"
#include <iostream>
#include <chrono>
#include <vector>

int main() {
    NyPizzaStore store;
    const int iterations = 1000;
    std::vector<std::string> orders = { "cheese", "pepperoni", "pineapple", "bacon", "veggie" };

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        for (const auto& type : orders) {
            auto pizza = store.order(type);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Created " << iterations * orders.size()
              << " pizzas in " << duration.count() << " seconds.\n";

    return 0;
}
