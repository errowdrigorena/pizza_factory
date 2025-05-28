#include "ny_pizza_store.hpp"
#include <gtest/gtest.h>

TEST(NyPizzaStoreTest, CreatesCheesePizza) {
    NyPizzaStore store;
    auto pizza = store.order_pizza("cheese");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Thin Crust Dough"), std::string::npos);
    EXPECT_NE(pizza->description().find("Mozzarella Cheese"), std::string::npos);
}

TEST(NyPizzaStoreTest, CreatesBaconPizza) {
    NyPizzaStore store;
    auto pizza = store.order_pizza("bacon");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Bacon"), std::string::npos);
}

TEST(NyPizzaStoreTest, CreatesPepperoniPizza) {
    NyPizzaStore store;
    auto pizza = store.order_pizza("pepperoni");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Pepperoni"), std::string::npos);
}

TEST(NyPizzaStoreTest, CreatesPineapplePizza) {
    NyPizzaStore store;
    auto pizza = store.order_pizza("pineapple");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Pineapple"), std::string::npos);
}

TEST(NyPizzaStoreTest, CreatesVeggiePizza) {
    NyPizzaStore store;
    auto pizza = store.order_pizza("veggie");
    ASSERT_NE(pizza, nullptr);
    EXPECT_NE(pizza->description().find("Tomato"), std::string::npos);
}


TEST(NyPizzaStoreTest, UnknownPizzaThrows) {
    NyPizzaStore store;
    EXPECT_THROW({
        auto pizza = store.order_pizza("unicorn");
    }, std::runtime_error);
}
