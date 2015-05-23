//
// Created by myrovh on 5/20/15.
//

#ifndef FIT3094_AI_ASSIGNMENT2_FLOWER_H
#define FIT3094_AI_ASSIGNMENT2_FLOWER_H

#include <string>
#include <map>
#include <sstream>
#include <random>

enum flower_gene {
    petal_radius,
    red,
    green,
    blue,
    number_of_edges
};
typedef std::map<flower_gene, double> flower_genotype;

class Flower {
public:
    Flower();
    double generate_value();
    std::string get_flower_stats();

private:
    static const double range_min;
    static const double range_max;
    static const int fixed_seed;
    flower_genotype flower_genes;
};

#endif //FIT3094_AI_ASSIGNMENT2_FLOWER_H
