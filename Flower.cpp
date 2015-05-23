//
// Created by myrovh on 5/20/15.
//

#include "Flower.h"


const double Flower::range_min = 0.0;
const double Flower::range_max = 1.0;
const int Flower::fixed_seed = 42;

Flower::Flower() {
    flower_genes[petal_radius] = generate_value();
    flower_genes[red] = generate_value();
    flower_genes[green] = generate_value();
    flower_genes[blue] = generate_value();
    flower_genes[number_of_edges] = generate_value();
}

double Flower::generate_value() {
    static std::default_random_engine engine{fixed_seed};
    static std::uniform_real_distribution<double> distribution{range_min, range_max};
    return distribution(engine);
}

std::string Flower::get_flower_stats() {
    std::ostringstream stream;
    std::string temp_string;
    for (auto iterator = flower_genes.begin(); iterator != flower_genes.end(); ++iterator) {
        stream << iterator->first << " => " << iterator->second << '\n';
    }

    temp_string = stream.str();
    return temp_string;
}