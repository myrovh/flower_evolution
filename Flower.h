//
// Created by myrovh on 5/20/15.
//

#ifndef FIT3094_AI_ASSIGNMENT2_FLOWER_H
#define FIT3094_AI_ASSIGNMENT2_FLOWER_H

#include <string>
#include <map>
#include <sstream>
#include <random>
#include <GL/gl.h>
#include <math.h>

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
    static const double range_min;
    static const double range_max;
    static const unsigned long fixed_seed;

    Flower();

    double generate_value(bool clamp);

    void draw_petal();
    std::string get_flower_stats();

private:
    flower_genotype flower_genes;
};

#endif //FIT3094_AI_ASSIGNMENT2_FLOWER_H
