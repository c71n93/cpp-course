#pragma once

#include <iostream>
#include <string>

namespace entity {

using namespace std::literals;

class Entity {
public:
    Entity();
    Entity(const int& data_1, int data_2, int data_3);
    Entity(const int& data_1, int data_2);
    ~Entity();

    int data_1() const;
    int data_2() const;
    int data_3() const;

    const std::string& data_as_string() const;

    void set_data_3(int data);

    static void test();

private:
    struct CachedData {
        void update(const Entity& entity);

        std::string string;
        bool is_invalid = true;
    };

    static inline auto s_data_1_ = 0;
    static const int S_DATA_2;
    static inline const auto S_DATA_4 = "aaaaa"s;

    const int& data_1_;
    const int data_2_;
    int data_3_;

    mutable CachedData cached_data_;
};

}  // namespace entity
