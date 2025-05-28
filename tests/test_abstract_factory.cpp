#include "chicago_ingredient_factory.hpp"
#include <gtest/gtest.h>

TEST(ChicagoIngredientFactoryTest, ProducesCorrectDescriptions) {
    ChicagoIngredientFactory factory;
    EXPECT_EQ(factory.create_dough()->description(), "Thick Crust Dough");
    EXPECT_EQ(factory.create_topping()->description(), "Spicy Pepperoni");
}
