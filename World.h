//
// Created by myrovh on 5/26/15.
//

#ifndef FIT3094_AI_ASSIGNMENT2_WORLD_H
#define FIT3094_AI_ASSIGNMENT2_WORLD_H

#include <vector>
#include "Flower.h"

class World {
public:
    World(int world_size);

    std::vector<Flower *> flower_container;

    std::pair<int, int> get_flower_location(int flower_position);

    void selection_check(std::string input_string);

private:
    const static int range_min;
    const static int range_max;
    int number_of_flowers;
    int grid_spacing_x;
    int grid_spacing_y;
    int world_size;
    Flower *parent_1;
    Flower *parent_2;

    void deselect_all_parents();
};

#endif //FIT3094_AI_ASSIGNMENT2_WORLD_H
