#include <abstract_factory/chicago_ingredient_factory.hpp>
#include <abstract_factory/ny_ingredient_factory.hpp>
#include <gtest/gtest.h>

TEST(ChicagoIngredientFactoryTest, ProducesCorrectDescriptions) {
    ChicagoIngredientFactory factory;
    EXPECT_EQ(factory.create_dough()->description(), "Thick Crust Dough");
    EXPECT_EQ(factory.create_topping()->description(), "Spicy Pepperoni");
}

TEST(NewYorkIngredientFactoryTest, ProducesCorrectDescriptions) {
    NyIngredientFactory factory;
    EXPECT_EQ(factory.create_dough()->description(), "Thin Crust Dough");
    EXPECT_EQ(factory.create_topping()->description(), "Crispy Bacon");
}
