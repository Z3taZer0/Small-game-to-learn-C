#include "generator.h"
#include <math.h>

double money = 0;
double basic_generator_level = 1;
double multiply_generator_level = 1;
double basic_generator_price = 25;
double multiply_generator_price = 25;
double multiply_timer = 10.0;
double basic_timer = 1.0;
const double multiply_interval = 10.0;
const double basic_interval = 1.0;

double basic_generator(double income, double level, double interval, double *timer, double deltaTime) {
    double current_interval = interval / (1.0 + level * 0.1 - 0.1);
    *timer -= deltaTime;
    if (*timer <= 0) {
        money += basic_gen_up(income, level);
        *timer = current_interval;
    }
    return money;
}

double multiply_generator(double level, double base_income, double interval, double *timer, double deltaTime) {
    double current_interval = interval / (1.0 + level * 0.1 - 0.1);
    *timer -= deltaTime;
    if (*timer <= 0) {
        money += multiply_gen_up(level, base_income);
        *timer = current_interval;
    }
    return money;
}

double basic_gen_up(double income, double level) {
    return income * pow(level, 1.25);
}

double multiply_gen_up(double level, double base_income) {
    double increment = (money * (0.05 * level));
    double cap = base_income * (money * 10);
    
    if (increment > cap) {
        return cap;
    }
    return increment;
}
