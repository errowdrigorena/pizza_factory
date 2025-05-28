# 🍕 Pizza Factory - Modern Design Patterns Implementation in C++17

![Coverage](https://raw.githubusercontent.com/errowdrigorena/pizza_factory/main/badges/coverage.svg)
[![Build](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/errowdrigorena/pizza_factory/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/std/the-standard)
[![CMake](https://img.shields.io/badge/CMake-3.16%2B-brightgreen)](https://cmake.org/)

## 📋 Overview

This project demonstrates a modern and professional implementation of the **Factory Method** and **Abstract Factory** design patterns using C++17. The code follows industry best practices and is designed to be:

- ✅ **Extensible**: Add new pizza types, ingredients, or doughs without modifying existing code
- ✅ **Maintainable**: Clean, well-documented code following modern style guides
- ✅ **Testable**: Complete test coverage with GoogleTest
- ✅ **Modern**: Utilizes C++17 features like smart pointers and move semantics

## 🏗️ Architecture

The project implements a composition-based architecture following the Open/Closed principle:

```
📦 PizzaFactory
├── 🏭 Factory Method
│   ├── PizzaStore (interface)
│   │   ├── order(type: string) -> unique_ptr<Pizza>
│   ├── NYPizzaStore
│   │   ├── Thin crust dough
│   │   ├── Marinara sauce
│   │   └── Reggiano cheese
│   └── ChicagoPizzaStore
│       ├── Thick crust dough
│       ├── Plum tomato sauce
│       └── Mozzarella cheese
└── 🏭 Abstract Factory
    ├── IngredientFactory (interface)
    └── ChicagoIngredientFactory
        ├── createDough() -> ThickCrustDough
        ├── createSauce() -> PlumTomatoSauce
        └── createCheese() -> MozzarellaCheese
```

## 📖 Implementation Details

### Factory Method Pattern

The Factory Method pattern is implemented through two concrete pizza stores:

#### NYPizzaStore
- Uses thin crust dough for a crispy texture
- Implements NY-style pizza creation with specific ingredients
- Available pizzas: cheese, pepperoni, pineapple, bacon, and veggie

#### ChicagoPizzaStore
- Uses thick crust dough for a deep-dish style
- Implements Chicago-style pizza creation with specific ingredients
- Available pizzas: cheese, pepperoni, pineapple, bacon, and veggie
- Each pizza is created with Chicago-style ingredients (thick crust, mozzarella cheese, etc.)

### Abstract Factory Pattern

The Abstract Factory pattern is implemented through the ingredient factory system:

#### ChicagoIngredientFactory
- Creates a family of Chicago-style ingredients
- Produces thick crust dough, plum tomato sauce, and mozzarella cheese
- Each ingredient is created with specific Chicago-style characteristics

## 🚀 Getting Started

### Prerequisites

- C++17 compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.16 or higher
- Git

### Installation

```bash
# Clone the repository
git clone https://github.com/errowdrigorena/pizza_factory.git
cd pizza_factory

# Configure and build
cmake -B build
cmake --build build

# Run tests
ctest --test-dir build --output-on-failure
```

## 📖 Usage Examples

### Factory Method Pattern

The Factory Method pattern is demonstrated through the `PizzaStore` hierarchy. Here's a complete example showing how to use both stores:

```cpp
#include "ny_pizza_store.hpp"
#include "chicago_pizza_store.hpp"
#include <iostream>
#include <vector>

int main() {
    // Create both pizza stores
    NyPizzaStore nyStore;
    ChicagoPizzaStore chicagoStore;

    // List of pizza types to order
    std::vector<std::string> orders = { 
        "cheese", "pepperoni", "pineapple", "bacon", "veggie" 
    };

    // Order from NY store
    std::cout << "Ordering from NY store:\n";
    for (const auto& type : orders) {
        auto pizza = nyStore.order(type);
        std::cout << "Ordered a " << type << " pizza: " 
                  << pizza->description() << std::endl;
    }

    // Order from Chicago store
    std::cout << "\nOrdering from Chicago store:\n";
    for (const auto& type : orders) {
        auto pizza = chicagoStore.order(type);
        std::cout << "Ordered a " << type << " pizza: " 
                  << pizza->description() << std::endl;
    }
}
```

#### Expected Output
```
Ordering from NY store:
Ordered a cheese pizza: Thin Crust Dough dough pizza with Mozzarella Cheese
Ordered a pepperoni pizza: Thin Crust Dough dough pizza with Spicy Pepperoni, Mozzarella Cheese
Ordered a pineapple pizza: Thin Crust Dough dough pizza with Fresh Pineapple, Mozzarella Cheese
Ordered a bacon pizza: Thin Crust Dough dough pizza with Crispy Bacon, Mozzarella Cheese
Ordered a veggie pizza: Thin Crust Dough dough pizza with Sliced Tomato, Mozzarella Cheese

Ordering from Chicago store:
Ordered a cheese pizza: Thick Crust Dough dough pizza with Mozzarella Cheese
Ordered a pepperoni pizza: Thick Crust Dough dough pizza with Spicy Pepperoni, Mozzarella Chees
e
Ordered a pineapple pizza: Thick Crust Dough dough pizza with Fresh Pineapple, Mozzarella Chees
e
Ordered a bacon pizza: Thick Crust Dough dough pizza with Crispy Bacon, Mozzarella Cheese
Ordered a veggie pizza: Thick Crust Dough dough pizza with Sliced Tomato, Mozzarella Cheese
```

### Abstract Factory Pattern

The Abstract Factory pattern is demonstrated through the ingredient factory system:

```cpp
#include "chicago_ingredient_factory.hpp"
#include <iostream>

void demonstrateIngredientFactory() {
    ChicagoIngredientFactory factory;

    // Create a family of Chicago-style ingredients
    auto dough = factory.createDough();      // Creates thick crust
    auto pepperoni = factory.createPepperoni(); // Creates spicy pepperoni

    std::cout << "Factory (Chicago) produces: " << dough->description() 
              << " dough and " << pepperoni->description() << " topping." << std::endl;
}
```

#### Expected Output
```
Factory (Chicago) produces: Thick Crust Dough dough and Spicy Pepperoni topping.
```

### Running the Examples

To run the examples and see the results:

```bash
# Run Factory Method example
./build/examples/factory_method/factory_method_main
# This will show pizzas from both NY and Chicago stores with their specific ingredients

# Run Abstract Factory example
./build/examples/abstract_factory/abstract_factory_main
# This will demonstrate the creation of Chicago-style ingredients
```

Each example demonstrates different aspects of the design patterns:
- The Factory Method example shows how different stores create pizzas with their own styles
- The Abstract Factory example shows how to create families of related ingredients

## 🧪 Testing

The project uses GoogleTest for unit testing. Tests cover both the Factory Method and Abstract Factory implementations:

```bash
# Run all tests
cd build
ctest --output-on-failure

# Run tests with coverage
make coverage
```

The test suite includes:
- Factory Method tests for both NY and Chicago pizza stores
- Abstract Factory tests for ingredient creation
- Edge cases and error handling

## 🛠️ Tech Stack

- **Language**: C++17
- **Build System**: CMake 3.16+
- **Testing**: GoogleTest
- **CI/CD**: GitHub Actions
- **Code Analysis**: 
  - Clang-Tidy
  - Clang-Format
- **Coverage**: LCOV

## 📚 Implemented Design Patterns

| Pattern | Purpose | Example |
|---------|---------|---------|
| Factory Method | Create pizza variants | `PizzaStore::order("cheese")` |
| Abstract Factory | Create ingredient families | `IngredientFactory::createDough()` |

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📞 Contact

If you have questions or suggestions, feel free to open an issue in the repository.

---

⭐️ If you like the project, don't forget to give it a star!

