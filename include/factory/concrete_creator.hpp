#pragma once
#include <memory>
#include <type_traits>
#include <utility>

template<class Base, class Derived>
class Concrete_creator {
    static_assert(std::is_base_of_v<Base, Derived>, "Derived must inherit from Base");
public:
    std::unique_ptr<Base> operator()() const {
        return std::make_unique<Derived>();
    }
};
