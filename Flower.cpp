//
// Created by myrovh on 5/20/15.
//

#include "Flower.h"


const double Flower::range_min = 0.0;
const double Flower::range_max = 1.0;
const unsigned long Flower::fixed_seed = 42;

Flower::Flower() {
    flower_genes[petal_radius] = generate_value(true);
    flower_genes[red] = generate_value(true);
    flower_genes[green] = generate_value(true);
    flower_genes[blue] = generate_value(true);
    flower_genes[number_of_edges] = generate_value(true);
}

double Flower::generate_value(bool clamp) {
    static std::default_random_engine engine{fixed_seed};
    if (clamp) {
        static std::uniform_int_distribution<int> int_distribution{1, 10};
        double value = ((double) int_distribution(engine)) / 10;
        return value;
    }
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