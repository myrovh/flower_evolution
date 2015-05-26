//
// Created by myrovh on 5/26/15.
//

#include "World.h"

const int World::range_min = 2;
const int World::range_max = 12;

World::World(int world_size) {
    if (world_size > range_max) {
        number_of_flowers = range_max * range_max;
    }
    else if (world_size < range_min) {
        number_of_flowers = range_min * range_min;
    }
    else {
        number_of_flowers = world_size * world_size;
    }
    //number_of_flowers = world_size;

    for (int i = 0; i < number_of_flowers; i++) {
        flower_container.push_back(new Flower());
    }
}
