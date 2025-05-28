#include "ny_ingredient_factory.hpp"
#include "chicago_ingredient_factory.hpp"
#include <iostream>

void describe_factory(const PizzaIngredientFactory& factory, const std::string& name) {
    std::cout << name << " Factory produces:\n";
    std::cout << "- Dough: " << factory.create_dough()->description() << "\n";
    std::cout << "- Topping: " << factory.create_topping()->description() << "\n\n";
}

int main() {
    NyIngredientFactory ny_factory;
    ChicagoIngredientFactory chicago_factory;

    describe_factory(ny_factory, "NY");
    describe_factory(chicago_factory, "Chicago");

    return 0;
}
