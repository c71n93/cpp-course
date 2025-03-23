#pragma once

#include <functional>
#include <map>
#include <typeindex>
#include <variant>

namespace patterns {

template <typename... Ts>
class Factory {
public:
    using creator_type = std::variant<std::function<Ts()>...>;
    explicit Factory(std::function<Ts()>... args) : map_{{typeid(Ts), creator_type(args)}...} {}

    template <typename T>
    T create() const {
        return std::get<std::function<T()>>(map_.find(typeid(T))->second)();
    }

private:
    std::unordered_map<std::type_index, std::variant<std::function<Ts()>...>> map_;
};

}  // namespace patterns
