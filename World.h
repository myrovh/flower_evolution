/*
 * This software is the original work of Dyson Hamilton. ID: 23390662
 * This software is submitted in partial fulfilment of the
 * requirements for the degree of Information Technology.
 * Monash University
 */

#ifndef FIT3094_AI_ASSIGNMENT2_WORLD_H
#define FIT3094_AI_ASSIGNMENT2_WORLD_H

#include <vector>
#include "Flower.h"

class World {
public:
    int number_of_flowers;
    std::vector<Flower *> flower_container;
    Flower *parent_1;
    Flower *parent_2;

    World(int world_size);

    std::pair<int, int> get_flower_location(int flower_position);

    void selection_check(std::string input_string);

    void deselect_all_parents();

    Flower mate_flowers();

    static World *generate_new_world(World *pointer);

    static World *generate_new_world(World *pointer, Flower child);

private:
    const static int range_min;
    const static int range_max;
    int grid_spacing_x;
    int grid_spacing_y;
    int world_size;

};

#endif //FIT3094_AI_ASSIGNMENT2_WORLD_H
