#include <cassert>

#include "entity.hpp"

using entity::Entity;

int main() {
    Entity entity_1;

    //	entity_1.data_3_ = 1; // error

    entity_1.set_data_3(1);

    assert(entity_1.data_3() == 1);

    assert(entity_1.data_as_string() == "0/0/1");

    //  ---------------------------------------------

    const Entity entity_2;

    //  entity_2.set_data_3(1); // error

    assert(entity_2.data_3() == 0);

    assert(entity_2.data_as_string() == "0/0/0");

    //  ---------------------------------------------

    const Entity entity_3;

    const Entity entity_4(1, 2, 3);

    const Entity entity_5(1, 2);

    //	Entity entity_6(); // warning

    //  --------------------------------

    entity_1.test();  // NOLINT
    Entity::test();
}
