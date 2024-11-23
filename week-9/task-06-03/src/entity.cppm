module;

#include <iostream>
#include <string>

export module entity;

//import <iostream>;
//import <string>;

namespace entity {

using namespace std::literals;

export class Entity {
public:
    Entity() : data_1_(s_data_1_), data_2_(0), data_3_(0) {}
    Entity(const int& data_1, int data_2, int data_3)
        : data_1_(data_1), data_2_(data_2), data_3_(data_3) {}
    Entity(const int& data_1, int data_2) : Entity(data_1, data_2, 0) {}

    //  ---------------------------------------------------------------------

    ~Entity() { std::clog << "Entity::~Entity\n"; }

    //  ----------------------------------------

    auto data_1() const { return data_1_; }
    auto data_2() const { return data_2_; }
    auto data_3() const { return data_3_; }

    //  ----------------------------------------

    const auto& data_as_string() const {
        if (cached_data_.is_invalid) {
            cached_data_.update(*this);
        }
        return cached_data_.string;
    }

    //  -----------------------------------------------------

    void set_data_3(int data) {
        data_3_ = data;
        cached_data_.is_invalid = true;
    }

    //  ------------------------------------

    static void test() {
        std::clog << "Entity::test : s_data_1 = " << s_data_1_ << '\n';
    }

private:
    struct CachedData {
        void update(const Entity& entity) {
            string = (std::to_string(entity.data_1_) + '/' + std::to_string(entity.data_2_) +
                      '/' + std::to_string(entity.data_3_));
            is_invalid = false;
        }

        std::string string;
        bool is_invalid = true;
    };

    //  -----------------------------------------------

    static inline auto s_data_1_ = 0;
    static const auto S_DATA_2 = 0;
    static inline const auto S_DATA_4 = "aaaaa"s;

    //  ---------------------------------------------

    const int& data_1_ = 0;
    const int data_2_ = 0;
    int data_3_ = 0;

    //  ----------------------------------

    mutable CachedData cached_data_;
};

}
