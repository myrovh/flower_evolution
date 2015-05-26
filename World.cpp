//
// Created by myrovh on 5/26/15.
//

#include "World.h"

extern int gWinRows;
extern int gWinCols;

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

    this->world_size = world_size;
    grid_spacing_x = 30;
    grid_spacing_y = 30;
}

std::pair<int, int> World::get_flower_location(int flower_position) {
    int top_most_location = 80;
    int left_most_location = -80;
    int count = 0;
    for (int y = 0; y < world_size; y++) {
        for (int x = 0; x < world_size; x++) {
            if (count >= flower_position) {
                return std::pair<int, int>(left_most_location + (x * grid_spacing_x),
                                           top_most_location - (y * grid_spacing_y));
            }
            count++;
        }
    }
}
