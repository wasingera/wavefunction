#ifndef UTILITY_H
#define UTILITY_H

#include <tuple>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "Rules.hpp"

std::string vect_to_string(std::vector<char>& v);
std::string set_to_string(std::set<char>& s);
void print_tuple(rule r);
void print_character(char c);

int weighted_random_index(std::vector<double> weights);

#endif
