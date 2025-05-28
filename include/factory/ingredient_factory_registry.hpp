#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <functional>
#include <stdexcept>

template<typename Factory>
class Ingredient_factory_registry {
public:
    using Creator = std::function<std::unique_ptr<Factory>()>;

    void register_factory(const std::string& name, Creator creator) {
        factories_[name] = std::move(creator);
    }

    std::unique_ptr<Factory> get(const std::string& name) const {
        auto it = factories_.find(name);
        if (it != factories_.end()) return it->second();
        throw std::runtime_error("Unknown factory: " + name);
    }

private:
    std::unordered_map<std::string, Creator> factories_;
};
