#pragma once

#include <memory>
#include <type_traits>
#include <utility>

// Concrete_creator
//
// This is a reusable utility for implementing the Factory Method 
// or Abstract Factory patterns.
//
// It provides a type-safe way to construct a concrete Derived class and return it
// as a std::unique_ptr<Base>. It forwards constructor arguments perfectly,
// checks the inheritance relationship at compile time, and ensures compile-time
// validation of the constructor arguments.
//
// Template parameters:
//   - Base:    The base class (interface or abstract).
//   - Derived: The concrete implementation.
//   - Args...: The constructor parameters expected by Derived.
//
// Suggested usage:
//
//   template<typename Derived, typename... Args>
//   using MyBaseCreator = Concrete_creator<MyBase, Derived, Args...>;
//
//   using FooCreator = MyBaseCreator<Foo>;                     // if Foo()
//   using BarCreator = MyBaseCreator<Bar, int, std::string>;  // if Bar(int, std::string)
//
//   FooCreator fooFactory;
//   auto foo = fooFactory.Create(); // returns std::unique_ptr<MyBase>
//
//   BarCreator barFactory;
//   auto bar = barFactory.Create(42, "example"); // same as make_unique<Bar>(42, "example")
//
template<class Base, class Derived, typename... Args>
class Concrete_creator
{
    static_assert(std::is_base_of_v<Base, Derived>,
                  "Concrete_creator: Derived must inherit from Base");

public:
    Concrete_creator() = default;

    [[nodiscard]]
    std::unique_ptr<Base> create(Args&&... args) const
        noexcept(std::is_nothrow_constructible_v<Derived, Args&&...>)
    {
        static_assert(std::is_constructible_v<Derived, Args&&...>,
                      "Concrete_creator: Arguments cannot construct Derived");

        return std::make_unique<Derived>(std::forward<Args>(args)...);
    }
};
