#pragma once
#include "ingredients/concrete_ingredients.hpp"
#include "factory/concrete_creator.hpp"

// Dough creators
using ThinCrustDoughCreator = Concrete_creator<Dough, ThinCrustDough>;
using ThickCrustDoughCreator = Concrete_creator<Dough, ThickCrustDough>;

// Topping creators
using MozzarellaCheeseCreator = Concrete_creator<Topping, MozzarellaCheese>;
using PepperoniCreator = Concrete_creator<Topping, Pepperoni>;
using PineappleCreator = Concrete_creator<Topping, Pineapple>;
using BaconCreator = Concrete_creator<Topping, Bacon>;
using TomatoCreator = Concrete_creator<Topping, Tomato>;
