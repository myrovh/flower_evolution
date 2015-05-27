/*
 * This software is the original work of Dyson Hamilton. ID: 23390662
 * This software is submitted in partial fulfilment of the
 * requirements for the degree of Information Technology.
 * Monash University
 */

#include <iostream>
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

    for (int i = 0; i < number_of_flowers; i++) {
        flower_container.push_back(new Flower());
    }

    this->world_size = world_size;
    grid_spacing_x = 50;
    grid_spacing_y = 50;

    parent_1 = nullptr;
    parent_2 = nullptr;
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
    return std::pair<int, int>(0, 0);
}

void World::selection_check(std::string input_string) {
    std::stringstream convert;
    convert << input_string;
    int selected_flower = -1;
    convert >> selected_flower;
    if (selected_flower >= 0 && selected_flower < flower_container.size()) {
        if (parent_1 != nullptr && parent_2 != nullptr) {
            deselect_all_parents();
        }
        else if (parent_1 == nullptr) {
            parent_1 = flower_container[selected_flower];
            parent_1->is_selected = true;
        }
        else if (parent_2 == nullptr) {
            parent_2 = flower_container[selected_flower];
            parent_2->is_selected = true;
        }
    }
}

void World::deselect_all_parents() {
    parent_1->is_selected = false;
    parent_2->is_selected = false;
    parent_1 = nullptr;
    parent_2 = nullptr;
}

Flower World::mate_flowers() {
    Flower new_flower;
    if (parent_1 != nullptr && parent_2 != nullptr) {
        new_flower = parent_1->crossover(*parent_2);
    }
    return new_flower;
}

World *World::generate_new_world(World *pointer, Flower child) {
    pointer->deselect_all_parents();
    pointer->flower_container.clear();
    for (int count = 0; count < pointer->number_of_flowers; count++) {
        Flower insert_flower = child.mutate();
        pointer->flower_container.push_back(
                new Flower(insert_flower.flower_genes[petal_radius], insert_flower.flower_genes[red],
                           insert_flower.flower_genes[green], insert_flower.flower_genes[blue],
                           insert_flower.flower_genes[number_of_edges], insert_flower.flower_genes[ring_diameter],
                           insert_flower.flower_genes[number_of_petals]));
        std::cout << "\nChild Flower: \n" << pointer->flower_container.at(count)->get_flower_stats();
    }
    return pointer;
}

World *World::generate_new_world(World *pointer) {
    int size = pointer->world_size;
    delete pointer;
    pointer = new World(size);
    return pointer;
}
