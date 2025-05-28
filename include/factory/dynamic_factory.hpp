#pragma once
#include <unordered_map>
#include <memory>
#include <functional>
#include <stdexcept>

template<class AbstractProduct, typename IdentifierType>
class Dynamic_factory {
public:
    using Creator = std::function<std::unique_ptr<AbstractProduct>()>;

    void add_creator(const IdentifierType& id, Creator creator) {
        creators_[id] = std::move(creator);
    }

    std::unique_ptr<AbstractProduct> make(const IdentifierType& id) const {
        auto it = creators_.find(id);
        if (it != creators_.end()) {
            return it->second();
        }
        throw std::runtime_error("Unknown identifier");
    }

private:
    std::unordered_map<IdentifierType, Creator> creators_;
};
