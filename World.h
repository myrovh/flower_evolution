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

private:
    const static int range_min;
    const static int range_max;
    int number_of_flowers;


};

#endif //FIT3094_AI_ASSIGNMENT2_WORLD_H
