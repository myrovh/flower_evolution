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
    number_of_edges,
    ring_diameter,
    number_of_petals
};
typedef std::map<flower_gene, double> flower_genotype;

class Flower {
public:
    static const double range_min;
    static const double range_max;
    static const double mutation_chance;
    static const unsigned long fixed_seed;
    static const double selection_box_size;
    bool is_selected;
    flower_genotype flower_genes;

    Flower();

    Flower(double petal, double red, double green, double blue, double number_of_edges, double ring,
           double petals_count);

    double generate_value();

    double generate_colour_value();

    int generate_crossover(int length);

    Flower crossover(Flower other);

    Flower mutate();

    void draw_petal();

    void draw_petal_ring();
    std::string get_flower_stats();

private:

    double generate_large_values(double in) {
        double out = in * 10;
        return out > 1.0 ? out : 2.0;
    }
};

#endif //FIT3094_AI_ASSIGNMENT2_FLOWER_H
