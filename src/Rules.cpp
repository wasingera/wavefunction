#include "Rules.hpp"
#include "utility.h"

Rules::Rules(char src[SRC_Y][SRC_X]) : rules{generate_rules(src)}, weights{generate_weights(src)} {}

weightsMap Rules::generate_weights(char src[SRC_Y][SRC_X]) {
    weightsMap weights;

    // Get total count of each tile
    for (int i = 0; i < SRC_Y; i++) {
        for (int j = 0; j < SRC_X; j++) {
            char curr = src[i][j];
            weights[curr] += 1;
        }
    }

    // Get proportion of each tile in source image
    int total {SRC_Y * SRC_X};
    for (auto& w : weights) {
        w.second = w.second / total;
    }

    return weights;
}

rulesMap Rules::generate_rules(char src[SRC_Y][SRC_X]) {
    rulesMap rules;

    for (int i = 0; i < SRC_Y; i++) {
        for (int j = 0; j < SRC_X; j++) {
            char curr = src[i][j];

            // Check left
            if (j > 0) {
                char left = src[i][j - 1];
                rules[curr]["LEFT"].insert(left);
                /* rule t {curr, left, "LEFT"}; */
                /* rules[curr].push_back(t); */
            }
            // Check right
            if (j < SRC_X - 1) {
                char right = src[i][j + 1];
                rules[curr]["RIGHT"].insert(right);
                /* rule t {curr, right, "RIGHT"}; */
                /* rules[curr].push_back(t); */
            }
            // Check up
            if (i > 0) {
                char up = src[i - 1][j];
                rules[curr]["UP"].insert(up);
                /* rule t {curr, up, "UP"}; */
                /* rules[curr].push_back(t); */
            }
            // Check down
            if (i < SRC_Y - 1) {
                char down = src[i + 1][j];
                rules[curr]["DOWN"].insert(down);
                /* rule t {curr, down, "DOWN"}; */
                /* rules[curr].push_back(t); */
            }
        }
    }

    // Remove duplicate rules
    /* for (auto& r : rules) { */
    /*     std::sort(r.second.begin(), r.second.end()); */
    /*     auto last = std::unique(r.second.begin(), r.second.end()); */
    /*     r.second.erase(last, r.second.end()); */
    /* } */

    return rules;
}

void Rules::print_rules() {
    for (auto r : rules) {
        print_character(r.first); std::cout << ":\n";

        for (auto e : r.second) {
            for (auto d : e.second) {
                std::cout << "    " << r.first << ' ' << d << ' ' << e.first << '\n';
            }
            /* std::cout << "    " << e.second << '\n'; */
        }

        std::cout << std::endl;
    }
    /* for (auto r : rules) { */
    /*     print_character(r.first); std::cout << ':' << std::endl; */

    /*     for (auto e : r.second) { */
    /*         std::cout << "    "; */
    /*         print_tuple(e); */
    /*         std::cout << std::endl; */
    /*     } */

    /*     std::cout << std::endl; */
    /* } */
}

void Rules::print_weights() {
    for (auto r : weights) {
        print_character(r.first); std::cout << ": " << r.second << std::endl;
    }
}
