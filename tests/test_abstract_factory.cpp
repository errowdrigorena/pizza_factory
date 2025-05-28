#include "ny_ingredient_factory.hpp"
#include "chicago_ingredient_factory.hpp"
#include <gtest/gtest.h>

TEST(NyIngredientFactoryTest, ProducesCorrectDescriptions) {
    NyIngredientFactory factory;
    EXPECT_EQ(factory.create_dough()->description(), "Thin Crust Dough");
    EXPECT_EQ(factory.create_topping()->description(), "Crispy Bacon");
}

TEST(ChicagoIngredientFactoryTest, ProducesCorrectDescriptions) {
    ChicagoIngredientFactory factory;
    EXPECT_EQ(factory.create_dough()->description(), "Thick Crust Dough");
    EXPECT_EQ(factory.create_topping()->description(), "Spicy Pepperoni");
}


#include "ingredient_factory_registry.hpp"

TEST(IngredientFactoryRegistry, UnknownFactoryThrows) {
    Ingredient_factory_registry<PizzaIngredientFactory> registry;
    EXPECT_THROW({
        auto factory = registry.get("mars_style");
    }, std::runtime_error);
}
