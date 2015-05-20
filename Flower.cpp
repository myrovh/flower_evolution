//
// Created by myrovh on 5/20/15.
//

#include "Flower.h"


const double Flower::range_min = 0.0;
const double Flower::range_max = 1.0;

Flower::Flower() {
    flower_genes[petal_radius] = generate_value();
    flower_genes[red] = generate_value();
    flower_genes[green] = generate_value();
    flower_genes[blue] = generate_value();
    flower_genes[number_of_edges] = generate_value();
}

double Flower::generate_value() { return range_max; }

std::string Flower::get_flower_stats() {
    std::ostringstream stream;
    std::string temp_string;
    for (flower_genotype::iterator it = flower_genes.begin(); it != flower_genes.end(); ++it) {
        stream << it->first << " => " << it->second << '\n';
    }

    temp_string = stream.str();
    return temp_string;
}