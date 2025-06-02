#include <string>
#include <memory>
#include <stdexcept>
#include "ny_pizza_store.hpp"
#include "chicago_pizza_store.hpp"
#include <gtest/gtest.h>

// NY Pizza Store Tests
TEST(NyPizzaStoreTest, CreatesCheesePizza) {
    NyPizzaStore store;
    auto pizza = store.order("cheese");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Thin Crust Dough"), std::string::npos);
    EXPECT_NE(pizza->description().find("Mozzarella Cheese"), std::string::npos);
}

TEST(NyPizzaStoreTest, CreatesBaconPizza) {
    NyPizzaStore store;
    auto pizza = store.order("bacon");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Bacon"), std::string::npos);
}

TEST(NyPizzaStoreTest, CreatesPepperoniPizza) {
    NyPizzaStore store;
    auto pizza = store.order("pepperoni");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Pepperoni"), std::string::npos);
}

TEST(NyPizzaStoreTest, CreatesPineapplePizza) {
    NyPizzaStore store;
    auto pizza = store.order("pineapple");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Pineapple"), std::string::npos);
}

TEST(NyPizzaStoreTest, CreatesVeggiePizza) {
    NyPizzaStore store;
    auto pizza = store.order("veggie");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Tomato"), std::string::npos);
}

TEST(NyPizzaStoreTest, UnknownPizzaThrows) {
    NyPizzaStore store;
    EXPECT_THROW({
        auto pizza = store.order("unicorn");
    }, std::out_of_range);
}

// Chicago Pizza Store Tests
TEST(ChicagoPizzaStoreTest, CreatesCheesePizza) {
    ChicagoPizzaStore store;
    auto pizza = store.order("cheese");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Thick Crust Dough"), std::string::npos);
    EXPECT_NE(pizza->description().find("Mozzarella Cheese"), std::string::npos);
}

TEST(ChicagoPizzaStoreTest, CreatesBaconPizza) {
    ChicagoPizzaStore store;
    auto pizza = store.order("bacon");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Bacon"), std::string::npos);
}

TEST(ChicagoPizzaStoreTest, CreatesPepperoniPizza) {
    ChicagoPizzaStore store;
    auto pizza = store.order("pepperoni");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Pepperoni"), std::string::npos);
}

TEST(ChicagoPizzaStoreTest, CreatesPineapplePizza) {
    ChicagoPizzaStore store;
    auto pizza = store.order("pineapple");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Pineapple"), std::string::npos);
}

TEST(ChicagoPizzaStoreTest, CreatesVeggiePizza) {
    ChicagoPizzaStore store;
    auto pizza = store.order("veggie");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Tomato"), std::string::npos);
}

TEST(ChicagoPizzaStoreTest, UnknownPizzaThrows) {
    ChicagoPizzaStore store;
    EXPECT_THROW({
        auto pizza = store.order("unicorn");
    }, std::out_of_range);
}
