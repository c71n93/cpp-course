#include "entity.hpp"

namespace entity {

const int Entity::S_DATA_2 = 0;

Entity::Entity() : data_1_(s_data_1), data_2_(0), data_3_(0) {}
Entity::Entity(const int& data_1, int data_2, int data_3)
    : data_1_(data_1), data_2_(data_2), data_3_(data_3) {}
Entity::Entity(const int& data_1, int data_2) : Entity(data_1, data_2, 0) {}
Entity::~Entity() { std::clog << "Entity::~Entity\n"; }
int Entity::data_1() const { return data_1_; }
int Entity::data_2() const { return data_2_; }
int Entity::data_3() const { return data_3_; }
const std::string& Entity::data_as_string() const {
    if (cached_data_.is_invalid) {
        cached_data_.update(*this);
    }
    return cached_data_.string;
}
void Entity::set_data_3(int data) {
    data_3_ = data;
    cached_data_.is_invalid = true;
}
void Entity::test() { std::clog << "Entity::test : s_data_1 = " << s_data_1 << '\n'; }

void Entity::CachedData::update(const Entity& entity) {
    string = (std::to_string(entity.data_1_) + '/' + std::to_string(entity.data_2_) + '/' +
              std::to_string(entity.data_3_));
    is_invalid = false;
}

}  // namespace entity
