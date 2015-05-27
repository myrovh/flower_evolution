//
// Created by myrovh on 5/20/15.
//

#include "Flower.h"


const double Flower::range_min = 0.0;
const double Flower::range_max = 1.0;
const int Flower::crossover_frequency = 2;
const double Flower::mutation_chance = 0.15;
const unsigned long Flower::fixed_seed = 42;

Flower::Flower() {
    flower_genes[petal_radius] = generate_large_values(generate_value(true));
    flower_genes[red] = generate_value(false);
    flower_genes[green] = generate_value(false);
    flower_genes[blue] = generate_value(false);
    flower_genes[number_of_edges] = generate_large_values(generate_value(true));
    is_selected = false;
}

double Flower::generate_value(bool clamp) {
    //To get same values every time replace random() with fixed_seed
    static std::random_device random;
    static std::default_random_engine engine{(unsigned long) random()};
    if (clamp) {
        static std::uniform_int_distribution<int> int_distribution{(int) (Flower::range_min * 10),
                                                                   (int) (Flower::range_max * 10)};
        double value = ((double) int_distribution(engine)) / 10;
        return value;
    }
    static std::uniform_real_distribution<double> distribution{Flower::range_min, Flower::range_max};
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

void Flower::draw_petal() {
    double center_x = 0;
    double center_y = 0;
    double current_point_x;
    double current_point_y;
    double angle_radians = 0;
    double step_size = (2 * M_PI) / flower_genes[number_of_edges];

    //Set colour
    glColor3d(flower_genes[red], flower_genes[green], flower_genes[blue]);

    glBegin(GL_LINE_LOOP);

    //Traverse around a circle in the specified number of steps
    for (angle_radians = 0; angle_radians < (2 * M_PI); angle_radians += step_size) {
        current_point_x = center_x + (flower_genes[petal_radius] * cos(angle_radians));
        current_point_y = center_y + (flower_genes[petal_radius] * sin(angle_radians));
        glVertex2f((GLfloat) current_point_x, (GLfloat) current_point_y);
    }

    glEnd();

    if (is_selected) {
        glColor3d(1.0, 0.0, 0.0);

        glBegin(GL_LINE_LOOP);
        glVertex2f((GLfloat) -10.0, (GLfloat) 10.0);
        glVertex2f((GLfloat) 10.0, (GLfloat) 10.0);
        glVertex2f((GLfloat) 10.0, (GLfloat) -10.0);
        glVertex2f((GLfloat) -10.0, (GLfloat) -10.0);
        glEnd();
    }
}

Flower Flower::crossover(Flower other) {
    Flower *current = this;
    Flower *next = &other;
    Flower new_flower;

    //TODO add checks for invalid values
    for (int count = 0; count < flower_genes.size(); count++) {
        // Swap pointers
        if (!count % crossover_frequency == 0) {
            Flower *temp = current;
            current = next;
            next = temp;
        }

        //Insert parent value into child
        new_flower.flower_genes.at((flower_gene) count) = current->flower_genes.at((flower_gene) count);
    }
    return new_flower;
}
