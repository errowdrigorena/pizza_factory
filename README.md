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
- ✅ **Modern**: Utilizes C++17 features like `std::optional`, `std::variant`, and smart pointers

## 🏗️ Architecture

The project implements a composition-based architecture following the Open/Closed principle:

```
📦 PizzaFactory
├── 🏭 Factory Method
│   ├── PizzaStore (interface)
│   ├── NYPizzaStore
│   └── ChicagoPizzaStore
└── 🏭 Abstract Factory
    ├── IngredientFactory (interface)
    ├── NYIngredientFactory
    └── ChicagoIngredientFactory
```

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

The Factory Method pattern is demonstrated through the `PizzaStore` hierarchy, where each store implements its own way of creating pizzas:

```cpp
#include "pizza_store.hpp"
#include "ny_pizza_store.hpp"
#include "chicago_pizza_store.hpp"

int main() {
    // Create different pizza stores
    auto nyStore = std::make_unique<NYPizzaStore>();
    auto chicagoStore = std::make_unique<ChicagoPizzaStore>();

    // Each store creates pizzas in its own way
    auto nyPizza = nyStore->orderPizza("cheese");    // Creates NY style pizza
    auto chicagoPizza = chicagoStore->orderPizza("cheese");  // Creates Chicago style pizza
}
```

### Abstract Factory Pattern

The Abstract Factory pattern is shown through the `IngredientFactory` hierarchy, which creates families of related ingredients:

```cpp
#include "ingredient_factory.hpp"
#include "ny_ingredient_factory.hpp"
#include "chicago_ingredient_factory.hpp"

void demonstrateIngredientFactory() {
    // Create different ingredient factories
    auto nyFactory = std::make_unique<NYIngredientFactory>();
    auto chicagoFactory = std::make_unique<ChicagoIngredientFactory>();

    // Each factory creates a family of related ingredients
    auto nyDough = nyFactory->createDough();      // Creates thin crust
    auto nySauce = nyFactory->createSauce();      // Creates marinara sauce
    auto nyCheese = nyFactory->createCheese();    // Creates reggiano cheese

    auto chicagoDough = chicagoFactory->createDough();    // Creates thick crust
    auto chicagoSauce = chicagoFactory->createSauce();    // Creates plum tomato sauce
    auto chicagoCheese = chicagoFactory->createCheese();  // Creates mozzarella cheese
}
```

### Pattern Interaction

The two patterns work together in the following way:

1. `PizzaStore` (Factory Method) defines the interface for creating pizzas
2. Each concrete store (e.g., `NYPizzaStore`) implements its own pizza creation method
3. The stores use `IngredientFactory` (Abstract Factory) to create the ingredients
4. Each concrete factory (e.g., `NYIngredientFactory`) creates a family of related ingredients

This demonstrates how the patterns can be combined to create flexible and extensible object creation systems.

## 🧪 Testing

The project uses GoogleTest for unit testing. To run tests with coverage:

```bash
# Run tests with coverage
cd build
ctest --output-on-failure
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
```

## 🛠️ Tech Stack

- **Language**: C++17
- **Build System**: CMake 3.16+
- **Testing**: GoogleTest
- **CI/CD**: GitHub Actions
- **Code Analysis**: 
  - Clang-Tidy
  - Clang-Format
- **Coverage**: LCOV
- **Documentation**: Doxygen (coming soon)

## 📚 Implemented Design Patterns

| Pattern | Purpose | Example |
|---------|---------|---------|
| Factory Method | Create product variants | `PizzaStore::orderPizza("cheese")` |
| Abstract Factory | Compose families of related objects | `IngredientFactory::createDough()` |

## 🤝 Contributing

Contributions are welcome. Please ensure you:

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📞 Contact

If you have questions or suggestions, feel free to open an issue in the repository.

---

⭐️ If you like the project, don't forget to give it a star!

