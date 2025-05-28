#include "chicago_ingredient_factory.hpp"
#include <iostream>
#include <string>

void describe_factory(const PizzaIngredientFactory& factory, const std::string& name) {
    std::cout << "Factory (" << name << ") produces: " << factory.create_dough()->description() << " dough and " << factory.create_topping()->description() << " topping." << std::endl;
}

int main() {
    ChicagoIngredientFactory chicago_factory;
    describe_factory(chicago_factory, "Chicago");
    return 0;
}
