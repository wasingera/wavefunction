#include "utility.h"
#include "colors.h"

std::string set_to_string(std::set<char>& s) {
    std::string r;
    for (auto e : s) {
        r += e;
        r += " ";
    }

    return r;
}

std::string vect_to_string(std::vector<char>& v) {
    std::string r;
    for (auto e : v) {
        r += e;
        r += " ";
    }

    return r;
}

void print_tuple(rule r) {
    std::cout << std::get<0>(r) << " " << std::get<1>(r) << " " << std::get<2>(r);
}

void print_character(char c) {
    switch (c) {
        case 'S':
            printf(CYN " %c" NC, c);
            break;
        case 'C':
            printf(YLW " %c" NC, c);
            break;
        case 'L':
            printf(GRN " %c" NC, c);
            break;
    }
}

int weighted_random_index(std::vector<double> weights) {
    std::vector<double> cumProb;
    double cumSum {0};
    /* std::cout << "IN RANDOM INDEX" << std::endl; */
    // generative cumulative probability distribution
    for (auto n : weights) {
        cumSum += n;
        cumProb.push_back(cumSum);
    }
    /* for (auto e: cumProb) std::cout << e << ' '; */
    /* std::cout << std::endl; */
    /* std::cout << "LENGTH: " << weights.size() << std::endl; */
    /* std::cout << "cumSum: " << cumSum << std::endl; */

    // generate random fraction
    double p = rand() / (double) RAND_MAX;

    for (int i = 0; i < weights.size(); i++) {
        // compare p against cumulative probability to get good distribution of indices
        /* std::cout << "P : " << p << std::endl; */
        /* std::cout << "I : " << i << std::endl; */
        /* std::cout << "CP: " << cumProb[i] << std::endl; */
        if (p < cumProb[i]) {
            /* std::cout << "RETURNING: " << i << std::endl; */
            return i;
        }
    }
    return weights.size() - 1;
}
