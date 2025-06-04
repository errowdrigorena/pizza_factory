#pragma once

#include <unordered_map>
#include <memory>
#include <functional>
#include <type_traits>
#include <stdexcept>

// Dynamic_factory is a generic dynamic factory for runtime object creation.
// You register creators (functions or lambdas) identified by a key (typically an enum or string),
// and later use that key to create instances of derived classes from a common base.
//
// Template parameters:
//   - AbstractProduct:  The base class shared by all concrete products.
//   - IdentifierType:   The key type used to register creators (e.g., enum or string).
//   - ProductCreator:   Callable returning `std::unique_ptr<AbstractProduct>`; defaults
//                       to `std::function<std::unique_ptr<AbstractProduct>()>`.
template
<
    class AbstractProduct,
    typename IdentifierType,
    typename ProductCreator = std::function<std::unique_ptr<AbstractProduct>()>
>
class Dynamic_factory
{
public:
    void register_creator(const IdentifierType& id, ProductCreator creator)
    {
        associations_[id] = std::move(creator);
    }

    bool unregister_creator(const IdentifierType& id)
    {
        return associations_.erase(id) == 1;
    }

    // Creates an object using the creator associated with the identifier.
    // Arguments are perfectly forwarded to the creator function.
    // Throws std::out_of_range if the identifier is not found.
    template<typename... Args>
    [[nodiscard]] std::invoke_result_t<ProductCreator, Args...>
    make(const IdentifierType& id, Args&&... args) const
    {
        auto it = associations_.find(id);
        if (it == associations_.end())
        {
            throw std::out_of_range("Dynamic_factory: identifier not registered.");
        }
        return it->second(std::forward<Args>(args)...);
    }

    // Returns true if no creators are registered.
    [[nodiscard]] bool is_empty() const
    {
        return associations_.empty();
    }

private:
    using CreatorContainer = std::unordered_map<IdentifierType, ProductCreator>;
    CreatorContainer associations_;
};
