#ifndef GENERATOR_H
#define GENERATOR_H

extern double money;
extern double basic_generator_level;
extern double multiply_generator_level;
extern double basic_generator_price;
extern double multiply_generator_price;
extern double multiply_timer;
extern double basic_timer;
extern const double multiply_interval;
extern const double basic_interval;

double basic_generator(double income, double level, double interval, double *timer, double deltaTime);
double multiply_generator(double level, double base_income, double interval, double *timer, double deltaTime);
double basic_gen_up(double income, double level);
double multiply_gen_up(double level, double base_income);

#endif