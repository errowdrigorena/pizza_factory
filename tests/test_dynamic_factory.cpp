#include <gtest/gtest.h>
#include <factory/dynamic_factory.hpp>
#include "pizza.hpp"
#include "ny_pizza_cheese.hpp"

TEST(DynamicFactoryTest, RegisterAndUnregister) {
    Dynamic_factory<Pizza, std::string> factory;
    EXPECT_TRUE(factory.is_empty());

    factory.register_creator("cheese", &create_ny_cheese_pizza);
    EXPECT_FALSE(factory.is_empty());

    EXPECT_TRUE(factory.unregister_creator("cheese"));
    EXPECT_TRUE(factory.is_empty());
}
