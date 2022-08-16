#ifndef UTILITY_H
#define UTILITY_H

#include <tuple>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Rules.hpp"

void print_tuple(rule r);
void print_character(char c);

int weighted_random_index(std::vector<double> weights);

#endif
