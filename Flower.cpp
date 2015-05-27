//
// Created by myrovh on 5/20/15.
//

#include <iostream>
#include "Flower.h"


const double Flower::range_min = 0.0;
const double Flower::range_max = 1.0;
const int Flower::crossover_frequency = 2;
const double Flower::mutation_chance = 0.15;
const unsigned long Flower::fixed_seed = 42;
const double Flower::selection_box_size = 20.0;

Flower::Flower() {
    flower_genes[petal_radius] = generate_value();
    flower_genes[red] = generate_colour_value();
    flower_genes[green] = generate_colour_value();
    flower_genes[blue] = generate_colour_value();
    flower_genes[number_of_edges] = generate_value();
    flower_genes[ring_diameter] = generate_value();
    flower_genes[number_of_petals] = generate_value();
    is_selected = false;
}

double Flower::generate_value() {
    //To get same values every time replace random() with fixed_seed
    static std::random_device random;
    static std::default_random_engine engine{(unsigned long) random()};
    static std::uniform_int_distribution<int> int_distribution{(int) (2),
                                                               (int) (10)};
    double value = ((double) int_distribution(engine));
    return value;
}

double Flower::generate_colour_value() {
    static std::random_device random;
    static std::default_random_engine engine{(unsigned long) random()};
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

void Flower::draw_petal_ring() {
    glPushMatrix();
    for (int i = 0; i < number_of_petals; i++) {
        glPushMatrix();
        glTranslated(ring_diameter * cos(i * 2.0 * M_PI / number_of_petals),
                     ring_diameter * sin(i * 2.0 * M_PI / number_of_petals), 0);

        glRotated((double) i * 360 / (double) number_of_petals, 0.0, 0.0, 1.0);

        draw_petal();

        glPopMatrix();
    }

    if (is_selected) {
        glColor3d(1.0, 0.0, 0.0);

        glBegin(GL_LINE_LOOP);
        glVertex2f((GLfloat) -selection_box_size, (GLfloat) selection_box_size);
        glVertex2f((GLfloat) selection_box_size, (GLfloat) selection_box_size);
        glVertex2f((GLfloat) selection_box_size, (GLfloat) -selection_box_size);
        glVertex2f((GLfloat) -selection_box_size, (GLfloat) -selection_box_size);
        glEnd();
    }
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

Flower Flower::mutate() {
    Flower new_flower = *this;
    for (auto p : flower_genes) {
        if (mutation_chance > generate_colour_value()) {
            std::cout << "mutation occured at " << p.first << "\n";
            if (p.first == petal_radius || p.first == number_of_edges || p.first == ring_diameter ||
                p.first == number_of_petals) {
                new_flower.flower_genes.at(p.first) = generate_value();
            }
            else {
                new_flower.flower_genes.at(p.first) = generate_colour_value();
            }
        }
    }
    return new_flower;
}

Flower::Flower(double petal, double red_number, double green_number, double blue_number,
               double number_of_edges_number, double ring, double petals_count) {
    flower_genes[petal_radius] = petal;
    flower_genes[red] = red_number;
    flower_genes[green] = green_number;
    flower_genes[blue] = blue_number;
    flower_genes[number_of_edges] = number_of_edges_number;
    flower_genes[ring_diameter] = ring;
    flower_genes[number_of_petals] = petals_count;
    is_selected = false;

}

